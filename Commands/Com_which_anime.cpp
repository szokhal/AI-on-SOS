#pragma once
#include "../User.cpp"
#include "../systemcall.cpp"

#define MAX_WHICH_ANIME_NUMBER 3

static wchar_t which_anime_keyword[MAX_WHICH_ANIME_NUMBER][30] = {
  L"which anime do you like?",
  L"about anime",
  L"which anime do you like"
   };

struct Com_which_anime {
  User user;

  bool Com_which_anime::check(wchar_t *com) {
    for (int i = 0; i < MAX_WHICH_ANIME_NUMBER; i++) {
      if (strcmps(com, which_anime_keywords[i]))
        return true;
    }
    return false;
  }

  void Com_which_anime::prepare(User user) {
    this->user = user;
  }

  void Com_which_anime::execute() {
    if(user->favorability < -50){
      printfs(L"I have nothing to talk with you.\n\r");
      imageview(L"dead_eyes.bgra");
    } else if(user->favorability >= -50 && user->favorability < 50){
      printfs(L"I like Laid-Back Camp.\n\r");
      imageview(L"smile.bgra");
    }else {
      printfs(L"I like Laid-Back Camp.\n\r");
      printfs(L"Because Shizuoka is Laid-Back Camp's pilgrimage.\n\r");
      imageview(L"big_smile.bgra");
    }
    imageview(L"default.bgra");
  }
};
