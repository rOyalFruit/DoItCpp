#include <iostream>
#include <random>
#include "character.h"
#include "monster.h"
#include "monster_factory.h"

using namespace std;

// 랜덤 숫자 생성기 (플레이어 위치용)
random_device rd_main;
mt19937 gen_main(rd_main());
uniform_int_distribution<int> dis_main(0, 99);

// 순수 가상 함수의 조합으로 흐름을 정의하는 전역 함수
// 템플릿 메서드 패턴: 몬스터의 행동 순서를 정의
void monster_routine(monster* mon, player target_player) {
    mon->attach_target(&target_player);
    mon->find_route(target_player);
    mon->check_target(target_player);
}

int main() {
    int mon_count, i;
    player target_player_dummy;

    // 플레이어 랜덤 위치 설정
    target_player_dummy.set_location(dis_main(gen_main), dis_main(gen_main));
    
    // 몬스터 초기화
    monster_factory::initialize_monster();

    // 모든 몬스터에 대해 동일한 루틴 실행
    mon_count = monster_factory::get_monster_count();
    for (i = 0; i < mon_count; ++i) {
        cout << endl;
        cout << endl;
        // 몬스터 종류와 상관없이 전체 몬스터를 순회하면서 동일한 흐름을 실행
        monster_routine(monster_factory::get_monster(i), target_player_dummy);
    }

    // 메모리 해제
    monster_factory::destroy_monster();

    return 0;
}
