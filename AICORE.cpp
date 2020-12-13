#pragma once
#include "systemcall.cpp"
#include "User.cpp"
#include "Commands\Com_can_you_teach_me_math.cpp"
#include "Commands\Com_can_you_teach_me_programming.cpp"
#include "Commands\Com_do_you_have_time_now.cpp"
#include "Commands\Com_do_you_like_japan.cpp"
#include "Commands\Com_exit.cpp"
#include "Commands\Com_extreme_sorry.cpp"
#include "Commands\Com_free.cpp"
#include "Commands\Com_get_age.cpp"
#include "Commands\Com_get_favorability.cpp"
#include "Commands\Com_hello.cpp"
#include "Commands\Com_how_are_you.cpp"
#include "Commands\Com_i_am_so_tired.cpp"
#include "Commands\Com_i_hate_you.cpp"
#include "Commands\Com_i_like_your_voice.cpp"
#include "Commands\Com_i_won't_see_you_for_a_while.cpp"
#include "Commands\Com_like_linux.cpp"
#include "Commands\Com_like_windows.cpp"
#include "Commands\Com_nothing.cpp"
#include "Commands\Com_ok_google.cpp"
#include "Commands\Com_omae_kawaii.cpp"
#include "Commands\Com_one_more_language.cpp"
#include "Commands\Com_riddle.cpp"
#include "Commands\Com_season.cpp"
#include "Commands\Com_set_age.cpp"
#include "Commands\Com_set_favorability.cpp"
#include "Commands\Com_set_name.cpp"
#include "Commands\Com_sorry.cpp"
#include "Commands\Com_university.cpp"
#include "Commands\Com_what_food_do_you_like.cpp"
#include "Commands\Com_what_is_your_favorite_drink.cpp"
#include "Commands\Com_what_is_your_favorite_sport.cpp"
#include "Commands\Com_what_is_your_favorite_sweets.cpp"
#include "Commands\Com_what_is_your_gender.cpp"
#include "Commands\Com_what_kind_of_songs_do_you_like.cpp"
#include "Commands\Com_What_language.cpp"
#include "Commands\Com_what_PC_game_do_you_like.cpp"
#include "Commands\Com_what_rhythm_game_do_you_like.cpp"
#include "Commands\Com_what_smartphone_game_do_you_like.cpp"
#include "Commands\Com_what_TV_game_do_you_like.cpp"
#include "Commands\Com_what_types_of_book_do_you_read.cpp"
#include "Commands\Com_what_weather.cpp"
#include "Commands\Com_when_you_are_happy.cpp"
#include "Commands\Com_where_are_you_from.cpp"
#include "Commands\Com_where_do_you_want_to_go.cpp"
#include "Commands\Com_which_movie.cpp"
#include "Commands\Com_world_greetings.cpp"
#include "Commands\Com_you_are_cute.cpp"
#include "Commands\Com_your_eyes_are_beautiful.cpp"

int     getInt(wchar_t chara);
wchar_t getChar(int num);
wchar_t str[20];
void    firstBoot(User* user);

User user;
Com_canyouteachmemath*        teach_math;
Com_canyouteachmeprogramming* teach_programming;
Com_doyouhavetimenow*         have_time;
Com_doyoulikejapan*           like_japan;
Com_exit*                     exit;
Com_extreme_sorry*            extreme_sorry;
Com_free*                     free;
Com_get_age*                  get_age;
Com_get_favo*                 get_favo;
Com_hello*                    hello;
Com_howareyou*                how_are_you;
Com_iamsotired*               so_tired;
Com_ihateyou*                 hate_you;
Com_ilikeyourvoice*           like_your_voice;
Com_iwillnotseeyouforawhile*  wont_see_you;
Com_like_linux*               like_linux;
Com_like_windows*             like_windows;
Com_nothing*                  nothing;
Com_ok_google*                ok_google;
Com_omae_kawaii*              omae_kawaii;
Com_one_more_language*        one_more_language;
Com_riddle*                   riddle;
Com_what_season*              what_season;
Com_set_age*                  set_age;
Com_set_favo*                 set_favo;
Com_set_name*                 set_name;
Com_sorry*                    sorry;
Com_university*               university;
Com_whatfooddoyoulike*        whatfooddoyoulike;
Com_drink*                    what_drink;
Com_whatisyourfavoritesport*  what_sport;
Com_whatisyourfavoritesweets* what_sweets;
Com_whatisyourgender*         what_gender;
Com_whatkindofsongsdoyoulike* what_songs;
Com_what_language*            what_language;
Com_whatPCgamedoyoulike*      whatPCgamedoyoulike;
Com_whatrhythmgamedoyoulike*  what_rhythm_game;
Com_whatsmartphonegamedoyoulike* what_smartphone_game;
Com_whatTVgamedoyoulike*      what_tv_game;
Com_book*                     what_book;
Com_what_weather*             what_weather;
Com_when_you_are_happy*       when_happy;
Com_wheredoyoulive*           where_from;
Com_wheredoyouwanttogo*       where_want_go;
Com_which_movie*              which_movie;
Com_greeting*                 world_greeting;
Com_you_are_cute*             you_are_cute;
Com_youreyesarebeautiful*     eyes_beautiful;

void sync_read() {
    wchar_t* favBuf = L"zzzz";
    fillNull(user.name, 40);
    fileread(user.name, L"name.ai");
    fillNull(favBuf, 10);
    fileread(favBuf, L"favorability.ai");
    user.favorability = wtoi(favBuf);
}

void sync_write() {
      wchar_t* favBuf = L"zzzz";
      itow(user.favorability, favBuf);
      filewrite(user.name, L"name.ai");
      filewrite(favBuf, L"favorability.ai");

}

void dialogue() {
    sync_read();
    wchar_t com[MAX_COMMAND_LENGTH];
    printfs(L"Welcome!\r\n");

    if (strcmps(user.name, L"null")) {
      firstBoot(&user);
    }

    bool suki = false;

    while (1) {

        // default face
        printfs(L"\r\n< AI dialogue >\r\n");

        if (commandline(com) <= 0) {
            continue;
        }

        if (teach_math->check(com)) {
            teach_math->prepare(&user);
            teach_math->execute();
            continue;
        }

        if (teach_programming->check(com)) {
            teach_programming->prepare(&user);
            teach_programming->execute();
            continue;
        }

        if (have_time->check(com)) {
            have_time->prepare(&user);
            have_time->execute();
            continue;
        }

        if (like_japan->check(com)) {
            like_japan->prepare(&user);
            like_japan->execute();
            continue;
        }

        if (extreme_sorry->check(com)) {
            extreme_sorry->prepare(&user);
            extreme_sorry->execute();
            continue;
        }

        if (free->check(com)) {
            free->prepare(&user);
            free->execute();
            continue;
        }

        if (get_age->check(com)) {
            get_age->prepare(&user);
            get_age->execute();
            continue;
        }

        if (get_favo->check(com)) {
            get_favo->prepare(&user);
            get_favo->execute();
            continue;
        }

        if (hello->check(com)) {
            hello->prepare(&user);
            hello->execute();
            continue;
        }

        if (how_are_you->check(com)) {
            how_are_you->prepare(&user);
            how_are_you->execute();
            continue;
        }

        if (so_tired->check(com)) {
            so_tired->prepare(&user);
            so_tired->execute();
            continue;
        }

        if (hate_you->check(com)) {
            hate_you->prepare(&user);
            hate_you->execute();
            continue;
        }

        if (like_your_voice->check(com)) {
            like_your_voice->prepare(&user);
            like_your_voice->execute();
            continue;
        }

        if (wont_see_you->check(com)) {
            wont_see_you->prepare(&user);
            wont_see_you->execute();
            continue;
        }

        if (like_linux->check(com)) {
            like_linux->prepare(&user);
            like_linux->execute();
            continue;
        }

        if (like_windows->check(com)) {
            like_windows->prepare(&user);
            like_windows->execute();
            continue;
        }

        if (ok_google->check(com)) {
            ok_google->prepare(&user);
            ok_google->execute();
            continue;
        }

        if (omae_kawaii->check(com)) {
            omae_kawaii->prepare(&user, &suki);
            omae_kawaii->execute();
            continue;
        }

        if (one_more_language->check(com)) {
            one_more_language->prepare(&user);
            one_more_language->execute();
            continue;
        }

        if (riddle->check(com)) {
            riddle->prepare(&user);
            riddle->execute();
            continue;
        }

        if (what_season->check(com)) {
            what_season->prepare(&user);
            what_season->execute();
            continue;
        }

        if (set_age->check(com)) {
            set_age->prepare(&user);
            set_age->execute();
            continue;
        }

        if (set_favo->check(com)) {
            set_favo->prepare(&user);
            set_favo->execute();
            continue;
        }

        if (set_name->check(com)) {
            set_name->prepare(&user);
            set_name->execute();
            continue;
        }

        if (sorry->check(com)) {
            sorry->prepare(&user);
            sorry->execute();
            continue;
        }

        if (university->check(com)) {
            university->prepare(&user);
            university->execute();
            continue;
        }

        if (whatfooddoyoulike->check(com)) {
            whatfooddoyoulike->prepare(&user);
            whatfooddoyoulike->execute();
            continue;
        }

        if (what_drink->check(com)) {
            what_drink->prepare(&user);
            what_drink->execute();
            continue;
        }

        if (what_sport->check(com)) {
            what_sport->prepare(&user);
            what_sport->execute();
            continue;
        }

        if (what_sweets->check(com)) {
            what_sweets->prepare(&user);
            what_sweets->execute();
            continue;
        }

        if (what_gender->check(com)) {
            what_gender->prepare(&user);
            what_gender->execute();
            continue;
        }

        if (what_songs->check(com)) {
            what_songs->prepare(&user);
            what_songs->execute();
            continue;
        }

        if (what_language->check(com)) {
            what_language->prepare(&user);
            what_language->execute();
            continue;
        }

        if (whatPCgamedoyoulike->check(com)) {
            whatPCgamedoyoulike->prepare(&user);
            whatPCgamedoyoulike->execute();
            continue;
        }

        if (what_rhythm_game->check(com)) {
            what_rhythm_game->prepare(&user);
            what_rhythm_game->execute();
            continue;
        }

        if (what_tv_game->check(com)) {
            what_tv_game->prepare(&user);
            what_tv_game->execute();
            continue;
        }

        if (what_book->check(com)) {
            what_book->prepare(&user);
            what_book->execute();
            continue;
        }

        if (what_weather->check(com)) {
            what_weather->prepare(&user);
            what_weather->execute();
            continue;
        }

        if (when_happy->check(com)) {
            when_happy->prepare(&user);
            when_happy->execute();
            continue;
        }

        if (where_from->check(com)) {
            where_from->prepare(&user);
            where_from->execute();
            continue;
        }

        if (where_want_go->check(com)) {
            where_want_go->prepare(&user);
            where_want_go->execute();
            continue;
        }

        if (which_movie->check(com)) {
            which_movie->prepare(&user);
            which_movie->execute();
            continue;
        }

        if (world_greeting->check(com)) {
            world_greeting->prepare(&user);
            world_greeting->execute();
            continue;
        }

        if (you_are_cute->check(com)) {
            you_are_cute->prepare(&user);
            you_are_cute->execute();
            continue;
        }

        if (eyes_beautiful->check(com)) {
            eyes_beautiful->prepare(&user);
            eyes_beautiful->execute();
            continue;
        }

        if (exit->check(com)) {
            exit->execute();
            sync_write();
            return;
        }

        if (nothing->check()) {
            nothing->execute();
            continue;
        }
    }
}

void firstBoot(User* user) {
  printfs(L"Hello! I'm A.I.\r\n");
  printfs(L"Nice to meet you!\r\n");

  printfs(L"Please tell me your name.    --Type your name\r\n");
  fillNull(user->name, 35);
  scanfs(user->name);
  
  printfs(L"How old are you?             --Type your age\r\n");
  wchar_t age[10] = L"";
  scanfs(age);
  user->age = wtoi(age);

  printfs(L"\r\nWELCOME TO A.I. WORLD!!\r\n");
  printfs(L"Let's talk a lot from now on!\r\n");
}


void fillNull(wchar_t* ptr, int byte) {
  for (int i = 0; i < byte; i++) {
    ptr[i] = L'\0';
  }
}


int wtoi(wchar_t* str) {
  int num = 0;

  for (int i = 0; str[i] != L'\0'; i++) {
    num = num * 10 + getInt(str[i]);
  }

  return num;
}

void itow(int num, wchar_t* str) {
  int digit = 0;
  int copy = num;

  while (copy != 0) {
    copy /= 10;
    digit++;
  }

  for (int i = digit - 1; 0 <= i; i--) {
    copy = num;

    for (int j = 1; j < digit - i; j++) {
      copy /= 10;
    }

    copy = copy % 10;
    str[i] = getChar(copy);
  }
}

int getInt(wchar_t chara) {
  switch (chara) {
    case L'0':
      return 0;
      break;
    case L'1':
      return 1;
      break;
    case L'2':
      return 2;
      break;
    case L'3':
      return 3;
      break;
    case L'4':
      return 4;
      break;
    case L'5':
      return 5;
      break;
    case L'6':
      return 6;
      break;
    case L'7':
      return 7;
      break;
    case L'8':
      return 8;
      break;
    case L'9':
      return 9;
      break;
    default:
      return 0;
  }
}

wchar_t getChar(int num) {
  switch (num) {
    case 0:
      return L'0';
      break;
    case 1:
      return L'1';
      break;
    case 2:
      return L'2';
      break;
    case 3:
      return L'3';
      break;
    case 4:
      return L'4';
      break;
    case 5:
      return L'5';
      break;
    case 6:
      return L'6';
      break;
    case 7:
      return L'7';
      break;
    case 8:
      return L'8';
      break;
    case 9:
      return L'9';
      break;
    default:
      return L'0';
  }
}

void bootai() {
    dialogue();
}
