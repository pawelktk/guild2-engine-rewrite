#!/bin/bash
i686-w64-mingw32-g++ -I ./include/ -c lua.cpp -o lua.o -Wno-write-strings -Wno-invalid-offsetof
i686-w64-mingw32-g++ -I ./include/ -c GuildGameScriptBinding.cpp -o GuildGameScriptBinding.o -Wno-write-strings -Wno-invalid-offsetof
i686-w64-mingw32-g++ -I ./include/ -c ScriptManagerUtil.cpp -o ScriptManagerUtil.o -Wno-write-strings -Wno-invalid-offsetof
i686-w64-mingw32-g++ -I ./include/ -c MyMod.cpp -o MyMod.o -Wno-write-strings -Wno-invalid-offsetof
i686-w64-mingw32-g++ -I ./include/ -c LogSystem.cpp -o LogSystem.o -Wno-write-strings -Wno-invalid-offsetof
i686-w64-mingw32-g++ GuildGameScriptBinding.o ScriptManagerUtil.o lua.o LogSystem.o MyMod.o -o MyMod.dll -shared -static