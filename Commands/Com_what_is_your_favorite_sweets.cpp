#pragma once
#include "../User.cpp"
#include "../systemcall.cpp"

#define MAX_WHATISYOURFAVORITESWEETS_NUMBER 4

static wchar_t whatisyourfavoritesweets_keywords[MAX_WHATISYOURFAVORITESWEETS_NUMBER][30] = {
    L"what is your favorite sweets",
    L"what is your favorite sweets?",
    L"What is your favorite sweets",
    L"What is your favorite sweets?"
};

struct Com_whatisyourfavoritesweets {
    User * user;

    bool Com_whatisyourfavoritesweets::check(wchar_t *com) {
        for (int i = 0; i < MAX_WHATISYOURFAVORITESWEETS_NUMBER; i++) {
          if (strcmps(com, whatisyourfavoritesweets_keywords[i]))
            return true;
        }
        return fals;
    }

    void Com_whatisyourfavoritesweets::prepare(User * user) {
       this->user = user;
    }

    void Com_whatisyourfavoritesweets::execute() {
        if(user->favorability < -50){
            imageview(L"depressed.bgra");
            printfs(L"I don't want to tell you");
            printfs(L"\r\n");
        } else if(user->favorability < 50){
            imageview(L"smile.bgra");
            printfs(L"I like sweet potatoes");
            printfs(L"\r\n");
            user->favorability += 10;
        } else {
            imageview(L"big_smile.bgra");
            printfs(L"I like sweet potatoes!");
            printfs(L"\r\n");
            printfs(L"Sweet treats are my favorite!")
            user->favorability += 10;
        }
    }
};