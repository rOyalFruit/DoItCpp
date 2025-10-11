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
        cout << "Monster A�� ���� ��ġ�մϴ�." << endl;
    }
}
void forest_terrain::bost_monster(monster* mon) {
    if (mon->get_monster_type() == 0) {
        cout << "Monster A�� �������� ���� �� �������ϴ�." << endl;
    }
}

void cyber_terrain::allocate_monster(monster* mon) {
    update_monster_list(mon);
    cout << "��� ������ Monster�� ���̹� ������ ��ġ �մϴ�." << endl;
}
void cyber_terrain::bost_monster(monster* mon) {
    cout << "��� ���Ͱ� ���̹� ���������� �ӵ��� ���� ���ϴ�." << endl;
}

void urban_terrain::allocate_monster(monster* mon) {
    if (mon->get_monster_type() != 0) {
        update_monster_list(mon);
        cout << "Monster B, C�� ���ɿ� ��ġ �մϴ�." << endl;
    }
}
void urban_terrain::bost_monster(monster* mon) {
    if (mon->get_monster_type() == 2) {
        update_monster_list(mon);
        cout << "Monster C�� ���ɿ� ���� ���� ���ϴ�." << endl;
    }
}
