#include "systemcall.cpp"
#include "Command.cpp"

class Com_hello : protected Command {
private:
	User* user;

public:
	Com_hello();
	void makeKeywordList() override;
	void prepare(User* user) override;
	void execute() override;
};

inline Com_hello::Com_hello() {
	makeKeywordList();
}

inline void Com_hello::makeKeywordList() {
	plug(keywords[0], L"hello");
}

inline void Com_hello::prepare(User* user) {
	this->user = user;
}

inline void Com_hello::execute() {
	printf(L"hello ");
	printf(user->name);
	printf(L"\r\n");
}