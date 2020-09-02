#pragma once
#include "systemcall.cpp"

class User {
public:
	wchar_t name[20] = L" ";
	int age = 0;
	int favorability = 0;

	User(wchar_t * newName, int newAge) {
		strcpy(&name[0], newName);
		age = newAge;
	}

	User(wchar_t* newName) {
		strcpy(&name[0], newName);
		age = -1;
	}

	User() {};
};
