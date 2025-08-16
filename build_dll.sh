#!/bin/bash
i686-w64-mingw32-g++ -c lua.cpp -o lua.o -Wno-write-strings
i686-w64-mingw32-g++ -c GuildGameScriptBinding.cpp -o GuildGameScriptBinding.o -Wno-write-strings
i686-w64-mingw32-g++ -c ScriptManagerUtil.cpp -o ScriptManagerUtil.o -Wno-write-strings
i686-w64-mingw32-g++ -c MyMod.cpp -o MyMod.o -Wno-write-strings
i686-w64-mingw32-g++ GuildGameScriptBinding.o ScriptManagerUtil.o lua.o MyMod.o -o MyMod.dll -shared -static -Wno-write-strings