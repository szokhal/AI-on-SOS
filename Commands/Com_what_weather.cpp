#pragma once
#include "../User.cpp"
#include "../systemcall.cpp"

#define MAX_WHAT_WEATHER_NUMBER 3

static wchar_t what_weather_keywords[MAX_WHAT_WEATHER_NUMBER][20] {
    L"What's the weather",
    L"What is the weather",
    L"weather"
};

struct Com_what_weather {
    User* user;

    Com_what_weather::check(wchar_t* com) {
        for (int i = 0; i < MAX_WHAT_WEATHER_NUMBER; i++) {
            if (strcmps(com, what_weather_keywords[i])) {
                return true;
            }
        }
        return false;
    }

    void Com_what_weather::prepare(User* user) {
        this->user = user;
    }

    void Com_what_weather::execute() {
        if (user->favorability < -50) {
            printfs(L"Great storm\r\n");
        } else if (user->favorability < 0) {
            printfs(L"Rainy\r\n");
        } else if (user->favorability < 50) {
            printfs(L"Cloudy\r\n");
        } else if (user->favorability < 75) {
            printfs(L"Sunny\r\n");
        } else {
            printfs(L"Great!!\r\n");
        }
    }
};