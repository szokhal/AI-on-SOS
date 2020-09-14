#pragma once
#include "../User.cpp"
#include "../systemcall.cpp"

#define MAX_KEYWORD_NUMBER 20

struct Com_hello {
  wchar_t *keywords[MAX_KEYWORD_NUMBER];
  User user;

  void Com_hello::makeKeywordList() {
    keywords[0] = L"hello";
    keywords[1] = L"hi";
  }

  bool Com_hello::check(wchar_t *com) {
    for (int i = 0; i < MAX_KEYWORD_NUMBER; i++) {
      if (strcmps(com, keywords[i]))
        return true;
    }
    return false;
  }

  void Com_hello::prepare(User user) {
    this->user = user;
  }

  void Com_hello::execute() {
    printfs(L"hi ");
    printfs(user.name);
    printfs(L".\r\n");
  }
};
