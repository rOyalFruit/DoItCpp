#include <iostream>
#include "character.h"
#include "monster.h"
#include "terrain.h"
#include "monster_factory.h"
using namespace std;

void monster_routine(monster* mon, player target_player) {
    mon->attach_target(&target_player);
    mon->find_route(target_player);
    mon->check_target(target_player);
}

int main() {
    int mon_count, i;
    player target_player_dummy;
    monster_factory::create_terrain();
    target_player_dummy.set_location(0, 0); // 임의 위치
    monster_factory::initialize_monster();
    mon_count = monster_factory::get_monster_count();
    for (i = 0; i < mon_count; ++i) {
        cout << endl;
        monster_routine(monster_factory::get_monster(i), target_player_dummy);
    }
    monster_factory::destroy_monster();
    monster_factory::destroy_terrain();
    return 0;
}
