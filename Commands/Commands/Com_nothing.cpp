#pragma once
#include "../User.cpp"
#include "../systemcall.cpp"

struct Com_nothing {
    bool Com_nothing::check() {
        return true;
    }

    void Com_nothing::execute() {
        imageview(L"cry.bgra");
        printfs(L"It doesn't make sense.\r\n");
    }
};
