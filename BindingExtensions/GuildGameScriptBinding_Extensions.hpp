#pragma once

#include "../lua.hpp"

#include "../ScriptManagerUtil.hpp"
#include "./dumpObject.hpp"
#include <cstdint>
#include <map>
#include <string>

void registerExtension(lua_State *L, lua_CFunction func, const char *name) {
  lua_pushcclosure(L, func, 0);
  lua_pushstring(L, name);
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);
}

DEFINE_CDECL_FUNC(int *, ns_GetCoreInstance, 0x00704af0, void);
DEFINE_THISCALL_FUNC(void *, ns_GetNode, 0x00704030, void *pThis, const char *path, bool flag);
DEFINE_THISCALL_FUNC(void, ns_SetOptionRaw, 0x005024a0, void *pThis, const char *header, const char *option, float value);

// quick and hacky way to set the game speed without any restrictions
// press '-' to update the game speed after running this
// used for quick testing of the simulation
int SetGameSpeed(lua_State *L) {
  ScriptManager_InitDebugInfo_magic(L, "whatever_its_not_even_used", 12345, 1);
  float speed = ReadFloatArgument(L, 1, 1.0, 1);
  void *core = ns_GetCoreInstance();
  //TODO some checks for nullptrs and dynamic cast after I define i_Game class
  void *game = ns_GetNode(core, "\\application\\game", true);
  ns_SetOptionRaw(game, "OPTIONS", "GameSpeed", speed);
  return 0;
}

DEFINE_THISCALL_FUNC(void *, ns_GetController, 0x00502a80, void *pThis, const char *name);
DEFINE_THISCALL_FUNC(void *, internalQuickSave, 0x004057b0, void *pThis);
int Quicksave(lua_State *L) {
	ScriptManager_InitDebugInfo_magic(L, "whatever_its_not_even_used", 12345, 1);
	void *core = ns_GetCoreInstance();
	void *game = ns_GetNode(core, "\\application\\game", true);
	void *gic = ns_GetController(game, "GeneralInputCtrl");
	internalQuickSave(gic);
	return 0;
}

/*int BuildingSetAISettingProduce(lua_State *L){
	ScriptManager_InitDebugInfo_magic(L, "whatever_its_not_even_used", 12345, 1);
	bool toggle = ReadBoolArgument(L, 2, true, 1);
	void *pBuilding = (void*)ResolveObjectFromAlias(L, 1, 0, 1);
	if (pBuilding!=nullptr){
		*((uint8_t*)((int)pBuilding+0x58d)) = (uint8_t)toggle;
	}
	return 0;
}*/

// sets the ai management options
// those can be either 0 or 1 for the higher level options (Enable, BuySell, Workers, Budget, Produce)
// the lower level options get set automatically to -1 if the higher order option is disabled
// the lower level options also can have higher values if they have more than 1 option
// eg. Sales and purchases:
// 0 - "Not at all"
// 1 - "In the city"
// 2 - "On the whole map
// they more or less correspond to their place in ai management menu
// Usage in lua: BuildingSetAISetting([Alias of type cl_Building] pBuilding, string option, Number setTo)
// eg. BuildingSetAISetting("", "Produce", 0) disables the AI management of production completelly for building of alias ""
int BuildingSetAISetting(lua_State *L) {
  ScriptManager_InitDebugInfo_magic(L, "whatever_its_not_even_used", 12345, 1);

  std::string option = ReadStringArgument(L, 2, "", 1);
  int setTo = ReadIntArgument(L, 3, 1, 1);
  // TODO make use of the cl_Building after I implement it insead of using raw voidptrs
  void *pBuilding = (void *)ResolveObjectFromAlias(L, 1, 0, 1);

  if (!pBuilding)
    return 0;

  static const std::map<std::string, std::uintptr_t> optionOffsets = {
      {"Enable",             0x163},
      {"BuySell",            0x164},
      {"BuySell_Radius",     0x591},
      {"BuySell_PriceLevel", 0x592},
      {"BuySell_SellStock",  0x593},
      {"BuySell_Carts",      0x165},
      {"Workers",            0x595},
      {"Workers_Quality",    0x596},
      {"Workers_Favor",      0x597},
      {"Budget",             0x166},
      {"Budget_Repair",      0x599},
      {"Budget_Upgrades",    0x59a},
      {"Produce",            0x58d},
      {"Produce_Selection",  0x58e},
      {"Produce_Stock",      0x58f},
  };

  auto it = optionOffsets.find(option);
  if (it != optionOffsets.end()) {
    size_t offset = it->second;
    *((int8_t *)((uintptr_t)pBuilding + offset)) = (int8_t)setTo;
  }

  return 0;
}

int RunLua(lua_State *L){
	ScriptManager_InitDebugInfo_magic(L, "whatever_its_not_even_used", 12345, 1);
	std::string toRun = ReadStringArgument(L, 1, "", 1);
	bool thereAreErrors = true;
	if (toRun!=""){
		thereAreErrors = lua_dostring(L, toRun.c_str());
	}
	lua_pushboolean(L, !thereAreErrors);
	return 1;
}

void GuildGameScriptBinding_RegisterExtensions(lua_State *L) {
  //registerExtension(L, func, "myFunc");
  registerExtension(L, SetGameSpeed, "SetGameSpeed");
  //registerExtension(L, BuildingSetAISettingProduce, "BuildingSetAISettingProduce");
  registerExtension(L, BuildingSetAISetting, "BuildingSetAISetting");
  registerExtension(L, RunLua, "RunLua");
  registerExtension(L, Quicksave, "Quicksave");
}
