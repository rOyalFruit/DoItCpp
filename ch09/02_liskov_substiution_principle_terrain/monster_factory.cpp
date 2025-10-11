#include "monster_factory.h"
#include "terrain.h"
#include "monster.h"
#include <random>
using namespace std;

const int forest_terrain_type = 0;
const int cyber_terrain_type = 1;
const int urban_terrain_type = 2;

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> dis(0, 99);
uniform_int_distribution<int> select(0, 2);

list<monster*> monster_factory::mon_list = {};
int monster_factory::mon_count = 0;
terrain* monster_factory::terrain_inst[] = { nullptr, nullptr, nullptr };

int monster_factory::get_monster_count() {
    return mon_count;
}

monster* monster_factory::get_monster(int index) {
    auto item = mon_list.begin();
    advance(item, index);
    return *item;
}

void monster_factory::initialize_monster() {
    create_monster(forest_terrain_type, 2);
    create_monster(cyber_terrain_type, 3);
    create_monster(urban_terrain_type, 1);
}

void monster_factory::create_terrain() {
    terrain_inst[0] = new forest_terrain();
    terrain_inst[1] = new cyber_terrain();
    terrain_inst[2] = new urban_terrain();
    for (auto object : terrain_inst) {
        object->set_start_location(dis(gen), dis(gen));
        object->set_end_location(dis(gen), dis(gen));
    }
}

void monster_factory::destroy_terrain() {
    for (auto inst : terrain_inst) {
        delete inst;
    }
}

monster* monster_factory::create_monster(const int terrain_type, terrain* terrain_inst) {
    monster* new_mon = nullptr;
    switch (terrain_type) {
    case forest_terrain_type:
        new_mon = new monster_a();
        break;
    case cyber_terrain_type:
        new_mon = new monster_b();
        break;
    case urban_terrain_type:
        new_mon = new monster_c();
        break;
    }
    terrain_inst->allocate_monster(new_mon);
    terrain_inst->bost_monster(new_mon);
    mon_list.push_back(new_mon);
    mon_count++;
    return new_mon;
}

void monster_factory::destroy_monster() {
    for (auto mon : mon_list) {
        delete mon;
    }
}

void monster_factory::create_monster(const int terrain_type, int count) {
    for (int i = 0; i < count; ++i) {
        monster* mon = monster_factory::create_monster(terrain_type, terrain_inst[select(gen)]);
        mon->set_location(dis(gen), dis(gen));
    }
}
