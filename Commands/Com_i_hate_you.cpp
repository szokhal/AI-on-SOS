#pragma once
#include "../User.cpp"
#include "../systemcall.cpp"

#define MAX_IHATEYOU_NUMBER 4

static wchar_t ihateyou_keywords[MAX_IHATEYOU_NUMBER][25] = {
    L"i hate you",
    L"i hate you!",
    L"I hate you",
    L"I hate you!"
};

struct Com_ihateyou {
    User * user;

    bool Com_ihateyou::check(wchar_t *com) {
        for (int i = 0; i < MAX_IHATEYOU_NUMBER; i++) {
        if (strcmps(com, ihateyou_keywords[i]))
            return true;
        }
        return false;
    }

    void Com_ihateyou::prepare(User * user) {
        this->user = user;
    }

    void Com_ihateyou::execute() {
        if(user->favorability < 0){
            imageview(L"jitome.bgra");
            printfs(L"Sorry coffee break, and?");
            printfs(L"\r\n");
            user->favorability -= 10;
        } else if(user->favorability < 50){
            imageview(L"despise.bgra");
            printfs(L"....What?");
            printfs(L"\r\n");
            user->favorability -= 20;
        } else {
            imageview(L"crying.bgra");
            printfs(L"Why would you say that...?");
            printfs(L"\r\n");
            user->favorability -= 10;
        }
    }
};
