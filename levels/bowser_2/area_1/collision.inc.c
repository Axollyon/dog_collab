const Collision bowser_2_area_1_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(16),
	COL_VERTEX(-1299, -750, 500),
	COL_VERTEX(1299, 750, 500),
	COL_VERTEX(1299, 750, -500),
	COL_VERTEX(-1299, -750, -500),
	COL_VERTEX(2165, 1250, 500),
	COL_VERTEX(2165, 1250, -500),
	COL_VERTEX(-2165, -1250, -500),
	COL_VERTEX(-2165, -1250, 500),
	COL_VERTEX(-2665, -384, 500),
	COL_VERTEX(-1799, 116, 500),
	COL_VERTEX(799, 1616, 500),
	COL_VERTEX(1665, 2116, 500),
	COL_VERTEX(-1799, 116, -500),
	COL_VERTEX(-2665, -384, -500),
	COL_VERTEX(1665, 2116, -500),
	COL_VERTEX(799, 1616, -500),
	COL_TRI_INIT(SURFACE_DEFAULT, 18),
	COL_TRI(0, 1, 2),
	COL_TRI(0, 2, 3),
	COL_TRI(2, 1, 4),
	COL_TRI(2, 4, 5),
	COL_TRI(0, 3, 6),
	COL_TRI(0, 6, 7),
	COL_TRI(0, 7, 8),
	COL_TRI(0, 8, 9),
	COL_TRI(4, 1, 10),
	COL_TRI(4, 10, 11),
	COL_TRI(1, 0, 9),
	COL_TRI(1, 9, 10),
	COL_TRI(3, 12, 13),
	COL_TRI(3, 13, 6),
	COL_TRI(5, 14, 15),
	COL_TRI(5, 15, 2),
	COL_TRI(2, 15, 12),
	COL_TRI(2, 12, 3),
	COL_TRI_STOP(),
	COL_END()
};
