#include <iostream>
#include <list>

using namespace std;

class character {
public:
	character() : hp(100), power(100)
	{
	};
	void get_damage(int _damage) {};

protected:
	int hp;
	int power;
};

class player : public character {
public:
	player() {};
};

class monster {
public:
	monster() {};
	void attack(player target_player) {};
	virtual void attack_special(player target_player);
	virtual void attack_at_down() = 0; // 순수 가상 함수 선언
};

class monster_a :public monster, character {
public:
	// 상속받은 함수 오버라이드 선언
	virtual void attack_special(player target_player) override;
};

class monster_b :public monster, character {
public:
	virtual void attack_special(player target_player) override;
};

class monster_c :public monster, character {
	virtual void attack_special(player target_player) override;
};

int main() {
	list<monster*> mon_list;

	monster_a first_monster;
	mon_list.push_back(&first_monster);

	monster_b second_monster;
	mon_list.push_back(&second_monster);

	monster_c third_monster;
	mon_list.push_back(&third_monster);

	for(auto item: mon_list) {
		item->attack_at_down();
	}

	return 0;
}