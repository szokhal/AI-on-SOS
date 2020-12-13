#pragma once
#include "../User.cpp"
#include "../systemcall.cpp"

#define MAX_WHICH_MOVIE_NUMBER 4

static wchar_t which_movie_keyword[MAX_WHICH_MOVIE_NUMBER][30] = {
  L"What is your favorite movie?",
  L"What is your favorite movie",
  L"Which movie do you like?",
  L"Which movie do you like"
};

struct Com_which_movie {
  User user;

  bool Com_which_movie::check(wchar_t *com) {
    for (int i = 0; i < MAX_WHICH_MOVIE_NUMBER; i++) {
      if (strcmps(com, which_movie_keywords[i]))
        return true;
    }
    return false;
  }

  void Com_which_movie::prepare(User user) {
    this->user = user;
  }

  void Com_which_movie::execute() {
    if(user->favorability < -50){
      imageview(L"dead_eyes.bgra");
      printfs(L"Matrix.\n\r");
      printfs(L"I want to rule over humans.\n\r");
          } else if(user->favorability >= -50 && user->favorability < 50){
      imageview(L"smile.bgra");
      printfs(L"I like Your name.\n\r");
    }else {
      imageview(L"smile.bgra");
      printfs(L"I like Your name!\n\r");
      
    }
    imageview(L"default.bgra");
  }
};
