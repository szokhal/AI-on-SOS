#pragma once
#include "../User.cpp"
#include "../systemcall.cpp"

#define MAX_EXIT_NUMBER 2

static wchar_t exit_keywords[MAX_EXIT_NUMBER][20] = {
    L"exit",
    L"good bye"
};

struct Com_exit {

    bool Com_exit::check(wchar_t *com) {
        for (int i = 0; i < MAX_EXIT_NUMBER; i++) {
            if (strcmps(com, exit_keywords[i]))
                return true;
        }
        return false;
    }

    void Com_exit::execute() {
        printfs(L"Good bye.\r\n");
    }
};