#pragma once
#include "../User.cpp"
#include "../systemcall.cpp"

#define MAX_OMAE_KAWAII_NUMBER 2  // MAX_HELLO

static wchar_t omae_kawaii_keywords[MAX_OMAE_KAWAII_NUMBER][20] = {
  L"omae kawaii",
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
    imageview(L"love.bgra");
    printfs(L"Arigato ");
    *suki = true;    
    printfs(user->name);
    printfs(L"!.\r\n");
  }
};
