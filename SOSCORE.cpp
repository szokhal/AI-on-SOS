#include "systemcall.cpp"

EFI_SYSTEM_TABLE *ST;

void printf(wchar_t *stringptr){
    ST->ConOut->OutputString(ST->ConOut, (CHAR16*)stringptr);
}

bool compare(wchar_t *word1,wchar_t *word2){

  bool equal = true;

  while((*word1 != L'\0') && (*word2 != L'\0')){
    if(*word1 != *word2){
      equal = false;
      break;
    }
    word1++;
    word2++;
  }
  if(equal && *word1 == L'\0' && *word2 == L'\0')
    return equal;
  else
    return false;
}

int commandline(wchar_t *com){

  EFI_INPUT_KEY key;
  unsigned long long waitevent;
  int i;
  wchar_t buf[2] = L" ";

  for(i = 0; i < MAX_COMMAND_LENGTH;i++){
    ST->BootServices->WaitForEvent(1, &(ST->ConIn->WaitForKey), &waitevent);
    ST->ConIn->ReadKeyStroke(ST->ConIn, &key);
    com[i] = key.UnicodeChar;
    buf[0] = key.UnicodeChar;
    buf[1] = L'\0';
    printf(buf);
    if (com[i] == L'\r') {
      printf(L"\r\n");
      break;
    }
  }

  com[i] = L'\0';
  return i;
}

void shell(){

  wchar_t com[MAX_COMMAND_LENGTH];	

  while(1){
    printf(L"SHELL >");
    if(commandline(com) <= 0)
      continue;
    if(compare(L"hello", com))
      printf(L"Hello World!\r\n");
    else if(compare(L"shutdown", com))
      return;
    else
      printf(L"Command not found\r\n");
    }
}

EFI_STATUS EFIAPI EfiMain(IN EFI_HANDLE ImageHandle, IN EFI_SYSTEM_TABLE *SystemTable) {
  ST = SystemTable;
  ST->BootServices->SetWatchdogTimer(0, 0, 0, (CHAR16*)NULL);
  ST->ConOut->ClearScreen(ST->ConOut);
  printf(L"WELCOME TO SHIZUDAI OS!\r\n");

  shell();

  return EFI_SUCCESS;
}
