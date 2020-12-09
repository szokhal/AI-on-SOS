#pragma once
#include "../User.cpp"
#include "../systemcall.cpp"

#define MAX_WHATRHYTHMGAMEDOYOULIKE_NUMBER 4

static wchar_t whatrhythmgamedoyoulike_keywords[MAX_WHATRHYTHMGAME_NUMBER][30] = {
  L"what rhythm game do you like",
  L"what rhythm game do you like?",
  L"What rhythm game do you like",
  L"What rhythm game do you like?"
  };

struct Com_whatrhythmgamedoyoulike {
  User * user;

  bool Com_whatrhythmgamedoyoulike::check(wchar_t *com) {
    for (int i = 0; i < MAX_WHATRHYTHMGAMEDOYOULIKE_NUMBER; i++) {
      if (strcmps(com, whatrhythmgamedoyoulike_keywords[i]))
        return true;
    }
    return false;
  }

  void Com_whatrhythmgamedoyoulike::prepare(User * user) {
    this->user = user;
  }

  void Com_whatrhythmgamedoyoulike::execute() {
    if(user->favoravility < -50) {
        imaageview(L"jitome.bgra");
        printfs(L"Why do I have to tell you that?");
        printfs(L"\r\n");
    } else if(user->favoravility < 50) {
        imageview(L"smile.bgra");
        printfs(L"I like Project Sekai.");
        printfs(L"\r\n");
    } else {
        imageview(L"big_smile.bgra");
        printfs(L"I like Project Sekai!!");
        printfs(L"\r\n");
        printfs(L"It has a lot of Vocaloid songs!!");
        printfs(L"\r\n");
    }
    user->favoravility += 15;
  }
};