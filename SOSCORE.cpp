#include "systemcall.cpp"

static EFI_SYSTEM_TABLE *ST;
EFI_SIMPLE_FILE_SYSTEM_PROTOCOL *SFSP;
EFI_GUID sfsp_guid = EFI_SIMPLE_FILE_SYSTEM_PROTOCOL_GUID;
static wchar_t datalist[20][10];

bool compare(wchar_t *word){
  wchar_t com[MAX_COMMAND_LENGTH];
  while(1){
  if(commandline(com) <= 0)
      continue;
  if(strcmp(word, com))
    return true;
  else
    return false;
  }
}

void strcpy(wchar_t *word1, wchar_t *word2){
  while(*word1 != L'\0'){
    word1 = word2++;
    word1++;
  }
  ++word1 = L'\0';

}

void printf(wchar_t *stringptr){
    ST->ConOut->OutputString(ST->ConOut, (CHAR16*)stringptr);
}

bool strcmp(wchar_t *word1,wchar_t *word2){

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

void filescan(){
  EFI_FILE_PROTOCOL *root;
  EFI_FILE_PROTOCOL *file;

  CHAR16 *data = (CHAR16*)L" ";
  CHAR16 *filename = (CHAR16*)L"pdata";
  unsigned long long data_size = 1024;

  SFSP->OpenVolume(SFSP,&root);
  root->Open(root, &file, (CHAR16 *)L"pdata", EFI_FILE_MODE_READ, 0);
  file->Read(file, &data_size, (CHAR16 *)data);
  for(i = 0; ;i++){
    for(j = 0; ;j++){
      if(*data == L'\0')
        return;
      if(*data == L'\n')
        break;
      datalist[j][i] = *data++;
    }
    *data++;
  }
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
    if(strcmp(L"hello", com))
      printf(L"Hello World!\r\n");
    else if(strcmp(L"shutdown", com))
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
