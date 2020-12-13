#pragma once
#include "../User.cpp"
#include "../systemcall.cpp"

#define MAX_GREETING_NUMBER 3

static wchar_t greeting_keywords[MAX_GREETING_NUMBER][48] {
	L"greeting",
	L"world greetings",
	L"please tell me about world greetings",
};

struct Com_greeting {
	User* user;

	bool Com_greeting::check(wchar_t* com) {
		for (int i = 0; i < MAX_GREETING_NUMBER; i++) {
			if (strcmps(com, greeting_keywords[i])) {
				return true;
			}
		}
		return false;
	}

	void Com_greeting::prepare(User* user) {
		this->user = user;
	}

	// compare ayasii
	void Com_greeting::execute() {
		printfs(L"Where?\r\n");
		printfs(L"Japanese,English,Spanish,Chinese,Germany\r\n");
		imageview(L"big_smile.bgra");
		if (compare(L"Japanese")) {
			printfs(L"Konnichiha!\r\n");
		} else if (compare(L"English")) {
			printfs(L"Hello!\r\n");
		} else if (compare(L"Spanish")) {
			printfs(L"Hola!\r\n");
		} else if (compare(L"Germany")) {
			printfs(L"Guten Tag!\r\n");
		} else if (compare(L"Chinese")) {
			printfs(L"Ni hao!\r\n");
		}
	}
};
