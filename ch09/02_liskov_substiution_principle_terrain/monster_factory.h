#pragma once
#include "terrain.h"
#include "monster.h"
#include <list>

class monster_factory {
public:
    static void create_monster(const int terrain_type, int count);
    static void destroy_monster();
    static void create_terrain();
    static void destroy_terrain();
    static monster* get_monster(int index);
    static int get_monster_count();
    static void initialize_monster();
private:
    static monster* create_monster(const int terrain_type, terrain* terrain_inst);
    static std::list<monster*> mon_list;
    static int mon_count;
    static terrain* terrain_inst[3];
};
