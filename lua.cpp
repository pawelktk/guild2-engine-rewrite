#include "lua.hpp"

void(__cdecl* lua_pushcclosure)(lua_State*, lua_CFunction, int) =
    reinterpret_cast<void(__cdecl*)(lua_State*, lua_CFunction, int)>(0x0070ee70);

void(__cdecl* lua_pushstring)(lua_State *L, const char *s) =
    reinterpret_cast<void(__cdecl*)(lua_State*, const char*)>(0x0070eda0);

void(__cdecl* lua_insert)(lua_State *L, int idx) =
    reinterpret_cast<void(__cdecl*)(lua_State*, int)>(0x0070e8e0);

void(__cdecl* lua_settable)(lua_State *L, int idx) =
    reinterpret_cast<void(__cdecl*)(lua_State*, int)>(0x0070f0a0);

void(__cdecl* lua_pushnumber)(lua_State *L,lua_Number n) =
	reinterpret_cast<void(__cdecl*)(lua_State*, lua_Number)>(0x0070ed30);