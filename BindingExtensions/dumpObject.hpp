#define WIN32_LEAN_AND_MEAN
/*#include <windows.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>
*/
#include "../lua.hpp"
#include "../ScriptManagerUtil.hpp"

/*void dumpMemory(void* pObject, uint32_t size, FILE* outFile) {
    uint8_t* ptr = (uint8_t*)pObject;

    fprintf(outFile,
        "%-12s %-11s %-12s %-12s %-12s %-8s | %-12s %-12s %-12s %-12s\n",
        "ADDRESS", "BYTES", "INT", "UINT", "FLOAT", "CHARS",
        "PTR->INT", "PTR->UINT", "PTR->FLOAT", "PTR->STR");

    fprintf(outFile,
        "-----------------------------------------------------------------------------------------------"
        "---------------------------------------------------\n");

    for (uint32_t i = 0; i < size; i += 4) {
        uint8_t* chunk = ptr + i;
        uint32_t remaining = (size - i >= 4) ? 4 : (size - i);

        int32_t asInt = 0;
        uint32_t asUInt = 0;
        float asFloat = 0.0f;
        char asChars[5] = {0};

        for (uint32_t j = 0; j < remaining; j++) {
            ((uint8_t*)&asInt)[j] = chunk[j];
            ((uint8_t*)&asUInt)[j] = chunk[j];
            ((uint8_t*)&asFloat)[j] = chunk[j];
            asChars[j] = (chunk[j] >= 32 && chunk[j] <= 126) ? (char)chunk[j] : '.';
        }


        void* possiblePtr = (void*)(uintptr_t)asUInt;

        char ptrInt[32] = "N/A";
        char ptrUInt[32] = "N/A";
        char ptrFloat[32] = "N/A";
        char ptrStr[32] = "N/A";

        if (remaining == 4 && !IsBadReadPtr(possiblePtr, sizeof(uint32_t))) {
            __try {
                int32_t* pi = (int32_t*)possiblePtr;
                uint32_t* pu = (uint32_t*)possiblePtr;
                float* pf = (float*)possiblePtr;
                snprintf(ptrInt, sizeof(ptrInt), "%d", *pi);
                snprintf(ptrUInt, sizeof(ptrUInt), "%u", *pu);
                snprintf(ptrFloat, sizeof(ptrFloat), "%f", *pf);

                if (!IsBadReadPtr(possiblePtr, 10)) {
                    char buf[11] = {0};
                    strncpy(buf, (char*)possiblePtr, 10);
                    for (int k = 0; k < 10; k++) {
                        if (buf[k] < 32 || buf[k] > 126) buf[k] = '.';
                    }
                    snprintf(ptrStr, sizeof(ptrStr), "\"%s\"", buf);
                }
            } __except (EXCEPTION_EXECUTE_HANDLER) {
                // "N/A"
            }
        }

        char bytesStr[16] = {0};
        char* bp = bytesStr;
        for (uint32_t j = 0; j < remaining; j++) {
            bp += sprintf(bp, "%02X", chunk[j]);
            if (j < remaining - 1) *bp++ = ' ';
        }

        fprintf(outFile,
            "0x%-10p %-11s %-12d %-12u %-12.6f %-8s | %-12s %-12s %-12s %-12s\n",
            (void*)chunk, bytesStr, asInt, asUInt, asFloat, asChars,
            ptrInt, ptrUInt, ptrFloat, ptrStr);
    }
}*/


int __cdecl dumpObject(lua_State *L){
	//void *pObject = ResolveObjectFromAlias(L, 1, 0, 1);
	return 0;
}

