#pragma once
#include "../User.cpp"
#include "../systemcall.cpp"

#define MAX_SET_AGE_NUMBER 2

static wchar_t set_age_keywords[MAX_SET_AGE_NUMBER][20] {
    L"set age",
    L"age"
};

struct Com_set_age {
    User* user;

    bool Com_set_age::check(wchar_t* com) {
        for (int i = 0; i < MAX_SET_AGE_NUMBER; i++) {
            if (strcmps(com, set_age_keywords[i])) {
                return true;
            }
        }
        return false;
    }

    void Com_set_age::prepare(User* user) {
        this->user = user;
    }

    void Com_set_age::execute() {
        printfs(L"Type your age\r\n");
        wchar_t input[10];
        scanfs(input);
        user->age = wtoi(input);
        printfs(L"You are young!!");
    }
};