﻿#include <iostream>

using namespace std;

class character {
public:
	character() {
		cout << "charater 클래스 생성자" << endl;
	}
};

class monster {
public:
	monster() {
		cout << "monster 클래스 생성자" << endl;
	}
};

class monster_a :public monster, character {
public:
	monster_a() {
		cout << "monster_a 클래스 생성자" << endl;
	}
};

int main() {
	monster_a forest_monster;

	return 0;
}