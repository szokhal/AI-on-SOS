extern "C" {
#include <Uefi.h>
}
#include "systemcall.cpp"

EFI_SYSTEM_TABLE *ST;
EFI_SIMPLE_FILE_SYSTEM_PROTOCOL *SFSP;
EFI_GRAPHICS_OUTPUT_PROTOCOL *GOP;
EFI_GUID sfsp_guid = EFI_SIMPLE_FILE_SYSTEM_PROTOCOL_GUID;
EFI_GUID gop_guid = EFI_GRAPHICS_OUTPUT_PROTOCOL_GUID;
static wchar_t datalist[20][10];

#define img_width 500
#define img_height 500


void strcpys(wchar_t *word1, wchar_t *word2){
  while(*word1 != L'\0'){
    word1 = word2++;
    word1++;
  }
  ++*word1 = L'\0';
}

bool compare(wchar_t *word){
  wchar_t com[MAX_COMMAND_LENGTH];
  while(1){
  if(commandline(com) <= 0)
      continue;
  if(strcmps(word, com))
    return true;
  else
    return false;
  }
}

void printfs(wchar_t *stringptr){
  ST->ConOut->OutputString(ST->ConOut, (CHAR16*)stringptr);
}

bool strcmps(wchar_t *word1,wchar_t *word2){

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
    printfs(buf);
    if (com[i] == L'\r') {
      printfs(L"\r\n");
      break;
    }
  }

  com[i] = L'\0';
  return i;
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
  for(unsigned int i = 0; ;i++){
    for(unsigned int j = 0; ;j++){
      if(*data == L'\0')
        return;
      if(*data == L'\n')
        break;
      datalist[j][i] = *data++;
    }
    *data++;
  }
}

void imagetest(){

  EFI_FILE_PROTOCOL *root;
  EFI_FILE_PROTOCOL *file;

  unsigned long long data_size = 4194304;
  unsigned char img[4194304];
  unsigned char *gptr = (unsigned char *)GOP->Mode->FrameBufferBase;

  SFSP->OpenVolume(SFSP, &root);
  root->Open(root, &file, (CHAR16 *)L"aimage.bgra", EFI_FILE_MODE_READ, EFI_FILE_READ_ONLY);
  file->Read(file, &data_size, (void *)img);
  unsigned int i,j,k,l = 0;

  gptr += (GOP->Mode->Info->HorizontalResolution - img_width) * 4;
  for(i = 0;i < img_height; i++){
    for(j = 0; j < img_width; j++){
      for(k = 0; k < 4; k++)
        *gptr++ = img[l++];
    }
    gptr += (GOP->Mode->Info->HorizontalResolution - img_width) * 4;
  }
}

void shell(){

  wchar_t com[MAX_COMMAND_LENGTH];	

  while(1){
    printfs(L"SHELL >");
    if(commandline(com) <= 0)
      continue;
    if(strcmps(L"hello", com))
      printfs(L"Hello World!\r\n");
    else if(strcmps(L"file", com))
      filescan();
    else if(strcmps(L"image", com))
      imagetest();
    else if(strcmps(L"bootai", com))
      bootai();
    else if(strcmps(L"shutdown", com))
      return;
    else
      printfs(L"Command not found\r\n");
  }
}

EFI_STATUS EFIAPI EfiMain(IN EFI_HANDLE ImageHandle, IN EFI_SYSTEM_TABLE *SystemTable) {
  ST = SystemTable;
  ST->BootServices->SetWatchdogTimer(0, 0, 0, (CHAR16*)NULL);
  ST->ConOut->ClearScreen(ST->ConOut);
  ST->BootServices->LocateProtocol(&sfsp_guid, NULL, (void **)&SFSP);
  ST->BootServices->LocateProtocol(&gop_guid, NULL, (void **)&GOP);

  printfs(L"WELCOME TO Sato Operating System!\r\n");

  shell();

  return EFI_SUCCESS;
}
