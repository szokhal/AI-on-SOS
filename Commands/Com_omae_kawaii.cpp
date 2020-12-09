  #pragma once
#include "../User.cpp"
#include "../systemcall.cpp"

#define MAX_OMAE_KAWAII_NUMBER 2  // MAX_HELLO

static wchar_t omae_kawaii_keywords[OMAE_KAWAII_NUMBER][20] = { // ユーザー側が入力する言葉
  L"omae_kawaii",
  L"kawaii"
};

struct Com_omae_kawaii {
  User* user;
  bool* suki;

  bool Com_omae_kawaii::check(wchar_t *com) {
    for (int i = 0; i < MAX_OMAE_KAWAII_NUMBER; i++) {
      if (strcmps(com, omae_kawaii_keywords[i]))
        return true;
    }
    return false;
  }

  void Com_omae_kawaii::prepare(User* user, bool* suki) {
    this->user = user;
    this->suki = suki;
  }

  void Com_omae_kawaii::execute() { //main
    printfs(L"Arigato ");
    // 画像変更入れたい
    bool = true;    
    printfs(user->name);
    printfs(L"!.\r\n");
  }
};