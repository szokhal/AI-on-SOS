#pragma once
#include "../User.cpp"
#include "../systemcall.cpp"

#define MAX_PLACE_NUMBER 4

static wchar_t wheredoyoulive_keywords[MAX_PLACE_NUMBER][24] = {
	L"Where do you live",
    L"Are you from Hamamatsu?",
    L"Where are you from?",
    L"Birthplace"
};

struct Com_wheredoyoulive {
    User * user;

    bool Com_wheredoyoulive::check(wchar_t *com) {
        for (int i = 0; i < MAX_PLACE_NUMBER; i++) {
            if (strcmps(com, wheredoyoulive_keywords[i]))
                return true;
        }
        return false;
    }

    void Com_wheredoyoulive::prepare(User * user) {
        this->user = user;
    }

    void Com_wheredoyoulive::execute() {
        if(user->favorability < -50){
	    imageview(L"despise");
            printfs(L"I won't tell you.");
            printfs(L"\r\n");
        } else if(user->favorability >= -50 && user->favorability < 50){
	    imageview(L"default2.bgra");
            printfs(L"I live in Japan.");
            printfs(user->name);
            printfs(L".\r\n");
        } else {
	    imageview(L"smile.bgra");
            printfs(L"I live in Hamamatsu");
            printfs(user->name);
            printfs(L" How about you \r\n");
            if(compare(L"Hamamatsu")||compare(L"Shizuoka")){
		imageview(L"surprise.bgra");
                printfs(L"Me too!!\r\n");
            } else if(compare(L"Japan")) {
		imageview(L"default.bgra");
                printfs(L"Where do you live in Japan?");
            }else{
		imageview(L"big_smile.bgra");
		printfs(L"Oh,that's a good place ");
			}
        }
    }
};
