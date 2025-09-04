#pragma once

#include "../lua.hpp"

#include "./dumpObject.hpp"

void registerExtension(lua_State *L, lua_CFunction func, const char *name){
  lua_pushcclosure(L,func,0);
  lua_pushstring(L,name);
  lua_insert(L,-2);
  lua_settable(L,LUA_GLOBALSINDEX);
}


void GuildGameScriptBinding_RegisterExtensions(lua_State *L){
	//registerExtension(L, func, "myFunc");
}