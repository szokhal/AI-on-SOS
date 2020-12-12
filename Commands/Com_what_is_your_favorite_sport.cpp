#pragma once
#include "../User.cpp"
#include "../systemcall.cpp"

#define MAX_WHATISYOURFAVORITESPORT_NUMBER 4

static wchar_t whatisyourfavoritesport_keywords[MAX_WHATISYOURFAVORITESPORT_NUMBER][30] = {
    L"what is your favorite sport",
    L"what is your favorite sport?",
    L"What is your favorite sport",
    L"What is your favorite sport?"
};

struct Com_whatisyourfavoritesport {
    User * user;

    bool Com_whatisyourfavoritesport::check(wchar_t *com) {
        for (int i = 0; i < MAX_WHATISYOURFAVORITESPORT_NUMBER; i++) {
          if (strcmps(com, whatisyourfavoritesport_keywords[i]))
            return true;
        }
        return false;
    }

    void Com_whatisyourfavoritesport::prepare(User * user) {
       this->user = user;
    }

    void Com_whatisyourfavoritesport::execute() {
        if(user->favorability < -50){
            imageview(L"despise.bgra");
            printfs(L"No worth for me to talk");
            printfs(L"\r\n");
        } else if(user->favorability < 50){
            imageview(L"default.bgra");
            printfs(L"I like to watch sports in any event");
            printfs(L"\r\n");
            user->favorability += 10;
        } else {
            imageview(L"smile.bgra");
            printfs(L"I like to watch sports in any event");
            printfs(L"\r\n");
            printfs(L"I want to try esports");
            user->favorability += 10;
        }
    }
};
