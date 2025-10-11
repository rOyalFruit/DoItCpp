#include "monster.h"
#include "character.h"
#include <iostream>
#include <cmath>
using namespace std;

monster_a::monster_a() { monster_type = 0; }
monster_b::monster_b() { monster_type = 1; }
monster_c::monster_c() { monster_type = 2; }

void monster::set_location(int x, int y) { monster_body.set_location(x, y); }
int monster::get_monster_type() { return monster_type; }
int monster::calculate_distance(player& target_player) {
    return (int)sqrt(pow(target_player.get_location(true) - monster_body.get_location(true), 2) +
        pow(target_player.get_location(false) - monster_body.get_location(false), 2));
}

void monster_a::attack_special(player& target_player) {
    cout << "인텡글 공격 : 데미지 - 15 hp" << endl;
}
void monster_a::find_route(player& target_player) {
    cout << "타겟 찾아 가기 - 최단 거리 우선" << endl;
}
bool monster_a::attach_target(player* target_player) {
    if (calculate_distance(*target_player) < 30) {
        this->target_player = target_player;
        cout << "뒤따라 가면서 플레이어 쫓아 가기" << endl;
        return true;
    }
    return false;
}
void monster_a::check_target(player& target_player) {
    if (target_player.get_hp() < 40) {
        attack_special(target_player);
        return;
    }
}

void monster_b::attack_special(player& target_player) {
    cout << "가상 공격 : 데미지 - 0 hp" << endl;
}
void monster_b::find_route(player& target_player) {
    cout << "타겟 찾아 가기 - 최소 시간 우선" << endl;
}
bool monster_b::attach_target(player* target_player) {
    if (calculate_distance(*target_player) > 30) {
        this->target_player = target_player;
        cout << "위치 추적을 통해서 찾아 가기" << endl;
        return true;
    }
    return false;
}
void monster_b::check_target(player& target_player) {
    if (target_player.get_hp() < 10) {
        attack_special(target_player);
        return;
    }
}

void monster_c::attack_special(player& target_player) {
    cout << "강력 뇌전 공격 : 데미지 - 100 hp" << endl;
}
void monster_c::find_route(player& target_player) {
    cout << "타겟 찾아 가기 - 타겟 시선에 보이지 않도록" << endl;
}
bool monster_c::attach_target(player* target_player) {
    this->target_player = target_player;
    cout << "눈에 띄면 무조건 따라감" << endl;
    return true;
}
void monster_c::check_target(player& target_player) {
    attack_special(target_player);
}
