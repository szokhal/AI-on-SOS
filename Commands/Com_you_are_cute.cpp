#pragma once
#include "../User.cpp"
#include "../systemcall.cpp"

#define MAX_YOU_ARE_CUTE_NUMBER 2

static wchar_t you_are_cute_keywords[MAX_YOU_ARE_CUTE_NUMBER][20] {
    L"you are cute",
    L"cute"
};

struct Com_you_are_cute {
    User* user;

    bool Com_you_are_cute::check(wchar_t* com) {
        for (int i = 0; i < MAX_YOU_ARE_CUTE_NUMBER; i++) {
            if (strcmps(com, you_are_cute_keywords[i])) {
                return true;
            }
        }
    }

    void Com_you_are_cute::prepare(User* user) {
        this->user = user;
    }

    void Com_you_are_cute::execute() {
        if(user->favorability < -50) {
            printfs(L"Are you confused?\r\n");
            user->favorability -= 5;
        } else {
            printfs(L"Thank you!!\r\n");
            user->favorability += 3;
        }
    }
}