#pragma once
#include "../User.cpp"
#include "../systemcall.cpp"

#define MAX_BOOK_NUMBER 3

static wchar_t book_keywords[MAX_BOOK_NUMBER][30] = {
    L"book",
    L"What types of book do you read?",
		L"What types of book do you read",
		L"Do you read any books?",
		L"do you read any books",
  };

struct Com_book {
  User * user;

  bool Com_book::check(wchar_t *com) {
    for (int i = 0; i < MAX_BOOK_NUMBER; i++) {
      if (strcmps(com, book_keywords[i]))
        return true;
    }
    return false;
  }

  void Com_book::prepare(User * user) {
    this->user = user;
  }

  void Com_book::execute() {
    if(user->favoravility < -50) {
        printfs(L"I don't read any books!\r\n");
				printfs(L"Don't speak to me!!");
    } else if(user->favoravility < 50) {
        printfs(L"I don'tread only textbook while studying.\r\n");
    } else{
			printfs(L"I like story of adventures.\r\n");
			printfs(L"It made me excited.\r\n");
			printfs(L"I am so excited and I couldn't sleep")
		}
  }
};
