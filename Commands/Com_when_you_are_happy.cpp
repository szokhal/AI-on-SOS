#pragma once
#include "../User.cpp"
#include "../systemcall.cpp"

#define MAX_WHEN_YOU_ARE_HAPPY_NUMBER 4

static wchar_t when_you_are_happy_keyword[MAX_WHEN_YOU_ARE_HAPPY_NUMBER][30] = {
  L"When are you happy?",
  L"When are you happy",
  L"what time are you happy?",
  L"what time are you happy"
};

struct Com_when_you_are_happy {
  User user;

  bool Com_when_you_are_happy::check(wchar_t *com) {
    for (int i = 0; i < MAX_HELLO_NUMBER; i++) {
      if (strcmps(com, when_you_are_happy_keywords[i]))
        return true;
    }
    return false;
  }

  void Com_when_you_are_happy::prepare(User user) {
    this->user = user;
  }

  void Com_when_you_are_happy::execute() {
    if(user->favoravility < -50){
      printfs(L"When you're bullying you.\n\r");
          } else if(user->favoravility >= -50 && user->facoravility < 50){
      printfs(L"You will be able to discover new horizons with your use of English.\n\r");
    }else {
      printfs(L"I'm happy when I get to know something new!\n\r");
      printfs(L "When are you happy?");
    }
  }
};
