#include "../ScriptManagerUtil.hpp"
#include "../RTTIInternalDynamicCast.hpp"
#include "../lua.hpp"
#include "../LogSystem.hpp"

auto GuildObject_GetHPRelative =
    reinterpret_cast<float(__fastcall *)(void *this_ptr)>(0x0062e700);

int __cdecl GetHPRelative(lua_State *L) {
  ScriptManager_InitDebugInfo_magic(
      L, ".\\SourceCode\\GuildGameObjectsScript\\GuildGameScriptBinding.cpp",
      12026, 1);

  //void *pObject = ResolveObjectFromAlias(L, 1, 0, 1);
  //pObject = IsInstanceOf(pObject, TYPE_CL_GUILDOBJECT);
  cl_GuildObject *pObject = internal_dynamic_cast<cl_GuildObject>(ResolveObjectFromAlias(L, 1, 0, 1));
  double hpValue;

  if (pObject == nullptr) {
    hpValue = -1.0;
  } else {
    hpValue = GuildObject_GetHPRelative(pObject);
  }
  
  #ifdef GUILDGAMESCRIPTBINDING_ADDITIONAL_DBG
  	if(hpValue==-1.0){
  		ER_LogWarning("@ADDITIONAL_DBG GetHPRelative(%s) - Got hpValue == -1", lua_tostring(L,1));
  	}
  #endif

  lua_pushnumber(L, hpValue);
  return 1;
}
