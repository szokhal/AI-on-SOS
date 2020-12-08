#pragma once
#include "../User.cpp"
#include "../systemcall.cpp"

#define MAX_WHATPCGAMEDOYOULIKE_NUMBER 4

static wchar_t whatPCgamedoyoulike_keywords[MAX_HELLO_NUMBER][30] = {
  L"what PC game do you like",
  L"what PC game do you like?"
  L"what pc game do you like"
  L"what pc game do you like?"
  };

struct Com_whatPCgamedoyoulike {
  User * user;

  bool Com_whatPCgamedoyoulike::check(wchar_t *com) {
    for (int i = 0; i < MAX_WHATPCGAMEDOYOULIKE_NUMBER; i++) {
      if (strcmps(com, whatPCgamedoyoulike_keywords[i]))
        return true;
    }
    return false;
  }

  void Com_whatPCgamedoyoulike::prepare(User * user) {
    this->user = user;
  }

  void Com_whatPCgamedoyoulike::execute() {
    if(user->favoravirity < -50) {
        printf(L"Why do I have to tell you that?");
        printf(L"\r\n");
    } else if(user->favoravirity < 50) {
        printf(L"I like Dead by Daylight.");
        printf(L"\r\n");
    } else {
        printf(L"I like Dead by Daylight!");
        printf(L"\r\n");
        printf(L"It's so exciting!!");
        printf(L"\r\n");
    }
  }
};
