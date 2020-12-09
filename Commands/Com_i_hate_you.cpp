#pragma once
#include "../User.cpp"
#include "../systemcall.cpp"

#define MAX_IHATEYOU_NUMBER 4

static wchar_t ihateyou_keywords[MAX_IHATEYOU_NUMBER][25] = {
  L"i hate you",
  L"i hate you!",
  L"I hate you",
  L"I hate you!"
};

struct Com_ihateyou {
  User * user;

  bool Com_ihateyou::check(wchar_t *com) {
    for (int i = 0; i < MAX_IHATEYOU_NUMBER; i++) {
      if (strcmps(com, ihateyou_keywords[i]))
        return true;
    }
    return false;
  }

  void Com_ihateyou::prepare(User * user) {
    this->user = user;
  }

  void Com_ihateyou::execute() {
    if(user->favoravility < 0){
        imageview(L"jitome.bgra");
        printfs(L"Sorry coffee break, and?");
        printfs(L"\r\n");
        user->favoravility -= 10;
    } else if(user->favoravility < 50){
        imageview(L"surprise.bgra");
        printfs(L"....What?");
        printfs(L"\r\n");
        user->favoravility -= 20;
    } else {
        imageview(L"crying.bgra");
        printfs(L"Why would you say that...?");
        printfs(L"\r\n");
        user->favoravility -= 10;
    }
  }
};