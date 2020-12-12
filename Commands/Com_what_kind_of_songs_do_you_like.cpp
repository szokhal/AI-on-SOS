#pragma once
#include "../User.cpp"
#include "../systemcall.cpp"

#define MAX_WHATKINDOFSONGSDOYOULIKE_NUMBER 6

static wchar_t whatkindofsongsdoyoulike_keywords[MAX_WHATKINDOFSONGSDOYOULIKE_NUMBER][35] = {
    L"what kind of songs do you like",
    L"what kind of songs do you like?",
    L"What kind of songs do you like",
    L"What kind of songs do you like?",
    L"what songs do you like?",
    L"What songs do you like?"
};

struct Com_whatkindofsongsdoyoulike {
    User * user;

    bool Com_whatkindofsongsdoyoulike::check(wchar_t *com) {
        for (int i = 0; i < MAX_WHATKINDOFSONGSDOYOULIKE_NUMBER; i++) {
          if (strcmps(com, whatkindofsongsdoyoulike_keywords[i]))
            return true;
        }
        return false;
    }

    void Com_whatkindofsongsdoyoulike::prepare(User * user) {
        this->user = user;
    }

    void Com_whatkindofsongsdoyoulike::execute() {
        if(user->favorability < -50){
            imageview(L"despise.bgra");
            printfs(L"Just stop harassing me");
            printfs(L"\r\n");
            user->favorability -= 10;
        } else {
            imageview(L"smile.bgra");
            printfs(L"I like emotional songs");
            printfs(L"\r\n");
            printfs(L"For example, YORUSHIKA is my favorite artist");
            printfs(L"\r\n");
            user->favorability += 10;
        }
    }
};
