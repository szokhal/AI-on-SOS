#include "systemcall.cpp"
#include "Command.cpp"

//クラス名をCom_*****の形に変更する
class Com_hello : protected Command {
private:
	//ユーザーの情報が必要なら書いておく
	//prepare()内で初期化してから使う
	User* user;

	//自分で関数を実装する場合はここで宣言

public:
	//Com_hello()のところは各クラス名に書き換え
	//それ以外は書き換えなくてOK
	Com_hello();
	void makeKeywordList() override;
	void prepare(User* user) override;
	void execute() override;
};

//必須
//Com_helloのところは各クラス名に書き換え
inline Com_hello::Com_hello() {
	makeKeywordList();
}

//必須
//20個までキーワードを追加できる
inline void Com_hello::makeKeywordList() {
	plug(keywords[0], L"hello");
	plug(keywords[1], L"hi");
}

//必須
//ユーザーの情報が必要なければ中身は空でもOK
//ユーザーの情報以外のデータがほしいときは要相談
inline void Com_hello::prepare(User* user) {
	this->user = user;
}

//必須
//実際に実行されるmain()的な部分
inline void Com_hello::execute() {
	printf(L"hi ");
	printf(user->name);
	printf(L"\r\n");
}
