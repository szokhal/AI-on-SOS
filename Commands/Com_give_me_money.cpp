#pragma once
#inlcude <stdio.h>
#include "../User.cpp"
#include "../systemcall.cpp"

#define GIVEMEMONEY 1

static wchar_t GIVEMEMONEY_keywords[MAX_GIVEMEMONEY_NUMBER][14] = {
	L"give me money"
};

struct Com_GIVEMEMONEY {
  User * user;

  bool Com_GIVEMEMONEY::check(wchar_t *com) {
    for (int i = 0; i < MAX_GIVEMEMONEY_NUMBER; i++) {
      if (strcmps(com, GIVEMEMONEY_keywords[i]))
        return true;
    }
    return false;
  }

  void Com_GIVEMEMONEY::prepare(User * user) {
    this->user = user;
  }

  void Com_GIVEMEMONEY::execute() {
    if(user->favoravility < 0){
        printfs(L"Work.");
        printfs(L"\r\n");
				user->favoravility -= 10;
    }else if(user->favoravility >= 0 &&user->favoravility < 99){
				printfs(L"I'll give you 100 yen");
        printfs(L"\r\n");
    }else{
				printfs(L"I'll give you 100 million yen!!!!!!!!!");
				printfs(L"\r\n");
				user->favoravility += 10;
			}
		}
  }
};
