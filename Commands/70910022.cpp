#pragma once
#include "../User.cpp"
#include "systemcall.cpp"
#define MAX_KEYWORD_NUMBER 20

struct Com_how_are_you{
    wchar_t *keywords[MAX_KEYWORD_NUMBER];
    
    User* user;

    void Com_how_are_you::makeKeywordList() {
        keywords[0] = L"how are you?";
        keywords[1] = L"how are you";
        keywords[2] = L"how do you feel today?" 
        keywords[3] = L"how do you feel today"
    }

    bool Com_how_are_you::check(wchar_t *com) {
    for (int i = 0; i < MAX_KEYWORD_NUMBER; i++) {
      if (strcmps(com, keywords[i]))
        return true;
    }
    return false;
  }

  void Com_how_are_you::prepare(User* user) {
    this->user = user;
  }

  void Com_how_are_you::execute() {
    printf(L"I'm good");
    printf(L".\r\n");
  }
};
