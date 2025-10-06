#include <iostream>

using namespace std;

class bank {
private:
	int safe; //금고

public:
	bank(); // 기본 생성자
	void use_counter(int _in, int _out); // 입출금 창구 함수
};

int main() {
	bank my_bank;
	my_bank.safe -= 100;

	return 0;
}