#include "systemcall.cpp"

class User {
public:
	wchar_t name[20];
	int age;
	int favorability;

	//コンストラクタ
	User(wchar_t * newName, int newAge) {
		name = newName;
		age  = newAge;
		favorability = 0;
	}

	User(wchar_t * newName) {
		name = newName;
		age = -1;
		favorability = 0;
	}

	User() {
		name = L"";
		age = 0;
		favorability = 0;
	}
}