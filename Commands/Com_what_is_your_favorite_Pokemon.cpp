#pragma once
#inlcude <stdio.h>
#include "../User.cpp"
#include "../systemcall.cpp"

#define WHATISYOURFAVORITEPOKEMON 2

static wchar_t WHATISYOURFAVORITEPOKEMON_keywords[MAX_WHATISYOURFAVORITEPOKEMON_NUMBER][14] = {
	L"what is your favorite Pokemon",
  L"what is your favorite Pokemon?"
};

struct Com_WHATISYOURFAVORITEPOKEMON {
  User * user;

  bool Com_WHATISYOURFAVORITEPOKEMON::check(wchar_t *com) {
    for (int i = 0; i < MAX_WHATISYOURFAVORITEPOKEMON_NUMBER; i++) {
      if (strcmps(com, WHATISYOURFAVORITEPOKEMON_keywords[i]))
        return true;
    }
    return false;
  }

  void Com_WHATISYOURFAVORITEPOKEMON::prepare(User * user) {
    this->user = user;
  }

  void Com_WHATISYOURFAVORITEPOKEMON::execute() {
    if(user->favoravility < 0){
        printfs(L"I don't like any pokemon.");
        printfs(L"\r\n");
				imageview(L"jotome.bgra");
			}else{
				printfs(L"My favorite Pokemon is Pikachu. It's cute.");
				printfs(L"\r\n");
				imageview(L"big_smile.bgra");
			}
			user->favoravility += 10;
		}
};
