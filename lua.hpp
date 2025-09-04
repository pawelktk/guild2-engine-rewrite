#pragma once

struct lua_State {};
typedef int (*lua_CFunction) (lua_State *L);

#define LUA_GLOBALSINDEX -0x2711
#define lua_Number double

extern void(__cdecl* lua_pushcclosure)(lua_State*, lua_CFunction, int);
extern void(__cdecl* lua_pushstring)(lua_State *L, const char *s);
extern void(__cdecl* lua_insert)(lua_State *L, int idx);
extern void(__cdecl* lua_settable)(lua_State *L, int idx);

extern void(__cdecl* lua_pushnumber)(lua_State *L,lua_Number n);


extern lua_Number(__cdecl* lua_tonumber)(lua_State *L,int idx);
extern char *(__cdecl* lua_tostring)(lua_State *L,int idx);