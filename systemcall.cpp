extern "C" {
#include <Uefi.h>
}

#define MAX_COMMAND_LENGTH 100

extern EFI_SYSTEM_TABLE *ST;
bool compare(wchar_t *word1,wchar_t *word2);
int commandline(wchar_t *com);
void printf(wchar_t *stringptr);
void strcpy(wchar_t *word1, wchar_t *word2);
