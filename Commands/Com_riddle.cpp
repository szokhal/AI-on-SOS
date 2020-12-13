#pragma once
#include "../User.cpp"
#include "../systemcall.cpp"

#define MAX_RIDDLE_NUMBER 4

static wchar_t riddle_keyword[MAX_RIDDLE_NUMBER][30] = {
  L"riddle",
  L"Riddle",
  L"nazonazo",
  L"give me riddle"
};

struct Com_riddle {
  User user;

  bool Com_riddle::check(wchar_t *com) {
    for (int i = 0; i < MAX_RIDDLE_NUMBER; i++) {
      if (strcmps(com, riddle_keywords[i]))
        return true;
    }
    return false;
  }

  void Com_riddle::prepare(User user) {
    this->user = user;
  }

  void Com_riddle::execute() {
    if(user->favorability < -50){
      printfs(L"During what month do people sleep the least?\n\r");
      user->favorability += 20; 
    } else if(user->favorability >= -50 && user->facoravility < 50){
      printfs(L" What is the center of gravity?\n\r");
      user->favorability += 20; 
    }else {
      printfs(L" What has to be broken before you can use it?\n\r");
      user->favorability += 20; 
    }
    imageview(L"default.bgra");
  }
};
