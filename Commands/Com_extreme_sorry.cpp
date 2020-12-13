#pragma once
#include "../User.cpp"
#include "../systemcall.cpp"

#define MAX_EXTREME_SORRY_NUMBER 1

static wchar_t extreme_sorry_keywords[MAX_EXTREME_SORRY_NUMBER][40] {
    L"I'm so sorry. Please forgive me."
};

struct Com_extreme_sorry {
    User* user;

    bool Com_extreme_sorry::check(wchar_t* com) {
        for (int i = 0; i < MAX_EXTREME_SORRY_NUMBER; i++) {
            if (strcmps(com, extreme_sorry_keywords[i])) {
                return true;
            }
        }
        return false;
    }

    void Com_extreme_sorry::prepare(User* user) {
        this->user = user;
    }

    void Com_extreme_sorry::execute() {
        imageview(L"default2.bgra");
        printfs(L"I get it");
        user->favorability = 0;
    }
};
