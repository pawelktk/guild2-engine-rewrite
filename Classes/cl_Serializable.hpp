#pragma once

#include "../RTTIMeta.hpp"
#include "cl_RootRef.hpp"

/*
        009d5e1c 80 ce 57 00     addr       FUN_0057ce80
        009d5e20 d0 10 40 00     addr       FUN_004010d0
        009d5e24 70 14 70 00     addr       FUN_00701470
        009d5e28 90 14 70 00     addr       FUN_00701490
        009d5e2c e0 7d 74 00     addr       FUN_00747de0
        009d5e30 a0 10 40 00     addr       FUN_004010a0
        009d5e34 40 10 70 00     addr       LAB_00701040
        
        009d5e38 e0 c2 96 00     addr       FUN_0096c2e0
        009d5e3c 50 10 70 00     addr       FUN_00701050
        009d5e40 80 10 70 00     addr       FUN_00701080
        009d5e44 a0 10 70 00     addr       FUN_007010a0
        009d5e48 c0 10 70 00     addr       FUN_007010c0
        009d5e4c a0 19 57 00     addr       FUN_005719a0
        009d5e50 a0 19 57 00     addr       FUN_005719a0
        009d5e54 a0 19 57 00     addr       FUN_005719a0
        009d5e58 a0 19 57 00     addr       FUN_005719a0
        009d5e5c a0 19 57 00     addr       FUN_005719a0
        009d5e60 50 22 7a 00     addr       LAB_007a2250
*/

// IMPORTANT!!!!
// In game binary the name of the class is mistyped as "cl_Serializeable".
// I'm leaving the name without the typo, but it should be noted it's different in the game files.
// Also, in FUN_004fa2f0 (tolua bindings) it uses the correct name "cl_Serializable"
#pragma pack(push, 1)
class cl_Serializable : public cl_RootRef {
public:
  GENERATE_VTABLE_PADDING(pad_cl_Root, 7)
  GENERATE_VTABLE_PADDING(pad_cl_Serializable, 11)
};
#pragma pack(pop)
static_assert(sizeof(cl_Serializable) == 0x18, "cl_Serializable has invalid size"); // 24
