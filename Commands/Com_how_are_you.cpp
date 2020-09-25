#include "Command.cpp"

class Com_howareyou : public Command {
private:
	User* user;

public:
	Com_howareyou();
	void makeKeywordList() override;
	void prepare(User* user) override;
	void execute() override;
};

inline Com_howareyou::Com_howareyou() {
	makeKeywordList();
}

inline void Com_howareyou::makeKeywordList() {
	plug(keywords[0], L"how are you");
	plug(keywords[1], L"how are you?");
    plug(keywords[2], L"how are you today");
    plug(keywords[3], L"how are you today?");
}

inline void Com_howareyou::prepare(User* user) {
	this->user = user;
}

inline void Com_howareyou::execute() {
	if(user->favoravirity < -50){
        printf(L"Don't talk me ");
	    printf(L"\r\n");
    } else if(user->favoravirity >= -50 && user->facoravirity < 50){
        printf(L"I'm fine thank you");
        printf(user->name);
        print(L"\r\n")
    } else {
        printf(L"I'm fine thank you");
        printf(user->name);
        printf(L"and you? \r\n");
        if(compare(L"i'm fine thank you") || compare(L"me too")){
            printf(L"Oh yeah \r\n");
        } else {
            printf(L"Really? Take care of yourself");
        }
    }
}
