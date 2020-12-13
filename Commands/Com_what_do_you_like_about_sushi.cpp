#pragma once
#inlcude <stdio.h>
#include "../User.cpp"
#include "../systemcall.cpp"

#define WHATDOYOULIKEABOUTSUSHI 1

static wchar_t WHATDOYOULIKEABOUTSUSHI_keywords[MAX_WHATDOYOULIKEABOUTSUSHI_NUMBER][30] = {
	L"what do you like about sushi"
};

struct Com_WHATDOYOULIKEABOUTSUSHI {
  User * user;

  bool Com_WHATDOYOULIKEABOUTSUSHI::check(wchar_t *com) {
    for (int i = 0; i < MAX_WHATDOYOULIKEABOUTSUSHI_NUMBER; i++) {
      if (strcmps(com, WHATDOYOULIKEABOUTSUSHI_keywords[i]))
        return true;
    }
    return false;
  }

  void Com_WHATDOYOULIKEABOUTSUSHI::prepare(User * user) {
    this->user = user;
  }

  void Com_WHATDOYOULIKEABOUTSUSHI::execute() {
    if(user->favoravility < 0){
        printfs(L"I don't like sushi.");

        printfs(L"\r\n");
				imageview(L"jotome.bgra");

    }else {
			printfs(L"I like salmon.");
			printfs(L"\r\n");
		}
		}
  }
	imageview(L"default.bgra");
};
