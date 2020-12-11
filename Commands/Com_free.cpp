#pragma once
#include "../User.cpp"
#include "../systemcall.cpp"

#define MAX_ARE_YOU_FREE_NUMBER 5

static wchar_t free_keywords[MAX_ARE_YOU_FREE_NUMBER][30] = {
    L"What should I do",
    L"Free",
		L"free"
    L"what should I do",
    L"I'm free now",
  };

struct Com_free {
  User * user;

  bool Com_free::check(wchar_t *com) {
    for (int i = 0; i < MAX_ARE_YOU_FREE_NUMBER; i++) {
      if (strcmps(com, free_keywords[i]))
        return true;
    }
    return false;
  }

  void Com_free::prepare(User * user) {
    this->user = user;
  }

  void Com_free::execute() {
    if(user->favorability < -50) {
        printfs(L"Go to bed right now!\r\n");
    } else if(user->favorability < 0) {
        printfs(L"You have to do many things\r\n");
				printfs(L"homework\r\n");
				printfs(L"clean room\r\n");
    } else if(user->favorability<50){
			  printfs(L"Me too");
        printfs(L"Please talk to me\r\n");
    }else{
			printfs(L"I'm free now!\r\n");
			printfs(L"Please talk to me right now!!\r\n");
		}
  }
};
