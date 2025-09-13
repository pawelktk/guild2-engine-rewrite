#include "../ScriptManagerUtil.hpp"
#include "../lua.hpp"

#include "../LogSystem.hpp"

#include "../Classes/cl_Sim.hpp"
#include "../RTTIInternalDynamicCast.hpp"

// TODO test it, register it

int __cdecl SimIsInside(lua_State *L) {
  ScriptManager_InitDebugInfo_magic(L, "whatever", 12345, 1);

  cl_GuildObject *pSim = internal_dynamic_cast<cl_Sim>(ResolveObjectFromAlias(L, 1, 0, 1));
  
  if(pSim){
  	auto pBuilding = pSim->GetInsideBuilding();
  	lua_pushboolean(L, pBuilding!=nullptr);
  	return 1;
  }

  lua_boolean(L, 0);
  return 1;
}
