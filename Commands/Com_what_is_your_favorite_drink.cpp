#pragma once
#include "../User.cpp"
#include "../systemcall.cpp"

#define MAX_DRINK_NUMBER 3

static wchar_t drink_keywords[MAX_DRINK_NUMBER][30] = {
    L"drink",
    L"What is your favorite drink?",
		L"What is your favorite drink",
  };

struct Com_drink {
  User * user;

  bool Com_drink::check(wchar_t *com) {
    for (int i = 0; i < MAX_DRINK_NUMBER; i++) {
      if (strcmps(com, drink_keywords[i]))
        return true;
    }
    return false;
  }

  void Com_drink::prepare(User * user) {
    this->user = user;
  }

  void Com_drink::execute() {
    if(user->favoravility < -50) {
        printfs(L"I don't wanna tell you!\r\n");
    } else if(user->favoravility < 50) {
        printfs(L"I don't drink.\r\n");
    } else{
			printfs(L"I like cola\r\n");
			printfs(L"I drink carbonated drinks.\r\n");
		}
  }
};
