#pragma once
#include "lua.hpp"


#define TYPE_CL_GUILDOBJECT (char **)(0x6C63AC)
//inline constexpr char** TYPE_CL_GUILDOBJECT = (char**)(0x00ac63ac);

extern void(__cdecl* ScriptManager_InitDebugInfo_magic)(
  lua_State *L,
  char *fileName,
  int lineNumber,
  int flag
);

extern void*(__cdecl* ResolveObjectFromAlias)(
  lua_State *L,
  int idx,
  int default_val,
  int print_error_messages
);

extern void*(__cdecl* IsInstanceOf)(
  void *object,
  char **class_name
);

