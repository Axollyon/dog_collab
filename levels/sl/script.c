#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "dialog_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"

#include "game/level_update.h"

#include "levels/scripts.h"

#include "actors/common1.h"

/* Fast64 begin persistent block [includes] */
/* Fast64 end persistent block [includes] */

#include "make_const_nonconst.h"
#include "levels/sl/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_sl_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _sl_segment_7SegmentRomStart, _sl_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _snow_yay0SegmentRomStart, _snow_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0B, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group7_yay0SegmentRomStart, _group7_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group7_geoSegmentRomStart, _group7_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group13_yay0SegmentRomStart, _group13_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group13_geoSegmentRomStart, _group13_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_8), 
	JUMP_LINK(script_func_global_14), 
	LOAD_MODEL_FROM_GEO(MODEL_LIGHTHOUSE_BROKEN_GLASS, lighthouse_broken_glass_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LIGHTHOUSE_BULB, lighthouse_bulb_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LIGHTHOUSE_CHAIN, lighthouse_chain_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LIGHTHOUSE_CHAIN_INSIDE, lighthouse_chain_inside_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, sl_area_1),
		WARP_NODE(0x0A, LEVEL_SL, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_SL, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_SL, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x00, LEVEL_SL, 0x01, 0x01, WARP_NO_CHECKPOINT),
		WARP_NODE(0x01, LEVEL_BOB, 0x01, 0x00, WARP_NO_CHECKPOINT),
		WARP_NODE(0x02, LEVEL_SL, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_SHELL_BUBBLE, 16822, -828, -9766, 0, 0, 0, 0x00000000, bhvBubbleShell),
		OBJECT(MODEL_CEPHIE, 200, -2500, 3000, 0, -90, 0, 0x00000000, bhvCephie),
		OBJECT(MODEL_LIGHTHOUSE_BROKEN_GLASS, 21045, -7000, -12096, 0, 0, 0, 0x00000000, bhvLighthouseBrokenGlass),
		OBJECT(MODEL_LIGHTHOUSE_BULB, 20437, -6250, -12262, 0, 0, 0, 0x00000000, bhvLighthouseBulb),
		OBJECT(MODEL_LIGHTHOUSE_CHAIN, 20437, -6550, -12578, 0, 0, 0, 0x00000000, bhvLighthouseChain),
		OBJECT(MODEL_NONE, 20438, -7000, -13096, 0, 0, 0, (0 << 16), bhvFadingWarp),
		OBJECT(MODEL_YELLOW_COIN, 20438, -7000, -13096, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 20646, -7000, -13040, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 20229, -7000, -13040, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_NONE, 20437, -947, -9230, 0, 0, 0, (1 << 16), bhvFadingWarp),
		OBJECT(MODEL_NONE, 0, -2500, 3500, 0, -180, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, -180, 0, -2500, 3500),
		OBJECT(MODEL_NONE, 20437, -6170, -12578, 0, -180, 0, (2 << 16), bhvWarp),
		OBJECT(MODEL_CEPHIE, 1500, -2450, 2000, 0, 0, 0, 0x00020000, bhvCephie),
		OBJECT(MODEL_CEPHIE, 1500, -2450, 2400, 0, -180, 0, 0x00010000, bhvCephie),
		OBJECT(MODEL_CEPHIE, 1285, -2450, 2977, 0, -112, 0, 0x00030000, bhvCephie),
		TERRAIN(sl_area_1_collision),
		ROOMS(sl_area_1_collision_rooms),
		MACRO_OBJECTS(sl_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_WATER),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, sl_area_2),
		WARP_NODE(0x0A, LEVEL_SL, 0x01, 0x02, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_SL, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_SL, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_LIGHTHOUSE_CHAIN_INSIDE, 20438, -6250, -12578, 0, 0, 0, (1 << 16), bhvLighthouseChain),
		OBJECT(MODEL_NONE, 20438, -6250, -12578, 0, 0, 0, (0xA << 16), bhvWarp),
		TERRAIN(sl_area_2_collision),
		MACRO_OBJECTS(sl_area_2_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, -180, 0, -2500, 3500),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
