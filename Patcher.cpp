#include <fstream>
#include <iostream>
#include <vector>
#include <windows.h>

const DWORD BASE_ADDRESS = 0x00400000;
const DWORD ADDR_GUILDGAMESCRIPTBINDING = 0x0061fc70;

// pointers in IAT
const DWORD PTR_LOADLIBRARYA = 0x009aa164;
const DWORD PTR_GETPROCADDRESS = 0x009aa15c;

const char *DLL_NAME = "G2ER.dll";
const char *FUNC_NAME = "G2ER_GuildGameScriptBinding";

int main() {
  std::fstream gameFile("GuildII.exe", std::ios::in | std::ios::out | std::ios::binary);

  if (!gameFile.is_open()) {
    std::cerr << "Can't open GuildII.exe!" << std::endl;
    return 1;
  }

  // --- shellcode ---
  std::vector<BYTE> shellcode;

  DWORD shellcodeBaseAddr = ADDR_GUILDGAMESCRIPTBINDING;
  DWORD dllNameAddr = shellcodeBaseAddr + 50; // TODO make it dynamic depending on the shellcode size
                                              // 50 is kinda arbitrary, but the current shellcode is smaller anyway
  DWORD funcNameAddr = dllNameAddr + strlen(DLL_NAME) + 1;

  // PUSHAD
  shellcode.push_back(0x60);

  // --- LoadLibraryA("G2ER.dll") ---
  // PUSH dllNameAddr
  shellcode.push_back(0x68);
  shellcode.insert(shellcode.end(), (BYTE *)&dllNameAddr, (BYTE *)&dllNameAddr + 4);
  // CALL [PTR_LoadLibraryA]
  shellcode.push_back(0xFF);
  shellcode.push_back(0x15); // CALL DWORD PTR [adres]
  shellcode.insert(shellcode.end(), (BYTE *)&PTR_LOADLIBRARYA, (BYTE *)&PTR_LOADLIBRARYA + 4);

  // --- GetProcAddress(hModule, "G2ER_GuildGameScriptBinding") ---
  // PUSH funcNameAddr
  shellcode.push_back(0x68);
  shellcode.insert(shellcode.end(), (BYTE *)&funcNameAddr, (BYTE *)&funcNameAddr + 4);
  // PUSH EAX (handle from LoadLibraryA)
  shellcode.push_back(0x50);
  // CALL [PTR_GetProcAddress]
  shellcode.push_back(0xFF);
  shellcode.push_back(0x15); // CALL DWORD PTR [adres]
  shellcode.insert(shellcode.end(), (BYTE *)&PTR_GETPROCADDRESS, (BYTE *)&PTR_GETPROCADDRESS + 4);

  // we need to overwrite EAX from PUSHAD directly on the stack with our current one so that POPAD won't fuck up the address we got from GetProcAddress

  // MOV DWORD PTR [ESP+28], EAX (op: 89 44 24 1C)
  shellcode.push_back(0x89);
  shellcode.push_back(0x44);
  shellcode.push_back(0x24);
  shellcode.push_back(0x1C); // Offset 28 (0x1C)

  // POPAD (EAX should contain the pointer to our new fuction)
  shellcode.push_back(0x61);

  // JMP EAX
  shellcode.push_back(0xFF);
  shellcode.push_back(0xE0);

  /*
    shellcode.push_back(0x61);
    shellcode.push_back(0xFF);
    shellcode.push_back(0xE0);
    */

  DWORD fileOffset = ADDR_GUILDGAMESCRIPTBINDING - BASE_ADDRESS;
  gameFile.seekp(fileOffset, std::ios::beg);
  gameFile.write((char *)shellcode.data(), shellcode.size());

  // fill the rest with nops
  while (shellcode.size() < 50) {
    gameFile.put(0x90); // NOP
    shellcode.push_back(0x90);
  }

  // save the strings after the shellcode
  gameFile.seekp((dllNameAddr - BASE_ADDRESS), std::ios::beg);
  gameFile.write(DLL_NAME, strlen(DLL_NAME) + 1);
  gameFile.seekp((funcNameAddr - BASE_ADDRESS), std::ios::beg);
  gameFile.write(FUNC_NAME, strlen(FUNC_NAME) + 1);

  gameFile.close();
  std::cout << "Patching complete! Used addresses from IAT." << std::endl;
  return 0;
}
