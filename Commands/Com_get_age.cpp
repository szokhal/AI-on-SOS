#pragma once
#include "../User.cpp"
#include "../systemcall.cpp"

#define MAX_GET_AGE_NUMBER 1

static wchar_t get_age_keywords[MAX_GET_AGE_NUMBER][20] {
    L"get age"
};

struct Com_get_age {
    User* user;

    bool Com_get_age::check(wchar_t* com) {
        for (int i = 0; i < MAX_GET_AGE_NUMBER; i++) {
            if (strcmps(com, get_age_keywords[i])) {
                return true;
            }
        }
        return false;
    }

    void Com_get_age::prepare(User* user) {
        this->user = user;
    }

    void Com_get_age::execute() {
        printfs(L"You are ");

        wchar_t age[10] = L"";
        itow(user->age, age);
        printfs(age);

        printfs(L"\r\n");
    }
};