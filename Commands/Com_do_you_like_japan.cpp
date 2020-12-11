#pragma once
#include "../User.cpp"
#include "../systemcall.cpp"

#define MAX_DOYOULIKEJAPAN_NUMBER 8

static wchar_t doyoulikejapan_keywords[MAX_DOYOULIKEJAPAN_NUMBER][20] = {
    L"do you like japan",
    L"do you like japan?",
    L"Do you like japan",
    L"Do you like japan?",
    L"do you like Japan",
    L"do you like Japan?",
    L"Do you like Japan",
    L"Do you like Japan?"
};

struct Com_doyoulikejapan {
    User * user;

    bool Com_doyoulikejapan::check(wchar_t *com) {
        for (int i = 0; i < MAX_DOYOULIKEJAPAN_NUMBER; i++) {
          if (strcmps(com, doyoulikejapan_keywords[i]))
            return true;
        }
        return false;
    }

    void Com_doyoulikejapan::prepare(User * user) {
        this->user = user;
    }

    void Com_doyoulikejapan::execute() {
        if(user->favorability < -50){
            imageview(L"depressed.bgra");
            printfs(L"I don't know the country");
            printfs(L"\r\n");
        } else {
            imageview(L"smile.bgra");
            printfs(L"Is that the country ");
            printfs(user->name);
            printfs(L" live in?");
            printfs(L"\r\n");
            printfs(L"I don't know the country");
            printfs(L"But I'm sure I'll love it in the country where you live ");
            printfs(L"\r\n");
            user->favorability += 10;
        }
    }
};