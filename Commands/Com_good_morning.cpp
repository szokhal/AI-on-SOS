#include "Command.cpp"

class Com_good_morning : protected Command {
private:
	User* user;

public:
	Com_good_morning();
	void makeKeywordList() override;
	void prepare(User* user) override;
	void execute() override;
};

inline Com_good_morning::Com_good_morning() {
	makeKeywordList();
}

inline void Com_good_morning::makeKeywordList() {
	plug(keywords[0], L"good morning");
}

inline void Com_good_morning::prepare(User* user) {
	this->user = user;
}

inline void Com_good_morning::execute() {
	printf(L"good morning ");
	printf(user->name);
	printf(L"\r\n");
}
