#pragma once
#include "../User.cpp"
#include "../systemcall.cpp"

#define MAX_IWILLNOTSEEYOUFORAWHILE_NUMBER 4

static wchar_t iwillnotseeyouforawhile_keywords[MAX_IWILLNOTSEEYOUFORAWHILE_NUMBER][30] = {
    L"i will not see you for a while",
    L"i won't see you for a while",
    L"I will not see you for a while",
    L"I won't see you for a while"
};

struct Com_iwillnotseeyouforawhile {
    User * user;

    bool Com_iwillnotseeyouforawhile::check(wchar_t *com) {
        for (int i = 0; i < MAX_IWILLNOTSEEYOUFORAWHILE_NUMBER; i++) {
          if (strcmps(com, iwillnotseeyouforawhile_keywords[i]))
            return true;
        }
        return false;
    }

    void Com_iwillnotseeyouforawhile::prepare(User * user) {
        this->user = user;
    }

    void Com_iwillnotseeyouforawhile::execute() {
        if(user->favorability < -50){
            imageview(L"depressed.bgra");
            printfs(L"You don't have to come home again");
            printfs(L"\r\n");
            user->favorability += 5;
        } else {
            imageview(L"crying.bgra");
            printfs(L"Really?");
            printfs(L"\r\n");
            printfs(L"I can't help it, but come back as soon as possible");
            printfs(L"\r\n");
            user->favorability += 10;
        }
    }
};