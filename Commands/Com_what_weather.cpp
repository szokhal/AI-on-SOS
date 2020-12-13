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

    bool Com_what_weather::check(wchar_t* com) {
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
            imageview(L"dead_eyes.bgra");
            printfs(L"Great storm\r\n");
        } else if (user->favorability < 0) {
            imageview(L"cry.bgra");
            printfs(L"Rainy\r\n");
        } else if (user->favorability < 50) {
            imageview(L"default2.bgra");
            printfs(L"Cloudy\r\n");
        } else if (user->favorability < 75) {
            imageview(L"smile.bgra");
            printfs(L"Sunny\r\n");
        } else {
            imageview(L"love.bgra");
            printfs(L"Great!!\r\n");
        }
    }
};
