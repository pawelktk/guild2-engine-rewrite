#include "../Classes.hpp"
#include "../LogSystem.hpp"
#include "../RTTIInternalDynamicCast.hpp"
#include "../ScriptManagerUtil.hpp"
#include "../lua.hpp"

int __cdecl SimSetCourtLover(lua_State *L) {
  ScriptManager_InitDebugInfo_magic(L, "whatever_its_not_used_anyway", 12345, 1);

  cl_Sim *firstSim = internal_dynamic_cast<cl_Sim>(ResolveObjectFromAlias(L, 1, 0, 0)); // TODO it shouldn't be optional...

  if (firstSim != nullptr) {
    cl_Sim *secondSim = internal_dynamic_cast<cl_Sim>(ResolveObjectFromAlias(L, 2, 0, 1));
    // TODO i'm pretty sure there should be a second check for a nullptr on secondSim :)
    // I'm leaving this as it is in the game code for now
    if (firstSim->SetCourtLover(secondSim)) {
      lua_pushboolean(L, 1);
      return 1;
    }
  }

  lua_pushboolean(L, 0);
  return 1;
}
