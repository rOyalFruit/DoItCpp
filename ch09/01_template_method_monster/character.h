#ifndef CHARACTER_H
#define CHARACTER_H

// character 기본 클래스
// 모든 캐릭터(플레이어, 몬스터)의 기본이 되는 클래스
class character {
public:
    character() : hp(100), power(100), location_x(0), location_y(0) {};
    int get_hp() { return hp; }
    int get_power() { return power; }
    int get_location(bool x) { return x ? location_x : location_y; }
    void set_location(int x, int y) { location_x = x; location_y = y; }

protected:
    int hp;           // 체력
    int power;        // 공격력
    int location_x;   // X 좌표
    int location_y;   // Y 좌표
};

// character 클래스를 상속받은 player 클래스
class player : public character {
public:
    player() {};
};

#endif // CHARACTER_H
