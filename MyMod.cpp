#define WIN32_LEAN_AND_MEAN


#include <cstdio>
#include "GuildGameScriptBinding.hpp"


#include <windows.h>

int __cdecl MyCustomLuaFunction(lua_State* L) {
    MessageBoxA(NULL, "test", "MyMod.dll", MB_OK);
    return 0;
}


extern "C" __declspec(dllexport) void __cdecl MyMod_GuildGameScriptBinding(lua_State *L) {
	//MessageBoxA(NULL, "GuildGameScriptBinding prolog", "MyMod.dll", MB_OK);
    GuildGameScriptBinding(L);
    //MessageBoxA(NULL, "GuildGameScriptBinding epilog", "MyMod.dll", MB_OK);
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
//MessageBoxA(NULL, "Guild2EngineRewrite Active!", "MyMod.dll", MB_OK);
/*FILE* logfile = fopen("C:\\MyMod.log", "w");
if (logfile) {
    fprintf(logfile, "MyMod.dll loaded!\n");
    fclose(logfile);
}*/
    return TRUE;
}
