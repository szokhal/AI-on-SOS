#pragma once
#include "../User.cpp"
#include "../systemcall.cpp"

#define MAX_CARING_NUMBER 4

static wchar_t iamsotired_keywords[MAX_CARING_NUMBER][30] = {
  L"I am so tired",
  L"It was hard for work",
  L"I don't feel great",
  L"I made a mistake today"
};

struct Com_iamsotired {
  User* user;

  bool Com_iamsotired::check(wchar_t *com) {
    for (int i = 0; i < MAX_CARING_NUMBER; i++) {
      if (strcmps(com, iamsotired_keywords[i]))
        return true;
    }
    return false;
  }

  void Com_iamsotired::prepare(User * user) {
    this->user = user;
  }

  void Com_iamsotired::execute() {
    if(user->favorability < -50) {
        printfs(L"Go to bed early!");
        printfs(L"\r\n");
    }  else if(user->favorability < 50){
        printfs(L"What happened!?");
        printfs(L"\r\n");
    }else{
			printfs(L"Do you need me?");
			printfs(L"\r\n");
			printfs(L"Is there anything I can do?");
			printfs(L"\r\n");
			printfs(L"I'll listen to you");
			printfs(L"\r\n");
		}
  }
};
