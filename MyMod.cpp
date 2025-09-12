#define WIN32_LEAN_AND_MEAN


#include <cstdio>
#include "GuildGameScriptBinding.hpp"
#include "Classes/cl_GuildObject.hpp"
#include "ScriptManagerUtil.hpp"
#include <windows.h>

#include "LogSystem.hpp"

static bool firstLoaded = true;




extern "C" __declspec(dllexport) void __cdecl MyMod_GuildGameScriptBinding(lua_State *L) {
	if(firstLoaded){
		ER_LogWarning("@G2ER Using GuildGameScriptBinding from Guild2EngineRewrite");
		#ifdef GUILDGAMESCRIPTBINDING_ADDITIONAL_DBG
    		ER_LogWarning("@ADDITIONAL_DBG Additional warnings will be displayed");
    	#endif
		firstLoaded = false;
	}
    GuildGameScriptBinding(L);
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
