#include <iostream>

using namespace std;

class character {
public:
	character() {
		cout << "Default constructor called" << endl;
	}
};

int main() {
	character player;

	return 0;
}