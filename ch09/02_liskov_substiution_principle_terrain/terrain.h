#pragma once
#include <list>
#include "monster.h"

class terrain {
public:
    virtual void allocate_monster(monster* mon) = 0;
    virtual void bost_monster(monster* mon) = 0;
    void set_start_location(int x, int y);
    void set_end_location(int x, int y);
protected:
    int terrain_type;
    void update_monster_list(monster* mon);
private:
    int start_location_x;
    int start_location_y;
    int end_location_x;
    int end_location_y;
    std::list<monster*> monster_list;
};

class forest_terrain : public terrain {
public:
    forest_terrain();
    void allocate_monster(monster* mon) override;
    void bost_monster(monster* mon) override;
};

class cyber_terrain : public terrain {
public:
    cyber_terrain();
    void allocate_monster(monster* mon) override;
    void bost_monster(monster* mon) override;
};

class urban_terrain : public terrain {
public:
    urban_terrain();
    void allocate_monster(monster* mon) override;
    void bost_monster(monster* mon) override;
};
