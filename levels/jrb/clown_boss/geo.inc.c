#include "src/game/envfx_snow.h"

const GeoLayout clown_boss_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, NULL),
		GEO_OPEN_NODE(),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 100, 0, clown_boss_Torso_mesh_layer_1),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, clown_boss_Chest_skinned_mesh_layer_1),
				GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 68, 0, clown_boss_Chest_mesh_layer_1),
				GEO_OPEN_NODE(),
					GEO_ASM(0, geo_clown_head_scaler),
					GEO_SCALE_BETTER(LAYER_OPAQUE, 65536, 65536, 65536),
					GEO_OPEN_NODE(),
						GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 114, 0, clown_boss_Head_geo_mesh_layer_1),
						GEO_OPEN_NODE(),
							GEO_ASM(0, geo_clown_awooga_eyes_scaler),
							GEO_SCALE_BETTER(LAYER_OPAQUE, 65536, 65536, 65536),
							GEO_OPEN_NODE(),
								GEO_ANIMATED_PART(LAYER_OPAQUE, -35, 83, 54, clown_boss_bigeyeleft_geo_mesh_layer_1),
							GEO_CLOSE_NODE(),
							GEO_ASM(0, geo_clown_awooga_eyes_scaler),
							GEO_SCALE_BETTER(LAYER_OPAQUE, 65536, 65536, 65536),
							GEO_OPEN_NODE(),
								GEO_ANIMATED_PART(LAYER_OPAQUE, 36, 83, 54, clown_boss_bigeyeright_geo_mesh_layer_1),
							GEO_CLOSE_NODE(),
							GEO_ASM(0, geo_clown_awooga_mouth_scaler),
							GEO_SCALE_BETTER(LAYER_OPAQUE, 65536, 65536, 65536),
							GEO_OPEN_NODE(),
								GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 69, 47, clown_boss_bigmouth_geo_mesh_layer_1),
							GEO_CLOSE_NODE(),
							GEO_ASM(0, geo_clown_eyes_scaler),
							GEO_SCALE_BETTER(LAYER_OPAQUE, 65536, 65536, 65536),
							GEO_OPEN_NODE(),
								GEO_ANIMATED_PART(LAYER_OPAQUE, -35, 83, 79, clown_boss_eyeleft_geo_mesh_layer_1),
							GEO_CLOSE_NODE(),
							GEO_ASM(0, geo_clown_eyes_scaler),
							GEO_SCALE_BETTER(LAYER_OPAQUE, 65536, 65536, 65536),
							GEO_OPEN_NODE(),
								GEO_ANIMATED_PART(LAYER_OPAQUE, 36, 83, 79, clown_boss_eyeright_geo_mesh_layer_1),
							GEO_CLOSE_NODE(),
						GEO_CLOSE_NODE(),
					GEO_CLOSE_NODE(),
					GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, -65, 111, 1, 0, 0, 106),
					GEO_OPEN_NODE(),
						GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, clown_boss_leftshoulder_mesh_layer_1),
						GEO_OPEN_NODE(),
							GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 0, 109, 0, 0, 3, 16),
							GEO_OPEN_NODE(),
								GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, clown_boss_leftwrist_mesh_layer_1),
								GEO_OPEN_NODE(),
									GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 0, 82, 0, -7, -33, 10),
									GEO_OPEN_NODE(),
										GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, clown_boss_lefthand_mesh_layer_1),
										GEO_OPEN_NODE(),
											GEO_DISPLAY_LIST(LAYER_OPAQUE, clown_boss_leftfinger_skinned_mesh_layer_1),
											GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 0, 56, 0, 8, 24, -7),
											GEO_OPEN_NODE(),
												GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, clown_boss_leftfinger_mesh_layer_1),
												GEO_OPEN_NODE(),
													GEO_DISPLAY_LIST(LAYER_OPAQUE, clown_boss_leftfingertip_skinned_mesh_layer_1),
													GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 0, 38, 0, -1, -3, 0),
													GEO_OPEN_NODE(),
														GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, clown_boss_leftfingertip_mesh_layer_1),
													GEO_CLOSE_NODE(),
												GEO_CLOSE_NODE(),
											GEO_CLOSE_NODE(),
											GEO_DISPLAY_LIST(LAYER_OPAQUE, clown_boss_leftthumb_skinned_mesh_layer_1),
											GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 14, 23, 28, 9, 27, -3),
											GEO_OPEN_NODE(),
												GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, clown_boss_leftthumb_mesh_layer_1),
												GEO_OPEN_NODE(),
													GEO_DISPLAY_LIST(LAYER_OPAQUE, clown_boss_leftthumbtip_skinned_mesh_layer_1),
													GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 0, 27, 0, 1, 4, 4),
													GEO_OPEN_NODE(),
														GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, clown_boss_leftthumbtip_mesh_layer_1),
													GEO_CLOSE_NODE(),
												GEO_CLOSE_NODE(),
											GEO_CLOSE_NODE(),
										GEO_CLOSE_NODE(),
									GEO_CLOSE_NODE(),
								GEO_CLOSE_NODE(),
							GEO_CLOSE_NODE(),
						GEO_CLOSE_NODE(),
					GEO_CLOSE_NODE(),
					GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 64, 111, 1, 0, 0, -106),
					GEO_OPEN_NODE(),
						GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, clown_boss_rightshoulder_mesh_layer_1),
						GEO_OPEN_NODE(),
							GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 0, 109, 0, 1, 0, -16),
							GEO_OPEN_NODE(),
								GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, clown_boss_rightwrist_mesh_layer_1),
								GEO_OPEN_NODE(),
									GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 0, 82, 0, -11, -2, -5),
									GEO_OPEN_NODE(),
										GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, clown_boss_righthand_mesh_layer_1),
										GEO_OPEN_NODE(),
											GEO_DISPLAY_LIST(LAYER_OPAQUE, clown_boss_rightfinger_skinned_mesh_layer_1),
											GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 0, 56, 0, 9, 0, 6),
											GEO_OPEN_NODE(),
												GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, clown_boss_rightfinger_mesh_layer_1),
												GEO_OPEN_NODE(),
													GEO_DISPLAY_LIST(LAYER_OPAQUE, clown_boss_rightfingertip_skinned_mesh_layer_1),
													GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 0, 38, 0, -1, 0, 0),
													GEO_OPEN_NODE(),
														GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, clown_boss_rightfingertip_mesh_layer_1),
													GEO_CLOSE_NODE(),
												GEO_CLOSE_NODE(),
											GEO_CLOSE_NODE(),
											GEO_DISPLAY_LIST(LAYER_OPAQUE, clown_boss_rightthumb_skinned_mesh_layer_1),
											GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 3, 23, 31, 10, 3, 2),
											GEO_OPEN_NODE(),
												GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, clown_boss_rightthumb_mesh_layer_1),
												GEO_OPEN_NODE(),
													GEO_DISPLAY_LIST(LAYER_OPAQUE, clown_boss_rightthumbtip_skinned_mesh_layer_1),
													GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 0, 27, 0, 2, 0, -4),
													GEO_OPEN_NODE(),
														GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, clown_boss_rightthumbtip_mesh_layer_1),
													GEO_CLOSE_NODE(),
												GEO_CLOSE_NODE(),
											GEO_CLOSE_NODE(),
										GEO_CLOSE_NODE(),
									GEO_CLOSE_NODE(),
								GEO_CLOSE_NODE(),
							GEO_CLOSE_NODE(),
						GEO_CLOSE_NODE(),
					GEO_CLOSE_NODE(),
				GEO_CLOSE_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, clown_boss_leftfoot_skinned_mesh_layer_1),
				GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, -43, -10, 0, 0, 0, 115),
				GEO_OPEN_NODE(),
					GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, clown_boss_leftfoot_mesh_layer_1),
				GEO_CLOSE_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, clown_boss_rightfoot_skinned_mesh_layer_1),
				GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 45, -10, 0, 0, 0, -115),
				GEO_OPEN_NODE(),
					GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, clown_boss_rightfoot_mesh_layer_1),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, clown_boss_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};