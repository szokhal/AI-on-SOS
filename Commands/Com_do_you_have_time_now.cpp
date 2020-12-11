#pragma once
#include "../User.cpp"
#include "../systemcall.cpp"

#define MAX_FREE_NUMBER 5

static wchar_t doyouhavetimenow_keywords[MAX_FREE_NUMBER][24] = {
	L"Are you free now",
    L"Do you have time now",
    L"free?",
    L"are you free now",
	L"Are you OK now?"
};

struct Com_doyouhavetimenow {
    User * user;

    bool Com_doyouhavetimenow::check(wchar_t *com) {
        for (int i = 0; i < MAX_FREE_NUMBER; i++) {
            if (strcmps(com, doyouhavetimenow_keywords[i]))
                return true;
        }
        return false;
    }

    void Com_doyouhavetimenow::prepare(User * user) {
        this->user = user;
    }

    void Com_doyouhavetimenow::execute() {
        if(user->favorability < -50){
            printfs(L"I'm busy.");
		    printfs(L"I'm so tired");
            printfs(L"\r\n");
        } else if(user->favorability >= -50 && user->favorability < 50){
            printfs(L"Yes, I'm free now.");
            printfs(user->name);
            printfs(L".\r\n");
        } else {
            printfs(L"I'm free!");
            printfs(user->name);
            printfs(L" Let's talk!! \r\n");
            if(compare(L"Well, it's nothing")||compare(L"Well, forget it")){
                printfs(L"It is a pity\r\n");
            } else{
				printfs(L"I'm glad to tallking with you!");
			}
        }
    }
};
