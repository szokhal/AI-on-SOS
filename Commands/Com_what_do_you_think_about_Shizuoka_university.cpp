#pragma once
#inlcude <stdio.h>
#include "../User.cpp"
#include "../systemcall.cpp"

#define WHATDOYOUTHINKABOUTSHIZUOKAUNIVERSITY 1

static wchar_t WHATDOYOUTHINKABOUTSHIZUOKAUNIVERSITY_keywords[MAX_WHATDOYOUTHINKABOUTSHIZUOKAUNIVERSITY_NUMBER][14] = {
	L"what do you think abou Shizuoka university"
};

struct Com_WHATDOYOUTHINKABOUTSHIZUOKAUNIVERSITY {
  User * user;

  bool Com_WHATDOYOUTHINKABOUTSHIZUOKAUNIVERSITY::check(wchar_t *com) {
    for (int i = 0; i < MAX_WHATDOYOUTHINKABOUTSHIZUOKAUNIVERSITY_NUMBER; i++) {
      if (strcmps(com, WHATDOYOUTHINKABOUTSHIZUOKAUNIVERSITY_keywords[i]))
        return true;
    }
    return false;
  }

  void Com_WHATDOYOUTHINKABOUTSHIZUOKAUNIVERSITY::prepare(User * user) {
    this->user = user;
  }

  void Com_WHATDOYOUTHINKABOUTSHIZUOKAUNIVERSITY::execute() {
    if(user->favoravility < 0){
        printfs(L"I think it's a university that seems inconvenient because it's far from the station.");
        printfs(L"\r\n");
				imageview(L"depressed.bgra");
			}else{
				printfs(L"I think it's a very nice university.");
				printfs(L"\r\n");
				imageview(L"big_smile.bgra");
			}
			user->favoravility += 10;
		}
		imageview(L"default.bgra");
};
