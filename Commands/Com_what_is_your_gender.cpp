#pragma once
#include "../User.cpp"
#include "../systemcall.cpp"

#define MAX_GENDER_NUMBER 5

static wchar_t whatisyourgender_keywords[MAX_GENDER_NUMBER][24] = {
	L"What is your gender",
    L"What is your gender?",
    L"Are you male?",
    L"Are you female?",
	L"male or female"
};

struct Com_whatisyourgender {
    User * user;

    bool Com_whatisyourgender::check(wchar_t *com) {
        for (int i = 0; i < MAX_GENDER_NUMBER; i++) {
            if (strcmps(com, whatisyourgender_keywords[i]))
                return true;
        }
        return false;
    }

    void Com_whatisyourgender::prepare(User * user) {
        this->user = user;
    }

    void Com_whatisyourgender::execute() {
        if(user->favorability < -50){
            printfs(L"Either gender is fine with me.");
            printfs(L"\r\n");
        } else if(user->favorability >= -50 && user->favorability < 50){
            printfs(L"I'm woman.");
            printfs(user->name);
            printfs(L".\r\n");
        } else {
            printfs(L"I am a beautiful woman");
            printfs(user->name);
            printfs(L" How about you \r\n");
            if (compare(L"woman")) {
                printfs(L"Let's be friends\r\n");
            } else {
                printfs(L"I see");
            }
        }
    }
};
