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
    User * user;

    bool Com_howareyou::check(wchar_t *com) {
        for (int i = 0; i < MAX_HELLO_NUMBER; i++) {
            if (strcmps(com, howareyou_keywords[i]))
                return true;
        }
        return false;
    }

    void Com_howareyou::prepare(User * user) {
        this->user = user;
    }

    void Com_howareyou::execute() {
        if(user->favoravirity < -50){
            printfs(L"Don't talk me.");
            printfs(L"\r\n");
        } else if(user->favoravirity >= -50 && user->facoravirity < 50){
            printfs(L"I'm fine thank you ");
            printfs(user->name);
            printfs(L".\r\n");
        } else {
            printfs(L"I'm fine thank you ");
            printfs(user->name);
            printfs(L" and you? \r\n");
            if(compare(L"i'm fine thank you") || compare(L"me too")){
                printfs(L"Oh yeah.\r\n");
            } else {
                printfs(L"Really? Take care of yourself.");
            }
        }
    }
}