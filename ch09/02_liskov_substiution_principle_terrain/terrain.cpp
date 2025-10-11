#include "terrain.h"
#include <iostream>
using namespace std;

forest_terrain::forest_terrain() { terrain_type = 0; }
cyber_terrain::cyber_terrain() { terrain_type = 1; }
urban_terrain::urban_terrain() { terrain_type = 2; }

void terrain::set_start_location(int x, int y) {
    start_location_x = x;
    start_location_y = y;
}
void terrain::set_end_location(int x, int y) {
    end_location_x = x;
    end_location_y = y;
}
void terrain::update_monster_list(monster* mon) {
    monster_list.push_back(mon);
}

void forest_terrain::allocate_monster(monster* mon) {
    if (mon->get_monster_type() == 0) {
        update_monster_list(mon);
        cout << "Monster A를 숲에 배치합니다." << endl;
    }
}
void forest_terrain::bost_monster(monster* mon) {
    if (mon->get_monster_type() == 0) {
        cout << "Monster A가 숲에서는 힘이 더 강해집니다." << endl;
    }
}

void cyber_terrain::allocate_monster(monster* mon) {
    update_monster_list(mon);
    cout << "모든 종류의 Monster를 사이버 공간에 배치 합니다." << endl;
}
void cyber_terrain::bost_monster(monster* mon) {
    cout << "모든 몬스터가 사이버 공간에서는 속도가 빨라 집니다." << endl;
}

void urban_terrain::allocate_monster(monster* mon) {
    if (mon->get_monster_type() != 0) {
        update_monster_list(mon);
        cout << "Monster B, C를 도심에 배치 합니다." << endl;
    }
}
void urban_terrain::bost_monster(monster* mon) {
    if (mon->get_monster_type() == 2) {
        update_monster_list(mon);
        cout << "Monster C는 도심에 힘이 강해 집니다." << endl;
    }
}
