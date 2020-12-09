#pragma once
#include "../User.cpp"
#include "../systemcall.cpp"

#define MAX_ONE_MORE_LANGUAGE_NUMBER 4

static wchar_t what_one_more_language_keyword[MAX_ONE_MORE_LANGUAGE_NUMBER][30] = {
  L"Which language would you prefer if you could speak another language?",
  L"Which language would you prefer if you could speak another language",
  L"which language would you prefer if you could speak another language?",
  L"Which language would you prefer if you could speak another language"
}
struct Com_one_more_language {
  User user;

  bool Com_one_more_language::check(wchar_t *com) {
    for (int i = 0; i < MAX_ONE_MORE_LANGUAGE_NUMBER; i++) {
      if (strcmps(com, one_more_language_keywords[i]))
        return true;
    }
    return false;
  }

  void Com_one_more_language::prepare(User user) {
    this->user = user;
  }

  void Com_one_more_language::execute() {
    if(user->favoravility < -50){
      printfs(L"Japanese\n\r");
        } else if(user->favoravility >= -50 && user->facoravility < 50){
      printfs(L"I want to be able to speak Japanese.\n\r");
    }else {
      printfs(L"I want to be able to speak Japanese.\n\r");
      printfs(L"Because the person who made it for me is Japanese..\n\r");
    }
  }
};