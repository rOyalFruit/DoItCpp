#include <iostream>

using namespace std;

class character {
public:
    character() {
        cout << "character 클래스 생성자" << endl;
    };
};

class monster {
public:
    monster() {
        cout << "monster 클래스 생성자" << endl;
    };
};

class monster_a :public monster, character {
public:
    monster_a() {
        cout << "monster_a 클래스 생성자" << endl;
	};

    monster_a(int x, int y): location{x, y} {
        cout << "monster_a 클래스 생성자(매개변수 추가) x: " << x << ", y: " << y << endl;
	};

    void show_location() {
		cout << "Location: (" << location[0] << ", " << location[1] << ")" << endl;
    };

private:
    int location[2];
};

int main(){
    monster_a forest_monster;          // 기본 생성자 호출
	forest_monster.show_location();

	monster_a wood_monster(10, 25);    // 매개변수가 있는 생성자 호출
	wood_monster.show_location();

    return 0;
}