void bhv_lighthouse_broken_glass_loop(void) {
    load_object_collision_model();

    if (cur_obj_dist_to_nearest_object_with_behavior(bhvExplosion) <= 350.f) {
        play_puzzle_jingle();
        obj_explode_and_spawn_coins(80.0f, COIN_TYPE_NONE);
    }
}