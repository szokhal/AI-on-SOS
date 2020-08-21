#include "systemcall.hpp"
#define MAX_KEYWORD_NUMBER 20

class Command {
protected:
	char_t keywords[MAX_KEYWORD_NUMBER][MAX_COMMAND_LENGTH];
	void plug(wchar_t* memory, wchar_t* word);

public:
	bool check(wchar_t* com);
	virtual void makeKeywordList() = 0;
	virtual void prepare(User* user) = 0;
	virtual void execute() = 0;
}

inline void Command::plug(wchar_t* memory, wchar_t* word) {
	for (int i = 0; word = L'\0'; i++) {
		memory[i] = word[i];
	}
}

inline bool Command::check(wchar_t* com) {
	for (wchar_t * keyword = keywords; keyword != NULL; keyword++) {
		if (compare(com, keyword)) {
			return true;
		}
	}
	return false;
}
