#pragma once
#inlcude <stdio.h>
#include "../User.cpp"
#include "../systemcall.cpp"

#define ILIKEPYTHON 1

static wchar_t ILIKEPYTHON_keywords[MAX_ILIKEPYTHON_NUMBER][14] = {
	L"what is your favorite programming language"
};

struct Com_ILIKEPYTHON {
  User * user;

  bool Com_ILIKEPYTHON::check(wchar_t *com) {
    for (int i = 0; i < MAX_ILIKEPYTHON_NUMBER; i++) {
      if (strcmps(com, ILIKEPYTHON_keywords[i]))
        return true;
    }
    return false;
  }

  void Com_ILIKEPYTHON::prepare(User * user) {
    this->user = user;
  }

  void Com_ILIKEPYTHON::execute(){
		printfs(L"It's silly if you use only useful libraries.\r\n");
		imageview(L"jotome.bgra");
		printfs(L"c++is the supreme\r\n");
			user->favoravility -=10 ;
		}
  }
	imageview(L"default.bgra");
};
