#pragma once
#inlcude <stdio.h>
#include "../User.cpp"
#include "../systemcall.cpp"

#define WHATAREYOUDOINGNOW 1

static wchar_t WHATAREYOUDOINGNOW_keywords[MAX_WHATAREYOUDOINGNOW_NUMBER][23] = {
	L"what are you doing now"
};

struct Com_WHATAREYOUDOINGNOW {
  User * user;

  bool Com_WHATAREYOUDOINGNOW::check(wchar_t *com) {
    for (int i = 0; i < MAX_WHATAREYOUDOINGNOW_NUMBER; i++) {
      if (strcmps(com, WHATAREYOUDOINGNOW_keywords[i]))
        return true;
    }
    return false;
  }

  void Com_WHATAREYOUDOINGNOW::prepare(User * user) {
    this->user = user;
  }

  void Com_WHATAREYOUDOINGNOW::execute() {
    if(user->favoravility < 0){
        printfs(L"Don't talk.");
				imageview(L"jotome.bgra");
        printfs(L"\r\n");
			}else{
				printfs(L"I'm surfing the internet now.");
				imageview(L"big_smile.bgra");
				printfs(L"\r\n");
			}
			user->favoravility += 10;
		}
		imageview(L"default.bgra");
};
