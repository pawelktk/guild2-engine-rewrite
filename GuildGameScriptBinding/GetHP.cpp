#include "../ScriptManagerUtil.hpp"
#include "../lua.hpp"

auto GuildObject_GetHP =
    reinterpret_cast<float(__fastcall *)(void *this_ptr)>(0x0062db00);

int __cdecl GetHP(lua_State *L) {
  ScriptManager_InitDebugInfo_magic(
      L, ".\\SourceCode\\GuildGameObjectsScript\\GuildGameScriptBinding.cpp",
      12006, 1);

  void *pObject = ResolveObjectFromAlias(L, 1, 0, 1);
  pObject = IsInstanceOf(pObject, TYPE_CL_GUILDOBJECT);

  double hpValue;

  if (pObject == nullptr) {
    hpValue = -1.0;
  } else {
    hpValue = GuildObject_GetHP(pObject);
  }

  lua_pushnumber(L, hpValue);
  return 1;
}
