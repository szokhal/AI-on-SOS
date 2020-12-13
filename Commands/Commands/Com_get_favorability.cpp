#pragma once
#include "../User.cpp"
#include "../systemcall.cpp"

#define MAX_GET_FAVO_NUMBER 1

static wchar_t get_favo_keywords[MAX_GET_FAVO_NUMBER][20] {
    L"get favo"
};

struct Com_get_favo {
    User* user;

    bool Com_get_favo::check(wchar_t* com) {
        for (int i = 0; i < MAX_GET_FAVO_NUMBER; i++) {
            if (strcmps(com, get_favo_keywords[i])) {
                return true;
            }
        }
        return false;
    }

    void Com_get_favo::prepare(User* user) {
        this->user = user;
    }

    void Com_get_favo::execute() {
        printfs(L"Your favorability is ");

        wchar_t favo[10] = L"";
        itow(user->favorability, favo);
        printfs(favo);

        printfs(L"\r\n");
    }
};