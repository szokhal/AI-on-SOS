#pragma once
#include "../User.cpp"
#include "../systemcall.cpp"

#define MAX_OK_GOOGLE_NUMBER 3

static wchar_t ok_google_keywords[MAX_OK_GOOGLE_NUMBER][20] {
    L"ok google",
    L"hey siri",
    L"alexa"
};

struct Com_ok_google {
    User* user;

    bool Com_ok_google::check(wchar_t* com) {
        for (int i = 0; i < MAX_OK_GOOGLE_NUMBER; i++) {
            if (strcmps(com, ok_google_keywords[i])) {
                return true;
            }
        }
    }

    void Com_ok_google::prepare(User* user) {
        this->user = user;
    }

    void Com_ok_google::execute() {
        printfs(L"Who's that woman!!\r\n");
        user->favorability -= 30;
    }
};