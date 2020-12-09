#pragma once
#include "../User.cpp"
#include "../systemcall.cpp"

#define MAX_WHEREDOYOUWANTTOGO_NUMBER 4

static wchar_t wheredoyouwanttogo_keywords[MAX_WHEREDOYOUWANTTOGO_NUMBER][25] = {
    L"where do you want to go",
    L"where do you want to go?",
    L"Where do you want to go",
    L"Where do you want to go?"
};

struct Com_wheredoyouwanttogo {
    User * user;

    bool Com_wheredoyouwanttogo::check(wchar_t *com) {
        for (int i = 0; i < MAX_WHEREDOYOUWANTTOGO_NUMBER; i++) {
        if (strcmps(com, wheredoyouwanttogo_keywords[i]))
            return true;
        }
        return false;
    }

    void Com_wheredoyouwanttogo::prepare(User * user) {
        this->user = user;
    }

    void Com_wheredoyouwanttogo::execute() {
        if(user->favorability < 0){
            imageview(L"depressed.bgra");
            printfs(L"Wherever you're not");
            printfs(L"\r\n");
            user->favorability -= 10;
        } else if(user->favorability < 50){
            imageview(L"normal.bgra");
            printfs(L"I want to go to sea");
            printfs(L"\r\n");
            user->favorability += 10;
        } else {
            imageview(L"smile.bgra");
            printfs(L"I want to go to sea!");
            printfs(L"\r\n");
            printfs(L"I want to go to see the sea together ");
            printfs(user->name);
            printfs(L"\r\n");
            if(compare(L"Yes") || compare(L"Me too")){
                printfs(L"I'm glad!!");
                user->favorability += 20;
            } else {
                user->favorability += 10;
            }
        }
    }
};