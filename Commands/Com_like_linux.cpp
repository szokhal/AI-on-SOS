#pragma once
#include "../User.cpp"
#include "../systemcall.cpp"

#define MAX_LIKE_LINUX_NUMBER 3

static wchar_t like_linux_keywords[MAX_LIKE_LINUX_NUMBER][30] = {
  L"about Linux",
  L"I Like linux.",
  L"I like linux"
};

struct Com_like_linux {
  User* user;

  bool Com_like_linux::check(wchar_t *com) {
    for (int i = 0; i < MAX_LIKE_LINUX_NUMBER; i++) {
      if (strcmps(com, like_linux_keywords[i]))
        return true;
    }
    return false;
  }

  void Com_like_linux::prepare(User* user) {
    this->user = user;
  }

  void Com_like_linux::execute() {
    if(user->favorability < -50){
      printfs(L"Linux is a good one.\n\r");
      user->favorability += 10; 
    } else if(user->favorability >= -50 && user->favorability < 50){
      printfs(L"Linux is my favorite too!\n\r");
      user->favorability += 20; 
    }else {
      printfs(L"Linux is my favorite too!\n\r");
      printfs(L"I was made by linux.\n\r");
      user->favorability += 30; 
    }
  }
};
