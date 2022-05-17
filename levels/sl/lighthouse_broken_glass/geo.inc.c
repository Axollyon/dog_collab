#include "src/game/envfx_snow.h"

const GeoLayout lighthouse_broken_glass_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lighthouse_broken_glass_Lighthouse_Broken_Glass_Inside_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE_DECAL, lighthouse_broken_glass_Lighthouse_Broken_Glass_Inside_mesh_layer_2),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lighthouse_broken_glass_Lighthouse_Broken_Glass_Outside_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE_DECAL, lighthouse_broken_glass_Lighthouse_Broken_Glass_Outside_mesh_layer_2),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lighthouse_broken_glass_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_OPAQUE_DECAL, lighthouse_broken_glass_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
