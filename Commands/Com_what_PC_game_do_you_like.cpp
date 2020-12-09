#pragma once
#include "../User.cpp"
#include "../systemcall.cpp"

#define MAX_WHATPCGAMEDOYOULIKE_NUMBER 8

static wchar_t whatPCgamedoyoulike_keywords[MAX_WHATPCGAMEDOYOULIKE_NUMBER][30] = {
    L"what PC game do you like",
    L"what PC game do you like?",
    L"what pc game do you like",
    L"what pc game do you like?",
    L"What PC game do you like",
    L"What PC game do you like?",
    L"What pc game do you like",
    L"What pc game do you like?"
};

struct Com_whatPCgamedoyoulike {
    User * user;

    bool Com_whatPCgamedoyoulike::check(wchar_t *com) {
        for (int i = 0; i < MAX_WHATPCGAMEDOYOULIKE_NUMBER; i++) {
          if (strcmps(com, whatPCgamedoyoulike_keywords[i]))
            return true;
        }
        return false;
    }

    void Com_whatPCgamedoyoulike::prepare(User * user) {
       this->user = user;
    }

    void Com_whatPCgamedoyoulike::execute() {
        if(user->favoravility < -50) {
            imageview(L"jitome.bgra");
            printfs(L"Why do I have to tell you that?");
            printfs(L"\r\n");
        } else if(user->favoravility < 50) {
            imageview(L"normal.bgra");
            printfs(L"I like Dead by Daylight.");
            printfs(L"\r\n");
        } else {
            imageview(L"smile.bgra");
            printfs(L"I like Dead by Daylight!");
            printfs(L"\r\n");
            printfs(L"It's so exciting!!");
            printfs(L"\r\n");
        }
        user->favoravility += 10;
    }
};
