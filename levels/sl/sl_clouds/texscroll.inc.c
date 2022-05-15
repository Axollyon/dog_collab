void scroll_sts_mat_sl_clouds_Clouds_layer1() {
	Gfx *mat = segmented_to_virtual(mat_sl_clouds_Clouds_layer1);
	shift_s(mat, 14, PACK_TILESIZE(0, 1));
	shift_t(mat, 14, PACK_TILESIZE(0, 1));
	shift_s_down(mat, 22, PACK_TILESIZE(0, 1));
	shift_t(mat, 22, PACK_TILESIZE(0, 1));
};

void scroll_sl_level_dl_sl_clouds() {
	scroll_sts_mat_sl_clouds_Clouds_layer1();
}
