#pragma once
#include "systemcall.cpp"
#include "User.cpp"
#define MAX_KEYWORD_NUMBER 20

class Command {
protected:
	wchar_t keywords[MAX_KEYWORD_NUMBER][MAX_COMMAND_LENGTH];
	void plug(wchar_t* memory, wchar_t* word);

public:
	bool check(wchar_t* com);
	virtual void makeKeywordList() {};
	virtual void prepare(User* user) {};
	virtual void execute() {};
};

//strcpy‚Ý‚½‚¢‚È
inline void Command::plug(wchar_t* memory, wchar_t* word) {
	for (int i = 0; word = L'\0'; i++) {
		memory[i] = word[i];
	}
}

inline bool Command::check(wchar_t* com) {
	for (int i = 0; i < MAX_KEYWORD_NUMBER; i++) {
		if (compare(com, keywords[i])) {
			return true;
		}
	}
	return false;
}