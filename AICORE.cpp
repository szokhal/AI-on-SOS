#pragma once
#include "systemcall.cpp"
#include "User.cpp"
#include "Commands\Com_hello.cpp"

#define COMMAND_LIST_LENGTH 1

User user;
Com_hello *hello;

void makeLists() {
    hello->makeKeywordList();
}

void dialogue() {
    wchar_t com[MAX_COMMAND_LENGTH];
    printfs(L"Welcome!\r\n");

    while (1) {
        printfs(L"\r\n< AI dialogue >\r\n");

        if (commandline(com) <= 0) {
            continue;
        }

        if (hello->check(com)) {
            hello->prepare(user);
            hello->execute();
        }
    }
}

void bootai() {
    makeLists();
    dialogue();
}
