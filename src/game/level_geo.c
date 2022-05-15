#include <ultra64.h>

#include "sm64.h"
#include "rendering_graph_node.h"
#include "mario_misc.h"
#include "skybox.h"
#include "engine/math_util.h"
#include "camera.h"
#include "envfx_snow.h"
#include "level_geo.h"
#include "game_init.h"
#include "level_update.h"

/**
 * Geo function that generates a displaylist for environment effects such as
 * snow or jet stream bubbles.
 */
Gfx *geo_envfx_main(s32 callContext, struct GraphNode *node, Mat4 mtxf) {
    Vec3s marioPos;
    Vec3s camFrom;
    Vec3s camTo;
    void *particleList;
    Gfx *gfx = NULL;

    if (callContext == GEO_CONTEXT_RENDER && gCurGraphNodeCamera != NULL) {
        struct GraphNodeGenerated *execNode = (struct GraphNodeGenerated *) node;
        u32 *params = &execNode->parameter; // accessed a s32 as 2 u16s by pointing to the variable and
                                            // casting to a local struct as necessary.

        if (GET_HIGH_U16_OF_32(*params) != gAreaUpdateCounter) {
            s32 snowMode = GET_LOW_U16_OF_32(*params);

            vec3f_to_vec3s(camTo, gCurGraphNodeCamera->focus);
            vec3f_to_vec3s(camFrom, gCurGraphNodeCamera->pos);
            vec3f_to_vec3s(marioPos, gPlayerCameraState->pos);
            particleList = envfx_update_particles(snowMode, marioPos, camTo, camFrom);
            if (particleList != NULL) {
                Mtx *mtx = alloc_display_list(sizeof(*mtx));

                gfx = alloc_display_list(2 * sizeof(*gfx));
                mtxf_to_mtx(mtx, mtxf);
                gSPMatrix(&gfx[0], VIRTUAL_TO_PHYSICAL(mtx), G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
                gSPBranchList(&gfx[1], VIRTUAL_TO_PHYSICAL(particleList));
                SET_GRAPH_NODE_LAYER(execNode->fnNode.node.flags, LAYER_OCCLUDE_SILHOUETTE_ALPHA);
            }
            SET_HIGH_U16_OF_32(*params, gAreaUpdateCounter);
        }
    } else if (callContext == GEO_CONTEXT_AREA_INIT) {
        // Give these arguments some dummy values. Not used in ENVFX_MODE_NONE
        vec3s_copy(camTo, gVec3sZero);
        vec3s_copy(camFrom, gVec3sZero);
        vec3s_copy(marioPos, gVec3sZero);
        envfx_update_particles(ENVFX_MODE_NONE, marioPos, camTo, camFrom);
    }

    return gfx;
}

/**
 * Geo function that generates a displaylist for the skybox. Can be assigned
 * as the function of a GraphNodeBackground.
 */
Gfx *geo_skybox_main(s32 callContext, struct GraphNode *node, UNUSED Mat4 *mtx) {
    Gfx *gfx = NULL;
    struct GraphNodeBackground *backgroundNode = (struct GraphNodeBackground *) node;

    if (callContext == GEO_CONTEXT_AREA_LOAD) {
        backgroundNode->unused = 0;
#ifndef L3DEX2_ALONE
    } else if (callContext == GEO_CONTEXT_RENDER) {
        struct GraphNodeCamera *camNode = (struct GraphNodeCamera *) gCurGraphNodeRoot->views[0];
        struct GraphNodePerspective *camFrustum =
            (struct GraphNodePerspective *) camNode->fnNode.node.parent;
        gfx = create_skybox_facing_camera(0, backgroundNode->background, camFrustum->fov, gLakituState.pos, gLakituState.focus);
#endif
    }

    return gfx;
}

Gfx *geo_zbuffer_clear(s32 callContext, UNUSED struct GraphNode *node, UNUSED Mat4 *mtx) {
    Gfx *dl = NULL;
    if (callContext == GEO_CONTEXT_RENDER) {
        Gfx *dlHead = NULL;
        dl = alloc_display_list(13 * sizeof(*dl));
        dlHead = dl;
        gDPPipeSync(dlHead++);
        gDPSetRenderMode(dlHead++, G_RM_NOOP, G_RM_NOOP2);
        gDPSetCycleType(dlHead++, G_CYC_FILL);
        gDPSetDepthSource(dlHead++, G_ZS_PIXEL);
        gDPSetDepthImage(dlHead++, gPhysicalZBuffer);
        gDPSetColorImage(dlHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, gPhysicalZBuffer);
        gDPSetFillColor(dlHead++,
                        GPACK_ZDZ(G_MAXFBZ, 0) << 16 | GPACK_ZDZ(G_MAXFBZ, 0));
        gDPFillRectangle(dlHead++, 0, gBorderHeight, SCREEN_WIDTH - 1,
                        SCREEN_HEIGHT - 1 - gBorderHeight);
        gDPPipeSync(dlHead++);
        gDPSetCycleType(dlHead++, G_CYC_1CYCLE);
        gDPSetColorImage(dlHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH,
                        gPhysicalFramebuffers[sRenderingFramebuffer]);
        gDPSetScissor(dlHead++, G_SC_NON_INTERLACE, 0, gBorderHeight, SCREEN_WIDTH,
                  SCREEN_HEIGHT - gBorderHeight);
        gSPEndDisplayList(dlHead++);
    }
    return dl;
}

Gfx *geo_backdrop_move(s32 callContext, struct GraphNode *node, UNUSED Mat4 *mtx) {
    if (callContext == GEO_CONTEXT_RENDER) {
        f32 scale = .95;
        ((struct GraphNodeTranslation *) node->next)->translation[0] = gLakituState.pos[0] * scale;
        ((struct GraphNodeTranslation *) node->next)->translation[1] = gLakituState.pos[1] * scale;
        ((struct GraphNodeTranslation *) node->next)->translation[2] = gLakituState.pos[2] * scale;
    }
    return 0;
}

Gfx *geo_clouds_move(s32 callContext, struct GraphNode *node, UNUSED Mat4 *mtx) {
    if (callContext == GEO_CONTEXT_RENDER) {
        ((struct GraphNodeTranslation *) node->next)->translation[0] = gLakituState.pos[0];
        ((struct GraphNodeTranslation *) node->next)->translation[1] = gLakituState.pos[1];
        ((struct GraphNodeTranslation *) node->next)->translation[2] = gLakituState.pos[2];
    }
    return 0;
}

extern Vtx sl_backdrop_water_Backdrop_Water_mesh_vtx_0[263];
extern Vtx sl_backdrop_Backdrop_mesh_vtx_0[264];
extern ALIGNED16 Mat4 gMatStack[32];

#define NEAR_CLIP 218.f
#define FAR_CLIP 65535.f

Gfx *geo_sl_backdrop_fog(s32 callContext, struct GraphNode *node, UNUSED Mat4 *mtx) {
    int i;
    Vtx *waterVerts = segmented_to_virtual(sl_backdrop_water_Backdrop_Water_mesh_vtx_0);
    Vtx *rockVerts = segmented_to_virtual(sl_backdrop_Backdrop_mesh_vtx_0);
    if (callContext == GEO_CONTEXT_CREATE) {
        for (i = 0; i < 264; i++) {
            if (i < 263 && sqr(waterVerts[i].v.ob[0]) + sqr(waterVerts[i].v.ob[2]) <= sqr(2500)) {
                waterVerts[i].v.flag = 1;
            }
            if (sqr(rockVerts[i].v.ob[0]) + sqr(rockVerts[i].v.ob[2]) <= sqr(2500)) {
                rockVerts[i].v.flag = 1;
            }
        }
    }
    else if (callContext == GEO_CONTEXT_RENDER) {
        f32 view0 = gMatStack[1][0][2] * 20;
        f32 view1 = gMatStack[1][1][2] * 20;
        f32 view2 = gMatStack[1][2][2] * 20;
        f32 view3 = gMatStack[1][3][2];

        for (i = 0; i < 264; i++) {
            if (i < 263 && waterVerts[i].v.flag == 1) {
                f32 depth;
                int fog;
                f32 oz = waterVerts[i].v.ob[0] * view0 + waterVerts[i].v.ob[1] * view1 + waterVerts[i].v.ob[2] * view2 + view3;
                if (oz < 0) {
                    depth = ((2 * NEAR_CLIP * FAR_CLIP) / (NEAR_CLIP - FAR_CLIP) / -oz) - (NEAR_CLIP + FAR_CLIP) / (NEAR_CLIP - FAR_CLIP);
                    fog = (depth - 0.94f) * (0xFF / 0.06f);
                    if (fog < 0x00) fog = 0x00;
                    if (fog > 0xFF) fog = 0xFF;
                    waterVerts[i].v.cn[3] = fog;
                }
                else {
                    waterVerts[i].v.cn[3] = 0;
                }
            }
            if (rockVerts[i].v.flag == 1) {
                f32 depth;
                int fog;
                f32 oz = rockVerts[i].v.ob[0] * view0 + rockVerts[i].v.ob[1] * view1 + rockVerts[i].v.ob[2] * view2 + view3;
                if (oz < 0) {
                    depth = ((2 * NEAR_CLIP * FAR_CLIP) / (NEAR_CLIP - FAR_CLIP) / -oz) - (NEAR_CLIP + FAR_CLIP) / (NEAR_CLIP - FAR_CLIP);
                    fog = (depth - 0.94f) * (0xFF / 0.06f);
                    if (fog < 0x00) fog = 0x00;
                    if (fog > 0xFF) fog = 0xFF;
                    rockVerts[i].v.cn[3] = fog;
                }
                else {
                    rockVerts[i].v.cn[3] = 0;
                }
            }
        }
    }
    return 0;
}

#undef NEAR_CLIP
#undef FAR_CLIP
