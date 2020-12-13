#pragma once
#inlcude <stdio.h>
#include "../User.cpp"
#include "../systemcall.cpp"

#define WHATISYOURFAVORITEPROGRAMMINGLANGUAGE 1

static wchar_t WHATISYOURFAVORITEPROGRAMMINGLANGUAGE_keywords[MAX_WHATISYOURFAVORITEPROGRAMMINGLANGUAGE_NUMBER][50] = {
	L"what is your favorite programming language"
};

struct Com_WHATISYOURFAVORITEPROGRAMMINGLANGUAGE {
  User * user;

  bool Com_WHATISYOURFAVORITEPROGRAMMINGLANGUAGE::check(wchar_t *com) {
    for (int i = 0; i < MAX_WHATISYOURFAVORITEPROGRAMMINGLANGUAGE_NUMBER; i++) {
      if (strcmps(com, WHATISYOURFAVORITEPROGRAMMINGLANGUAGE_keywords[i]))
        return true;
    }
    return false;
  }

  void Com_WHATISYOURFAVORITEPROGRAMMINGLANGUAGE::prepare(User * user) {
    this->user = user;
  }

  void Com_WHATISYOURFAVORITEPROGRAMMINGLANGUAGE::execute() {
    if(user->favoravility < 0){
        printfs(L"My favorite programming language is assembly language.");
        printfs(L"\r\n");
				imageview(L"jotome.bgra");
			}else{
				printfs(L"My favorite programming language is c++.");
				printfs(L"\r\n");
				imageview(L"big_smile.bgra");
			}
			user->favoravility += 10;
		}
};
