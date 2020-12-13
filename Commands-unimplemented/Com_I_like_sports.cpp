#pragma once
#inlcude <stdio.h>
#include "../User.cpp"
#include "../systemcall.cpp"

#define ILIKESPORTS 4

static wchar_t ILIKESPORTS_keywords[MAX_ILIKESPORTS_NUMBER][14] = {
	L"I like table tennis",
  L"I like base ball",
  L"I like basket ball",
  L"I like tennis"
};

struct Com_ILIKESPORTS {
  User * user;

  bool Com_ILIKESPORTS::check(wchar_t *com) {
    for (int i = 0; i < MAX_ILIKESPORTS_NUMBER; i++) {
      if (strcmps(com, ILIKESPORTS_keywords[i]))
        return true;
    }
    return false;
  }

  void Com_ILIKESPORTS::prepare(User * user) {
    this->user = user;
  }

  void Com_ILIKESPORTS::execute() {
    printfs(L"I also like it. I can't play it, but I enjoy watching it");
			user->favoravility += 10;
			imageview(L"big_smile.bgra");
		}
		imageview(L"default.bgra");
};
