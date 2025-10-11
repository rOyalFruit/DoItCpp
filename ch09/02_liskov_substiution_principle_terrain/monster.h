#pragma once
#include "character.h"

class player;
class monster {
public:
    virtual void find_route(player& target_player) = 0;
    virtual bool attach_target(player* target_player) = 0;
    virtual void check_target(player& target_player) = 0;
    virtual void attack_special(player& target_player) = 0;
    virtual void set_location(int x, int y);
    int get_monster_type();
protected:
    int calculate_distance(player& target_player);
    character* target_player = nullptr;
    int monster_type;
private:
    character monster_body;
};

class monster_a : public monster {
public:
    monster_a();
    void find_route(player& target_player) override;
    bool attach_target(player* target_player) override;
    void check_target(player& target_player) override;
    void attack_special(player& target_player) override;
};

class monster_b : public monster {
public:
    monster_b();
    void find_route(player& target_player) override;
    bool attach_target(player* target_player) override;
    void check_target(player& target_player) override;
    void attack_special(player& target_player) override;
};

class monster_c : public monster {
public:
    monster_c();
    void find_route(player& target_player) override;
    bool attach_target(player* target_player) override;
    void check_target(player& target_player) override;
    void attack_special(player& target_player) override;
};
