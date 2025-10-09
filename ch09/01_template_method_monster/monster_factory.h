#ifndef MONSTER_FACTORY_H
#define MONSTER_FACTORY_H

#include "monster.h"
#include <list>

// 지형 타입 상수
const int forest_terrain = 0;  // 숲
const int cyber_terrain = 1;   // 사이버
const int urban_terrain = 2;   // 도시

// Monster Factory 클래스
// 몬스터를 생성하고 관리하는 역할
class monster_factory
{
public:
    // 여러 개의 몬스터를 생성
    static void create_monster(const int terrain_type, int count);
    
    // 모든 몬스터 삭제 (메모리 해제)
    static void destroy_monster();
    
    // 특정 인덱스의 몬스터 가져오기
    static monster* get_monster(int index);
    
    // 생성된 몬스터 개수 반환
    static int get_monster_count();
    
    // 초기 몬스터 생성
    static void initialize_monster();

private:
    // 단일 몬스터 생성 (내부 사용)
    static monster* create_monster(const int terrain_type);
    
    // 몬스터 리스트
    static std::list<monster*> mon_list;
    
    // 몬스터 개수
    static int mon_count;
};

#endif // MONSTER_FACTORY_H
