#define WIN32_LEAN_AND_MEAN

#include "Classes/cl_GuildObject.hpp"
#include "GuildGameScriptBinding.hpp"
#include "ScriptManagerUtil.hpp"
#include <cstdio>
#include <windows.h>

#include "LogSystem.hpp"

#include "Profiling.hpp"

static bool firstLoaded = true;

extern "C" __declspec(dllexport) void __cdecl G2ER_GuildGameScriptBinding(lua_State *L) {
  if (firstLoaded) {
  	Profiling::Init();
    ER_LogWarning("@G2ER Using GuildGameScriptBinding from Guild2EngineRewrite");
#ifdef GUILDGAMESCRIPTBINDING_ADDITIONAL_DBG
    ER_LogWarning("@ADDITIONAL_DBG Additional warnings will be displayed");
#endif
    firstLoaded = false;
  }
  GuildGameScriptBinding(L);
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
  return TRUE;
}
