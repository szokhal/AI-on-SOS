#pragma once
#include "../User.cpp"
#include "../systemcall.cpp"

#define MAX_SET_NAME_NUMBER 2

static wchar_t set_name_keywords[MAX_SET_NAME_NUMBER][20] {
    L"set name",
    L"name"
};

struct Com_set_name {
    User* user;

    bool Com_set_name::check(wchar_t* com) {
        for (int i = 0; i < MAX_SET_NAME_NUMBER; i++) {
            if (strcmps(com, set_name_keywords[i])) {
                return true;
            }
        }
        return false;
    }

    void Com_set_name::prepare(User* user) {
        this->user = user;
    }

    void Com_set_name::execute() {
        printfs(L"Please type your name.\r\n");
        fillNUll(user->name, 35);
        scanfs(user->name);
        printfs(L"Good name ");
        printfs(user->name);
        printfs(L"\r\n");
    }
};