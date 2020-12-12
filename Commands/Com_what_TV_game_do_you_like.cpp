#pragma once
#include "../User.cpp"
#include "../systemcall.cpp"

#define MAX_WHATTVGAMEDOYOULIKE_NUMBER 8

static wchar_t whatTVgamedoyoulike_keywords[MAX_WHATTVGAMEDOYOULIKE_NUMBER][30] = {
    L"what TV game do you like",
    L"what TV game do you like?",
    L"what tv game do you like",
    L"what tv game do you like?",
    L"What TV game do you like",
    L"What TV game do you like?",
    L"What tv game do you like",
    L"What tv game do you like?"
};

struct Com_whatTVgamedoyoulike {
   User * user;

    bool Com_whatTVgamedoyoulike::check(wchar_t *com) {
        for (int i = 0; i < MAX_WHATTVGAMEDOYOULIKE_NUMBER; i++) {
          if (strcmps(com, whatTVgamedoyoulike_keywords[i]))
            return true;
        }
        return false;
    }

    void Com_whatTVgamedoyoulike::prepare(User * user) {
        this->user = user;
    }

    void Com_whatTVgamedoyoulike::execute() {
        if(user->favorability < -50) {
            imageview(L"jitome.bgra");
            printfs(L"Why do I have to tell you that?");
            printfs(L"\r\n");
        } else if(user->favorability < 50) {
            imageview(L"default.bgra");
            printfs(L"I like Pikmin.");
            printfs(L"\r\n");
        } else {
            imageview(L"smile.bgra");
            printfs(L"I like Pikmin");
            printfs(L"\r\n");
            printfs(L"Pikmins are so cute!!");
            printfs(L"\r\n");
        }
        user->favorability += 10;
    }
};
