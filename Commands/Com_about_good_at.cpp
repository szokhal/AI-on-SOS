#pragma once
#include "../User.cpp"
#include "../systemcall.cpp"

#define MAX_ABOUT_GOOD_AT_NUMBER 3

static wchar_t about_good_at_keyword[MAX_ABOUT_GOOD_AT_NUMBER][30] = {
  L"What is it you're good at?",
  L"What is it you're good at",
  L"about you're good at"
};

struct Com_about_good_at {
  User user;

  bool Com_about_good_at::check(wchar_t *com) {
    for (int i = 0; i < MAX_ABOUT_GOOD_AT_NUMBER; i++) {
      if (strcmps(com, about_good_at_keywords[i]))
        return true;
    }
    return false;
  }

  void Com_about_good_at::prepare(User user) {
    this->user = user;
  }

  void Com_about_good_at::execute() {
    if(user->favorability < -50){
      imageview(L"jotome.bgra");
      printfs(L"I have nothing to talk with you.\\n\r");
    } else if(user->favorability >= -50 && user->favorability < 50){
      imageview(L"default2.bgra");
      printfs(L"I'm good at talking to people.\n\r");
    }else {
      imageview(L"love.bgra");
      printfs(L"I'm good at talking to people.\n\r");
      printfs(L"Please talk to me a lot.\n\r");
    }
  }
};

