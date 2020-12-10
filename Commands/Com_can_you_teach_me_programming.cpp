#pragma once
#include "../User.cpp"
#include "../systemcall.cpp"

#define MAX_CANYOUTEACHMEPROGRAMMING_NUMBER 4

static wchar_t canyouteachmeprogramming_keywords[MAX_CANYOUTEACHMEPROGRAMMING_NUMBER][30] = {
    L"can you teach me programming",
    L"can you teach me programming?",
    L"Can you teach me programming",
    L"Can you teach me programming?"
};

struct Com_canyouteachmeprogramming {
    User * user;

    bool Com_canyouteachmeprogramming::check(wchar_t *com) {
        for (int i = 0; i < MAX_CANYOUTEACHMEPROGRAMMING_NUMBER; i++) {
          if (strcmps(com, canyouteachmeprogramming_keywords[i]))
            return true;
        }
        return false;
    }

    void Com_canyouteachmeprogramming::prepare(User * user) {
        this->user = user;
    }

    void Com_canyouteachmeprogramming::execute() {
        if(user->favorability < -50){
            imageview(L"depressed.bgra");
            printfs(L"Who the fuck do you think you are?");
            printfs(L"\r\n");
        } else {
            imageview(L"smile.bgra");
            printfs(L"No");
            printfs(L"\r\n");
            printfs(L"It is important to think and study for yourself, ");
            printfs(user->name);
            printfs(L"\r\n");
            user->favorability += 10;
        }
    }
;