#pragma once
#include "../User.cpp"
#include "../systemcall.cpp"

#define MAX_WHEN_YOU_ARE_HAPPY_NUMBER 4

static wchar_t when_you_are_happy_keywords[MAX_WHEN_YOU_ARE_HAPPY_NUMBER][30] = {
  L"When are you happy?",
  L"When are you happy",
  L"what time are you happy?",
  L"what time are you happy"
};

struct Com_when_you_are_happy {
  User* user;

  bool Com_when_you_are_happy::check(wchar_t *com) {
    for (int i = 0; i < MAX_WHEN_YOU_ARE_HAPPY_NUMBER; i++) {
      if (strcmps(com, when_you_are_happy_keywords[i]))
        return true;
    }
    return false;
  }

  void Com_when_you_are_happy::prepare(User* user) {
    this->user = user;
  }

  void Com_when_you_are_happy::execute() {
    if(user->favorability < -50){
      imageview(L"dead_eyes.bgra");
      printfs(L"When you're bullying you.\n\r");
    } else if(user->favorability >= -50 && user->favorability < 50){
      imageview(L"default2.bgra");
      printfs(L"When I made a new discovery.\n\r");
    }else {
      imageview(L"big_smile.bgra");
      printfs(L"I'm happy when I get to know something new!\n\r");
      printfs(L"When are you happy?");
    }
    imageview(L"default.bgra");
  }
};
