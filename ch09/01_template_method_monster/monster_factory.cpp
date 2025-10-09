#include "monster_factory.h"
#include <random>

using namespace std;

// static 멤버 변수 초기화
list<monster*> monster_factory::mon_list = {};
int monster_factory::mon_count = 0;

// 랜덤 숫자 생성기
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> dis(0, 99);

// 생성된 몬스터 개수 반환
int monster_factory::get_monster_count() {
    return mon_count;
}

// 특정 인덱스의 몬스터 가져오기
monster* monster_factory::get_monster(int index) {
    monster* new_mon = nullptr;
    auto item = mon_list.begin();
    advance(item, index);
    new_mon = *item;
    return new_mon;
}

// 초기 몬스터 생성
void monster_factory::initialize_monster() {
    create_monster(forest_terrain, 2);  // 숲 몬스터 2마리
    create_monster(cyber_terrain, 3);   // 사이버 몬스터 3마리
    create_monster(urban_terrain, 1);   // 도시 몬스터 1마리
}

// 단일 몬스터 생성 (private)
monster* monster_factory::create_monster(const int terrain_type) {
    monster* new_mon = nullptr;
    
    // 지형 타입에 따라 다른 몬스터 생성
    switch (terrain_type) {
    case forest_terrain:
        new_mon = new monster_a();
        break;
    case cyber_terrain:
        new_mon = new monster_b();
        break;
    case urban_terrain:
        new_mon = new monster_c();
        break;
    }

    mon_list.push_back(new_mon);
    mon_count++;
    return new_mon;
}

// 모든 몬스터 삭제
void monster_factory::destroy_monster() {
    for (auto mon : mon_list) {
        delete mon;
    }
}

// 여러 개의 몬스터 생성
void monster_factory::create_monster(const int terrain_type, int count) {
    monster* mon = nullptr;

    for (int i = 0; i < count; ++i) {
        mon = monster_factory::create_monster(terrain_type);
        // 랜덤 위치 설정
        mon->set_location(dis(gen), dis(gen));
    }
}
