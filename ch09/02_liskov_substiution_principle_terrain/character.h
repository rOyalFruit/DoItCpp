#pragma once

class character {
public:
    character() : hp(100), power(100), location_x(0), location_y(0) {};
    int get_hp() { return hp; }
    int get_power() { return power; }
    int get_location(bool x) { return x ? location_x : location_y; }
    void set_location(int x, int y) { location_x = x; location_y = y; }

protected:
    int hp;
    int power;
    int location_x;
    int location_y;
};

class player : public character {
public:
    player() : character() {}
};
