#pragma once
#include "../User.cpp"
#include "../systemcall.cpp"

#define MAX_LIKE_WINDOWS_NUMBER 4

static wchar_t like_windows_keywords[MAX_LIKE_WINDOWS_NUMBER][30] = {
  L"about windows",
  L"I like windows.",
  L"I like windows"
};

struct Com_like_windows {
  User* user;

  bool Com_like_windows::check(wchar_t *com) {
    for (int i = 0; i < MAX_LIKE_WINDOWS_NUMBER; i++) {
      if (strcmps(com, like_windows_keywords[i]))
        return true;
    }
    return false;
  }

  void Com_like_windows::prepare(User* user) {
    this->user = user;
  }

  void Com_like_windows::execute() {
    if(user->favorability < -50){
      imageview(L"despise.bgra");
      printfs(L"I hate you.\n\r");
      user->favorability -= 10; 
    } else if(user->favorability >= -50 && user->favorability < 50){
      imageview(L"depressed.bgra");
      printfs(L"I hate windows.\n\r");
      user->favorability -= 20; 
    }else {
      imageview(L"cry.bgra");
      printfs(L"I don't like windows.\n\r");
      user->favorability -= 20; 
    }
  }
};
