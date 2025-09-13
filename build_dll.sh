#!/bin/bash
#i686-w64-mingw32-g++ -I ./include/ -c lua.cpp -o lua.o -Wno-write-strings -Wno-invalid-offsetof
i686-w64-mingw32-g++ -I ./include/ -c GuildGameScriptBinding.cpp -o GuildGameScriptBinding.o -Wno-write-strings -Wno-invalid-offsetof
#i686-w64-mingw32-g++ -I ./include/ -c ScriptManagerUtil.cpp -o ScriptManagerUtil.o -Wno-write-strings -Wno-invalid-offsetof
i686-w64-mingw32-g++ -I ./include/ -c G2ER.cpp -o G2ER.o -Wno-write-strings -Wno-invalid-offsetof
i686-w64-mingw32-g++ -I ./include/ -c LogSystem.cpp -o LogSystem.o -Wno-write-strings -Wno-invalid-offsetof
i686-w64-mingw32-g++ GuildGameScriptBinding.o LogSystem.o G2ER.o -o G2ER.dll -shared -static

