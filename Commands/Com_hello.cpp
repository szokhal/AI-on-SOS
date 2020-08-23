#include "Command.cpp"

//�N���X����Com_*****�̌`�ɕύX����
class Com_hello : protected Command {
private:
	//���[�U�[�̏�񂪕K�v�Ȃ珑���Ă���
	//prepare()���ŏ��������Ă���g��
	User* user;

	//�����Ŋ֐�����������ꍇ�͂����Ő錾

public:
	//Com_hello()�̂Ƃ���͊e�N���X���ɏ�������
	//����ȊO�͏��������Ȃ���OK
	Com_hello();
	void makeKeywordList() override;
	void prepare(User* user) override;
	void execute() override;
};

//�K�{
//Com_hello�̂Ƃ���͊e�N���X���ɏ�������
inline Com_hello::Com_hello() {
	makeKeywordList();
}

//�K�{
//20�܂ŃL�[���[�h��ǉ��ł���
inline void Com_hello::makeKeywordList() {
	plug(keywords[0], L"hello");
	plug(keywords[1], L"hi");
}

//�K�{
//���[�U�[�̏�񂪕K�v�Ȃ���Β��g�͋�ł�OK
//���[�U�[�̏��ȊO�̃f�[�^���ق����Ƃ��͗v���k
inline void Com_hello::prepare(User* user) {
	this->user = user;
}

//�K�{
//���ۂɎ��s�����main()�I�ȕ���
inline void Com_hello::execute() {
	printf(L"hi ");
	printf(user->name);
	printf(L"\r\n");
}
