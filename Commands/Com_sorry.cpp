#pragma once
#include "../User.cpp"
#include "../systemcall.cpp"

#define MAX_SORRY_NUMBER 6

static wchar_t sorry_keywords[MAX_SORRY_NUMBER][20] {
    L"I'm sorry",
    L"i'm sorry",
    L"I'm sorry.",
    L"i'm sorry.",
    L"sorry",
    L"sorry."
};

struct Com_sorry {
    User* user;

    bool Com_sorry::check(wchar_t* com) {
        for (int i = 0; i < MAX_SORRY_NUMBER; i++) {
            if (strcmps(com, sorry_keywords[i])) {
                return true;
            }
        }
        return false;
    }

    void Com_sorry::prepare(User* user) {
        this->user = user;
    }

    void Com_sorry::execute() {
        if (user->favorability < 50) {
            printfs(L"Stop crying, I can't believe what a wimp you are.");
            user->favorability += 10;
        } else {
            printfs(L"It's not your fault");
        }
    }
};