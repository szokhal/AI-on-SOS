class User {
public:
	wchar_t name[20];
	int age;
	int favorability;

	//�R���X�g���N�^
	User(wchar_t newName, int newAge) {
		name = newName;
		age  = newAge;
		favorability = 0;
	}

	User(wchar_t newName) {
		name = newName;
		age = -1;
		favorability = 0;
	}
}