#pragma once
#include "../User.cpp"
#include "../systemcall.cpp"

#define MAX_UNIVERSITY_NUMBER 3

static wchar_t university_keywords[MAX_UNIVERSITY_NUMBER][48] = {
  L"about university",
  L"university",
  L"Which university do you belong to?"
};

struct Com_university {
  User* user;

  bool Com_university::check(wchar_t *com) {
    for (int i = 0; i < MAX_UNIVERSITY_NUMBER; i++) {
      if (strcmps(com, university_keywords[i]))
        return true;
    }
    return false;
  }

  void Com_university::prepare(User* user) {
    this->user = user;
  }

  void Com_university::execute() {
    if(user->favorability < -50){
      imageview(L"dead_eyes.bgra");
      printfs(L"I'm nothing to say to you.\n\r");
    } else if(user->favorability >= -50 && user->favorability < 50){
      imageview(L"smile.bgra");
      printfs(L"I belong to Shizuoka University.\n\r");
      user->favorability += 10; 
    }else {
      imageview(L"love.bgra");
      printfs(L"I belong to Shizuoka University.\n\r");
      printfs(L"I'm made as a college assignment.\n\r");
      user->favorability += 10; 
    }
    imageview(L"default.bgra");
  }
};
