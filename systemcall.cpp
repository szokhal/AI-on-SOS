extern "C" {
#include <Uefi.h>
}

#define MAX_COMMAND_LENGTH 100

extern EFI_SYSTEM_TABLE *ST;
extern unsigned int VerticalResolution, HorisontalResolution;
bool strcmps(wchar_t *word1,wchar_t *word2);
void strcpys(wchar_t *word1, wchar_t *word2);
bool compare(wchar_t *word);
int commandline(wchar_t *com);
void printfs(wchar_t *stringptr);
void bootai();
