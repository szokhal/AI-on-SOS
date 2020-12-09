#pragma once
#include "../User.cpp"
#include "../systemcall.cpp"

#define MAX_WHAT_SEASON_NUMBER 4

static wchar_t what_season_keywords[MAX_WHAT_SEASON_NUMBER][20] {
	L"season",
	L"Please tell me about four seasons",
	L"What season do you like",
	L"What season do you like?",

};

struct Com_what_season {
	User* user;

	Com_what_season::check(wchar_t* com) {
		for (int i = 0; i < MAX_WHAT_SEASON_NUMBER; i++) {
			if (strcmps(com, what_season_keywords[i])) {
				return true;
			}
		}
		return false;
	}

	void Com_what_season::prepare(User* user) {
		this->user = user;
	}

	void Com_what_season::execute() {
		printfs(L"I like winter\r\n");
		printfs(L"How about you?");
		if (Compare(L"spring")) {
			printfs(L"There are a lot of pollen\r\n");
		} else if (Compare(L"summer")) {
			printfs(L"There are many fun events\r\n");
		} else if (Compare(L"autumn")||Compare("fall")) {
			printfs(L"It's a comfortable season\r\n");
		} else if (Compare("winter")) {
			printfs(L"Really!?Me too!!\r\n");

		}
	}
};
