#include "../ScriptManagerUtil.hpp"
#include "../lua.hpp"

#include "../LogSystem.hpp"

#include "../Classes/cl_GuildObject.hpp"
#include "../RTTIInternalDynamicCast.hpp"

int __cdecl GetHP(lua_State *L) {
  ScriptManager_InitDebugInfo_magic(L, ".\\SourceCode\\GuildGameObjectsScript\\GuildGameScriptBinding.cpp", 12006, 1);

  /*void *pObject = ResolveObjectFromAlias(L, 1, 0, 1);
  pObject = IsInstanceOf(pObject, TYPE_CL_GUILDOBJECT);
  */
  cl_GuildObject *pObject = internal_dynamic_cast<cl_GuildObject>(ResolveObjectFromAlias(L, 1, 0, 1));

  double hpValue;

  if (pObject == nullptr) {
    hpValue = -1.0;
  } else {
    hpValue = pObject->GetHP(); //GuildObject_GetHP(pObject);
  }

#ifdef GUILDGAMESCRIPTBINDING_ADDITIONAL_DBG
  if (hpValue == -1.0) {
    ER_LogWarning("@ADDITIONAL_DBG GetHP(%s) - Got hpValue == -1", lua_tostring(L, 1));
  }
#endif

  lua_pushnumber(L, hpValue);
  return 1;
}
