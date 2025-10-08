#include <iostream>

using namespace std;

class character {
public:
	character() : hp(100), power(100) {};
	int get_hp() { return hp; };
	int get_power() { return power; };
protected:
	int hp;
	int power;
};

class player {
public:
	player() {};
private:
	character main_body;
};

class monster {
public:
	monster() {};
	void get_damage(int _damage) {};
	virtual void attack(player target_player) {
		cout << "공격: 데미지 - 10 hp" << endl;
	}
};

class monster_2nd_gen : public monster {
public:
	virtual void attack(player target_player) override {
		cout << "새로운 공격: 데미지 - 30 hp" << endl;
	}
};

class monster_a { // Composition
public:
	void attack(player target_player) {
		main_role.attack(target_player);
	}

private:
	// 캐릭터와 몬스터 객체를 직접 생성(몬스터 A와 생명 주기가 같음)
	character main_body;
	monster main_role;
};

class monster_b { // Aggregation
public:
	monster_b(character &ref_character, monster &ref_monster)
		: main_body(ref_character), main_role(ref_monster) {};

	void attack(player target_player) {
		main_role.attack(target_player);
	}

private:
	// 캐릭터와 몬스터 객체를 참조(몬스터 B와 생명 주기가 다름)
	character& main_body; 
	monster& main_role;
};

int main() {
	player player_1;
	character character_obj;
	monster monster_obj;
	monster_2nd_gen monster_new_obj;

	// 내부에서 객체를 직접 생성
	monster_a forest_monster;

	// 외부 객체 전달
	monster_b tutorial_monster(character_obj, monster_obj);
	monster_b urban_monster(character_obj, monster_new_obj);

	cout << "몬스터 A 공격" << endl;
	forest_monster.attack(player_1);

	cout << endl << "몬스터 B 공격" << endl;
	tutorial_monster.attack(player_1);
	urban_monster.attack(player_1);

	return 0;
}