#pragma once
#include <cstdarg>
#include <utility>

extern void*(__cdecl* LogSystem_GetInstance)();

extern void(__cdecl* LogSystem_LogWarning)(
    void *pLogSystem,
    const char* format,
    ...
);


// our own LogWarning wrapper function for verbose debugging
template<typename... Args> 
void ER_LogWarning(const char *fmt, Args&&... args){
    void *pLogSystem = LogSystem_GetInstance();
    
    LogSystem_LogWarning(pLogSystem, fmt, std::forward<Args>(args)...);
	
}