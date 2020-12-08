#pragma once
#include "../User.cpp"
#include "../systemcall.cpp"

#define MAX_HELLO_NUMBER 2

static wchar_t hello_keywords[MAX_HELLO_NUMBER][20] = {
  L"hello",
  L"hi"
};

struct Com_hello {
  User* user;

  bool Com_hello::check(wchar_t *com) {
    for (int i = 0; i < MAX_HELLO_NUMBER; i++) {
      if (strcmps(com, hello_keywords[i]))
        return true;
    }
    return false;
  }

  void Com_hello::prepare(User* user) {
    this->user = user;
  }

  void Com_hello::execute() {
    printfs(L"hi ");
    printfs(user->name);
    printfs(L".\r\n");
  }
};
