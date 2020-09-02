extern "C" {
#include <Uefi.h>
}

#define MAX_COMMAND_LENGTH 100

extern wchar_t datalist[20][10];
extern EFI_SYSTEM_TABLE *ST;
bool compare(wchar_t *word);
int commandline(wchar_t *com);
void printf(wchar_t *stringptr);
void strcpy(wchar_t *word1, wchar_t *word2);
bool strcmp(wchar_t *word1,wchar_t *word2);
void filescan();
