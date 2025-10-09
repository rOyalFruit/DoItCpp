#ifndef MONSTER_H
#define MONSTER_H

#include "character.h"

// Monster 인터페이스 (추상 클래스)
// 모든 몬스터가 따라야 하는 기본 규칙을 정의
class monster
{
public:
    // 순수 가상 함수 - 각 몬스터가 반드시 구현해야 함
    virtual void find_route(player& target_player) = 0;
    virtual bool attach_target(player* target_player) = 0;
    virtual void check_target(player& target_player) = 0;
    virtual void attack_special(player& target_player) = 0;
    virtual void set_location(int x, int y) { monster_body.set_location(x, y); };
    virtual ~monster() {};

protected:
    int calculate_distance(player& target_player);
    character* target_player = nullptr;

private:
    character monster_body;
};

// 몬스터 A - 숲 지역 몬스터
class monster_a : public monster {
public:
    virtual void find_route(player& target_player) override;
    virtual bool attach_target(player* target_player) override;
    virtual void check_target(player& target_player) override;
    virtual void attack_special(player& target_player) override;
};

// 몬스터 B - 사이버 지역 몬스터
class monster_b : public monster {
public:
    virtual void find_route(player& target_player) override;
    virtual bool attach_target(player* target_player) override;
    virtual void check_target(player& target_player) override;
    virtual void attack_special(player& target_player) override;
};

// 몬스터 C - 도시 지역 몬스터
class monster_c : public monster {
public:
    virtual void find_route(player& target_player) override;
    virtual bool attach_target(player* target_player) override;
    virtual void check_target(player& target_player) override;
    virtual void attack_special(player& target_player) override;
};

#endif // MONSTER_H
