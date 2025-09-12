#pragma once
#include <cstdarg>
#include <cstddef>

struct lua_State {};
typedef int (*lua_CFunction) (lua_State *L);
typedef double lua_Number;
#define LUA_GLOBALSINDEX -0x2711
//#define lua_Number double

#define DEFINE_LUA_API(return_type, name, address, ...) \
    inline return_type(__cdecl* name)(__VA_ARGS__) = \
        reinterpret_cast<return_type(__cdecl*)(__VA_ARGS__)>(address)

DEFINE_LUA_API(void, lua_insert, 0x0070e8e0, lua_State* L, int idx);
DEFINE_LUA_API(void, lua_settable, 0x0070f0a0, lua_State* L, int idx);

DEFINE_LUA_API(void, lua_pushboolean, 0x0070ef00, lua_State* L, int b);
DEFINE_LUA_API(void, lua_pushcclosure, 0x0070ee70, lua_State* L, lua_CFunction fn, int n);
DEFINE_LUA_API(const char*, lua_pushfstring, 0x0070ee40, lua_State* L, const char* fmt, ...);
DEFINE_LUA_API(void, lua_pushlightuserdata, 0x0070ef30, lua_State* L, void* p);
DEFINE_LUA_API(void, lua_pushlstring, 0x0070ed50, lua_State* L, const char* s, size_t l);
DEFINE_LUA_API(void, lua_pushnil, 0x0070ed10, lua_State* L);
DEFINE_LUA_API(void, lua_pushnumber, 0x0070ed30, lua_State* L, lua_Number n);
DEFINE_LUA_API(void, lua_pushstring, 0x0070eda0, lua_State* L, const char* s);
DEFINE_LUA_API(void, lua_pushvalue, 0x0070e990, lua_State* L, int idx);
DEFINE_LUA_API(const char*, lua_pushvfstring, 0x0070ee10, lua_State* L, const char* fmt, va_list argp);

DEFINE_LUA_API(int, lua_toboolean, 0x0070eb80, lua_State* L, int idx);
DEFINE_LUA_API(lua_CFunction, lua_tocfunction, 0x0070ec90, lua_State* L, int idx);
DEFINE_LUA_API(lua_Number, lua_tonumber, 0x0070eb30, lua_State* L, int idx);
DEFINE_LUA_API(const char*, lua_tostring, 0x0070ebc0, lua_State* L, int idx);
DEFINE_LUA_API(void*, lua_touserdata, 0x0070ecd0, lua_State* L, int idx);

DEFINE_LUA_API(int, lua_iscfunction, 0x0070ea20, lua_State* L, int idx);
DEFINE_LUA_API(int, lua_isnumber, 0x0070ea60, lua_State* L, int idx);
DEFINE_LUA_API(int, lua_isstring, 0x0070eab0, lua_State* L, int idx);
DEFINE_LUA_API(int, lua_isuserdata, 0x0070eaf0, lua_State* L, int idx);