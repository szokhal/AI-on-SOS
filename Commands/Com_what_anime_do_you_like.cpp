#pragma once
#inlcude <stdio.h>
#include "../User.cpp"
#include "../systemcall.cpp"

#define WHATANIMEDOYOULIKE 1

static wchar_t WHATANIMEDOYOULIKE_keywords[MAX_WHATANIMEDOYOULIKE_NUMBER][30] = {
	L"what anime do you like"
};

struct Com_WHATANIMEDOYOULIKE {
  User * user;

  bool Com_WHATANIMEDOYOULIKE::check(wchar_t *com) {
    for (int i = 0; i < MAX_WHATANIMEDOYOULIKE_NUMBER; i++) {
      if (strcmps(com, WHATANIMEDOYOULIKE_keywords[i]))
        return true;
    }
    return false;
  }

  void Com_WHATANIMEDOYOULIKE::prepare(User * user) {
    this->user = user;
  }

  void Com_WHATANIMEDOYOULIKE::execute() {
    if(user->favoravility < 0){
        printfs(L"I don't like watching anime.");
        printfs(L"\r\n");
    }else{
			printfs(L"I like SAO.");
			printfs(L"\r\n");
		}
		user->favoravility+=10;
		}
	}
};
