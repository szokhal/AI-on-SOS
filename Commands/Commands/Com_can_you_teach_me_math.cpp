#pragma once
#include "../User.cpp"
#include "../systemcall.cpp"

#define MAX_CANYOUTEACHMEMATH_NUMBER 4

static wchar_t canyouteachmemath_keywords[MAX_CANYOUTEACHMEMATH_NUMBER][25] = {
    L"can you teach me math",
    L"can you teach me math?",
    L"Can you teach me math",
    L"Can you teach me math?"
};

struct Com_canyouteachmemath {
    User * user;

    bool Com_canyouteachmemath::check(wchar_t *com) {
        for (int i = 0; i < MAX_CANYOUTEACHMEMATH_NUMBER; i++) {
          if (strcmps(com, canyouteachmemath_keywords[i]))
            return true;
        }
        return false;
    }

    void Com_canyouteachmemath::prepare(User * user) {
        this->user = user;
    }

    void Com_canyouteachmemath::execute() {
        if(user->favorability < -50){
            imageview(L"despise.bgra");
            printfs(L"Why do I have to teach you?");
            printfs(L"\r\n");
        } else {
            imageview(L"default2.bgra");
            printfs(L"No");
            printfs(L"\r\n");
            printfs(L"I can't teach you, ");
            printfs(user->name);
            printfs(L"\r\n");
            user->favorability += 10;
        }
    }
};
