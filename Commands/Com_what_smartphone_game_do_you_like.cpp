#pragma once
#include "../User.cpp"
#include "../systemcall.cpp"

#define MAX_WHATSMARTPHONEGAMEDOYOULIKE_NUMBER 4

static wchar_t whatsmartphonegamedoyoulike_keywords[MAX_WHATSMARTPHONEMGAME_NUMBER][30] = {
  L"what smartphone game do you like",
  L"what smartphone game do you like?",
  L"What smartphone game do you like",
  L"What smartphone game do you like?"
  };

struct Com_whatsmartphonegamedoyoulike {
  User * user;

  bool Com_whatsmartphonegamedoyoulike::check(wchar_t *com) {
    for (int i = 0; i < MAX_WHATSMARTPHONEGAMEDOYOULIKE_NUMBER; i++) {
      if (strcmps(com, whatsmartphonegamedoyoulike_keywords[i]))
        return true;
    }
    return false;
  }

  void Com_whatsmartphonegamedoyoulike::prepare(User * user) {
    this->user = user;
  }

  void Com_whatsmartphonegamedoyoulike::execute() {
    if(user->favoravility < -50) {
        printfs(L"Don't open your mouth.");
        printfs(L"\r\n");
    } else if(user->favoravility < 50) {
        printfs(L"I like Monster Strike.");
        printfs(L"\r\n");
    } else {
        printfs(L"I like Monster Strike!");
        printfs(L"\r\n");
        printfs(L"It has fun!");
        printfs(L"\r\n");
    }
    user->favoravility += 10;
  }
};