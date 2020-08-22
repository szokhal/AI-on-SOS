  
#include "systemcall.cpp"
#include "Command.cpp"

class Com_hello : protected Command {
private:
	User * user;

public:
	void makeKeywordList() override;
	void prepare(User* user) override;
	void execute() override;
}

inline Com_hello::Com_hello() {
	makeKeywordList();
}

inline void Com_hello::makeKeywordList() override {
	plug(&keywords[0], L"hi");
}

inline void Com_hello::prepare(User* user) override {
	this->user = user;
}

inline void Com_hello::execute() override {
	printf(L"hi ");
	printf(&(user->name));
	printf(L"\r\n");
}