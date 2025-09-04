#include "LogSystem.hpp"
#include <cstdarg>
#include <utility>


void*(__cdecl* LogSystem_GetInstance)() =
    reinterpret_cast<void*(__cdecl*)()>(0x00739a30);

void(__cdecl* LogSystem_LogWarning)(
    void *pLogSystem,
    const char* format,
    ...
) = reinterpret_cast<void(__cdecl*)(void*, const char* format, ...)>(0x00739870);


 