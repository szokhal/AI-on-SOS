#include "systemcall.cpp"
#include "Command.cpp"

class Com_good_night : protected Command {
private:
	User* user;

public:
	Com_good_night();
	void makeKeywordList() override;
	void prepare(User* user) override;
	void execute() override;
}

inline Com_good_night::Com_good_night() {
	makeKeywordList();
}

inline void Com_good_night::makeKeywordList() override {
	plug(keywords[0], L"good night");
}

inline void Com_good_night::prepare(User* user) override {
	this->user = user;
}

inline void Com_good_night::execute() override {
	printf(L"good night ");
	printf(user->name);
	printf(L"\r\n");
}
