#include "ScriptManagerUtil.hpp"


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

void*(__cdecl* IsInstanceOf)(
  void *object,
  char **class_name
) = reinterpret_cast<void*(__cdecl*)(void*, char**)>(0x00701420);