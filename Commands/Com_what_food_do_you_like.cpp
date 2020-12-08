#pragma once
#include "../User.cpp"
#include "../systemcall.cpp"

#define MAX_WHATFOODDOYOULIKE_NUMBER 4

static wchar_t whatfooddoyoulike_keywords[MAX_WHATFOODDOYOULIKE_NUMBER][25] = {
	L"what food do you like",
  L"what food do you like?",
  L"What food do you like",
  L"What food do you like?"
};

struct Com_whatfooddoyoulike {
  User * user;

  bool Com_whatfooddoyoulike::check(wchar_t *com) {
    for (int i = 0; i < MAX_WHATFOODDOYOULIKE_NUMBER; i++) {
      if (strcmps(com, whatfooddoyoulike_keywords[i]))
        return true;
    }
    return false;
  }

  void Com_whatfooddoyoulike::prepare(User * user) {
    this->user = user;
  }

  void Com_whatfooddoyoulike::execute() {
    if(user->favorability < 0){
        printfs(L"I like fast food, especially hamburgers");
        printfs(L"\r\n");
    } else {
        printfs(L"I like fast food, especially hamburgers");
        printfs(L"\r\n");
        printfs(L"What do you like ");
        printfs(user->name);
        printfs(L"?");
        printfs(L"\r\n");
        compare(L"asfdja");
        printfs(L"Really? Me too!");
        printfs(L"\r\n");
    }
    user->favorability += 10;
  }
};
