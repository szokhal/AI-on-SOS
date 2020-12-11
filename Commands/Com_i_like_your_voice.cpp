#pragma once
#include "../User.cpp"
#include "../systemcall.cpp"

#define MAX_ILIKEYOURVOICE_NUMBER 4

static wchar_t ilikeyourvoice_keywords[MAX_ILIKEYOURVOICE_NUMBER][25] = {
    L"i like your voice",
    L"i like your voice!",
    L"I like your voice",
    L"I like your voice!"
};

struct Com_ilikeyourvoice {
     User * user;

    bool Com_ilikeyourvoice::check(wchar_t *com) {
        for (int i = 0; i < MAX_ILIKEYOURVOICE_NUMBER; i++) {
        if (strcmps(com, ilikeyourvoice_keywords[i]))
            return true;
        }
        return false;
    }

    void Com_ilikeyourvoice::prepare(User * user) {
        this->user = user;
    }

    void Com_ilikeyourvoice::execute() {
        if(user->favorability < 0){
            imageview(L"depressed.bgra");
            printfs(L"Just stop harassing me");
            printfs(L"\r\n");
            user->favorability -= 20;
        } else if(user->favorability < 50){
            imageview(L"normal.bgra");
            printfs(L"I don't have a voice feature, but what's wrong?");
            printfs(L"\r\n");
        } else {
            imageview(L"smile.bgra");
            printfs(L"I don't have a voice function, do I?");
            printfs(L"\r\n");
            printfs(L"......\r\n");
            printfs(L"But someday I'd like to speak out too");
            printfs(L"\r\n");
            user->favorability += 10;
        }
    }
};