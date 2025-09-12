#include "ScriptManagerUtil.hpp"

//TODO Remove, deprecated

void(__cdecl* ScriptManager_InitDebugInfo_magic)(
  lua_State *L,
  char *fileName,
  int lineNumber,
  int flag
) = reinterpret_cast<void(__cdecl*)(lua_State*, char*, int, int)>(0x0053f140);

void*(__cdecl* ResolveObjectFromAlias)(
  lua_State *L,
  int idx,
  int default_val,
  int print_error_messages
) = reinterpret_cast<void*(__cdecl*)(lua_State*, int, int, int)>(0x0053efa0);


// Those errors get thrown only in the AID console, pretty useful
void(__cdecl* ScriptError)(
    lua_State* L,
    const char* format,
    ...
) = reinterpret_cast<void(__cdecl*)(lua_State*, const char* format, ...)>(0x0053edb0);