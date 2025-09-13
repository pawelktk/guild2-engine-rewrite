#pragma once
#include "lua.hpp"

#define GUILDGAMESCRIPTBINDING_ADDITIONAL_DBG

// clang-format off
#define DEFINE_CDECL_FUNC(return_type, name, address, ...) \
    inline return_type(__cdecl* name)(__VA_ARGS__) = \
        reinterpret_cast<return_type(__cdecl*)(__VA_ARGS__)>(address)


#define DEFINE_THISCALL_FUNC(return_type, name, address, ...) \
    inline return_type(__thiscall* name)(__VA_ARGS__) = \
        reinterpret_cast<return_type(__thiscall*)(__VA_ARGS__)>(address)
// clang-format on

DEFINE_CDECL_FUNC(void, ScriptManager_InitDebugInfo_magic, 0x0053f140, lua_State *L, char *fileName, int lineNumber, int flag);

DEFINE_CDECL_FUNC(void *, ResolveObjectFromAlias, 0x0053efa0, lua_State *L, int idx, int default_val, int print_error_messages);

// Those errors get thrown only in the AID console, pretty useful
DEFINE_CDECL_FUNC(void, ScriptError, 0x0053edb0, lua_State *L, const char *format, ...);

DEFINE_CDECL_FUNC(bool, ReadBoolArgument, 0x0053ef00, lua_State *L, int idx, bool defaultValue, bool print_error_messages);

DEFINE_CDECL_FUNC(float, ReadFloatArgument, 0x0053eeb0, lua_State *L, int idx, float defaultValue, bool print_error_messages);

DEFINE_CDECL_FUNC(int, ReadImpactIDArgument, 0x005fd310, lua_State *L, int idx);

DEFINE_CDECL_FUNC(int, ReadIntArgument, 0x0053ee60, lua_State *L, int idx, int defaultValue, int print_error_messages);

DEFINE_CDECL_FUNC(double, ReadNumberArgument, 0x0053ee10, lua_State *L, int idx, double defaultValue, bool print_error_messages);

DEFINE_CDECL_FUNC(const char *, ReadStringArgument, 0x0053ef50, lua_State *L, int idx, const char *defaultValue, int print_error_messages);
