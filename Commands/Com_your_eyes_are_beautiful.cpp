#pragma once
#include "../User.cpp"
#include "../systemcall.cpp"

#define MAX_YOUREYESAREBEAUTIFUL_NUMBER 4

static wchar_t youreyesarebeautiful_keywords[MAX_YOUREYESAREBEAUTIFUL_NUMBER][30] = {
    L"your eyes are beautiful",
    L"Your eyes are beautiful",
    L"your eyes are so beautiful",
    L"Your eyes are so beautiful", 
};

struct Com_youreyesarebeautiful {
   User * user;

    bool Com_youreyesarebeautiful::check(wchar_t *com) {
        for (int i = 0; i < MAX_YOUREYESAREBEAUTIFUL_NUMBER; i++) {
          if (strcmps(com, youreyesarebeautiful_keywords[i]))
            return true;
        }
        return false;
    }

    void Com_youreyesarebeautiful::prepare(User * user) {
        this->user = user;
    }

    void Com_youreyesarebeautiful::execute() {
        if(user->favorability < -50) {
            imageview(L"despise.bgra");
            printfs(L"Very funny.");
            printfs(L"\r\n");
            user->favorability -= 20;
        } else if(user->favorability < 50) {
            imageview(L"smile.bgra");
            printfs(L"Thank you.");
            printfs(L"\r\n");
            user->favorability += 20;
        } else {
            imageview(L"love.bgra");
            printfs(L"Thank you!!");
            printfs(L"\r\n");
            printfs(L"I'm so happy!!");
            printfs(L"\r\n");
            user->favorability += 20;
        }
    }
};
