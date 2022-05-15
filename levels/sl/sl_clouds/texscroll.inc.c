void scroll_sts_mat_sl_clouds_Clouds_layer1() {
	static int intervalTex0 = 2;
	static int curInterval0 = 2;
	static int intervalTex1 = 2;
	static int curInterval1 = 2;
	Gfx *mat = segmented_to_virtual(mat_sl_clouds_Clouds_layer1);

	if (--curInterval0 <= 0) {
		shift_s(mat, 13, PACK_TILESIZE(0, 1));
		shift_t(mat, 13, PACK_TILESIZE(0, 1));
		curInterval0 = intervalTex0;
	}

	if (--curInterval1 <= 0) {
		shift_s_down(mat, 21, PACK_TILESIZE(0, 1));
		shift_t(mat, 21, PACK_TILESIZE(0, 1));
		curInterval1 = intervalTex1;
	}
};

void scroll_sl_level_dl_sl_clouds() {
	scroll_sts_mat_sl_clouds_Clouds_layer1();
}
