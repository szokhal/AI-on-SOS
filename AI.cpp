#include "systemcall.cpp"
#include "Com_hello.cpp"

#define COMMAND_LIST_LENGTH 1

class ArtificialIntelligence {
public:
	User user;
	Command commandList[COMMAND_LIST_LENGTH];

	ArtificialIntelligence() {
		//コンストラクタでファイルから情報代入
		commandList[0] = new Com_hello();
	}

	void dialogue() {

		wchar_t com[MAX_COMMAND_LENGTH];

		while (1) {
			ST->ConOut->OutputString(ST->ConOut, (CHAR16)L"AI DIALOGUE >");
			if (commandline(com) <= 0) {
				continue;
			}

			for (int i = 0; i < COMMAND_LIST_LENGTH; i++) {
				if (commandList[i].check(com)) {
					commandList[i].prepare(&user);
					commandList[i].execute();
				}
			}
		}
	}
};