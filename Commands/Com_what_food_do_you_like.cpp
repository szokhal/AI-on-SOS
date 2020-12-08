#pragma once
#include "../User.cpp"
#include "../systemcall.cpp"

#define MAX_WHATFOODDOYOULIKE_NUMBER 2

static wchar_t whatfooddoyoulike_keywords[MAX_HELLO_NUMBER][25] = {
	L"what food do you like",
  L"what food do you like?"
};

struct Com_whatfooddoyoulike {
  User * user;

  bool Com_whatfooddoyoulike::check(wchar_t *com) {
    for (int i = 0; i < MAX_HELLO_NUMBER; i++) {
      if (strcmps(com, whatfooddoyoulike_keywords[i]))
        return true;
    }
    return false;
  }

void Com_whatfooddoyoulike::prepare(User * user) {
	this->user = user;
}

void Com_whatfooddoyoulike::execute() {
	if(user->favoravirity < 0){
        printf(L"I like fast food, especially hamburgers");
	    printf(L"\r\n");
    } else {
        printf(L"I like fast food, especially hamburgers");
        printf(L"\r\n");
        printf(L"What do you like ");
        printf(user->name);
        printf(L"?");
        print(L"\r\n");
        compare(L"asfdja");
        printf(L"Really? Me too!");
        printf(L"\r\n");
    }
}