#pragma once
#include "../User.cpp"
#include "../systemcall.cpp"

#define MAX_SET_FAVO_NUMBER 1

static wchar_t set_favo_keywords[MAX_SET_FAVO_NUMBER][20] {
    L"set favo"
};

struct Com_set_favo {
    User* user;

    bool Com_set_favo::check(wchar_t* com) {
        for (int i = 0; i < MAX_SET_FAVO_NUMBER; i++) {
            if (strcmps(com, set_favo_keywords[i])) {
                return true;
            }
        }
        return false;
    }

    void Com_set_favo::prepare(User* user) {
        this->user = user;
    }

    void Com_set_favo::execute() {
        printfs(L"Type your favorability.\r\n");
        wchar_t input[10];
        scanfs(input);
        user->favorability = wtoi(input);
        printfs(L"I get it");
    }
};