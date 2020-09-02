#pragma once
#include "systemcall.cpp"
#include "User.cpp"
#include "Commands/Com_hello.cpp"
#include "Commands/Com_good_morning.cpp"
#include "Commands/Com_good_night.cpp"

#define COMMAND_LIST_LENGTH 3

class ArtificialIntelligence {
public:
	User user;
	Command* commandList[COMMAND_LIST_LENGTH];

	ArtificialIntelligence() {
        User *user = new User();
		commandList[0] = new Com_hello();
		commandList[1] = new Com_good_morning();
		commandList[2] = new Com_good_night();
	}

	void dialogue() {

		wchar_t com[MAX_COMMAND_LENGTH];

		while (1) {
			printf(L"AI DIALOGUE >");
			if (commandline(com) <= 0) {
				continue;
			}

			for (int i = 0; i < COMMAND_LIST_LENGTH; i++) {
				if (commandList[i]->check(com)) {
					commandList[i]->prepare(&user);
					commandList[i]->execute();
				}
			}
		}
	}
};
