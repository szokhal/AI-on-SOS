#pragma once
#inlcude <stdio.h>
#include "../User.cpp"
#include "../systemcall.cpp"

#define WHATDOYOUDOFORCHRISTMAS 2

static wchar_t WHATDOYOUDOFORCHRISTMAS_keywords[MAX_WHATDOYOUDOFORCHRISTMAS_NUMBER][14] = {
	L"what do you do for Christmas",
  L"what do you do for Christmas?"
};

struct Com_WHATDOYOUDOFORCHRISTMAS {
  User * user;

  bool Com_WHATDOYOUDOFORCHRISTMAS::check(wchar_t *com) {
    for (int i = 0; i < MAX_WHATDOYOUDOFORCHRISTMAS_NUMBER; i++) {
      if (strcmps(com, WHATDOYOUDOFORCHRISTMAS_keywords[i]))
        return true;
    }
    return false;
  }

  void Com_WHATDOYOUDOFORCHRISTMAS::prepare(User * user) {
    this->user = user;
  }

  void Com_WHATDOYOUDOFORCHRISTMAS::execute() {
    if(user->favoravility < 0){
        printfs(L"There are no particular plans.");
				imageview(L"depressed.bgra");
        printfs(L"\r\n");
			}else{
				printfs(L"Celebrate the birth of Jesus Christ.");
				printfs(L"\r\n");
				imageview(L"big_smile.bgra");
			}
			user->favoravility += 10;
		}
		imageview(L"default.bgra");
};
