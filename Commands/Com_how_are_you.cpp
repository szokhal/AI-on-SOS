#pragma once
#include "../User.cpp"
#include "../systemcall.cpp"

#define MAX_HOWAREYOU_NUMBER 4

static wchar_t howareyou_keywords[MAX_HELLO_NUMBER][20] = {{
	L"how are you",
    L"how are you?",
    L"how are you today",
    L"how are you today?"
};

struct Com_howareyou {
    User user;

    bool Com_howareyou::check(wchar_t *com) {
        for (int i = 0; i < MAX_HELLO_NUMBER; i++) {
            if (strcmps(com, howareyou_keywords[i]))
                return true;
        }
        return false;
    }

    void Com_howareyou::prepare(User user) {
        this->user = user;
    }

    void Com_howareyou::execute() {
        if(user->favoravirity < -50){
            printf(L"Don't talk me.");
            printf(L"\r\n");
        } else if(user.favoravirity >= -50 && user.facoravirity < 50){
            printf(L"I'm fine thank you ");
            printf(user.name);
            print(L".\r\n");
        } else {
            printf(L"I'm fine thank you ");
            printf(user.name);
            printf(L" and you? \r\n");
            if(compare(L"i'm fine thank you") || compare(L"me too")){
                printf(L"Oh yeah.\r\n");
            } else {
                printf(L"Really? Take care of yourself.");
            }
        }
    }
}