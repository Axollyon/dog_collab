void bhv_lighthouse_broken_glass_loop(void) {
    load_object_collision_model();

    if (cur_obj_dist_to_nearest_object_with_behavior(bhvExplosion) <= 350.f) {
        play_puzzle_jingle();
        obj_explode_and_spawn_coins(80.0f, COIN_TYPE_NONE);
    }
}


static struct ObjectHitbox sLighthouseBulb = {
    /* interactType:      */ INTERACT_IGLOO_BARRIER,
    /* downOffset:        */ 550,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 200,
    /* height:            */ 550,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

void bhv_lighthouse_bulb_init(void) {
    obj_set_hitbox(o, &sLighthouseBulb);
}

void bhv_lighthouse_bulb_loop(void) {
    o->oIntangibleTimer = 0;
}

void bhv_lighthouse_chain_loop(void) {
    bhv_pole_base_loop();
    o->oFaceAngleYaw = atan2s(gLakituState.pos[2] - o->oPosZ, gLakituState.pos[0] - o->oPosX);
}