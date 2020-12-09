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
        if(user->favoravility < -50) {
            imageview(L"jitome.bgra");
            printfs(L"Very funny.");
            printfs(L"\r\n");
            user->favoravility -= 20;
        } else if(user->favoravility < 50) {
            imageview(L"smile.bgra");
            printfs(L"Thank you.");
            printfs(L"\r\n");
            user->favoravility += 20;
        } else {
            imageview(L"big_smile.bgra");
            printfs(L"Thank you!!");
            printfs(L"\r\n");
            printfs(L"I'm so happy!!");
            printfs(L"\r\n");
            user->favoravility += 20;
        }
    }
};