#pragma once

#include "../RTTIMeta.hpp"
#include "cl_Serializable.hpp"

/*
        009f4ebc 50 7d 6d 00     addr       FUN_006d7d50
        009f4ec0 d0 10 40 00     addr       FUN_004010d0
        009f4ec4 70 14 70 00     addr       FUN_00701470
        009f4ec8 90 14 70 00     addr       FUN_00701490
        009f4ecc e0 7d 74 00     addr       FUN_00747de0
        009f4ed0 a0 10 40 00     addr       FUN_004010a0
        009f4ed4 10 fc 6f 00     addr       LAB_006ffc10
        
        009f4ed8 a0 f6 6f 00     addr       FUN_006ff6a0
        009f4edc b0 b9 70 00     addr       FUN_0070b9b0
        009f4ee0 d0 fb 6f 00     addr       FUN_006ffbd0
        009f4ee4 f0 fb 6f 00     addr       FUN_006ffbf0
        009f4ee8 10 fd 6f 00     addr       FUN_006ffd10
        009f4eec 00 0f 70 00     addr       FUN_00700f00
        009f4ef0 e0 f5 6f 00     addr       FUN_006ff5e0
        009f4ef4 10 f6 6f 00     addr       FUN_006ff610
        009f4ef8 40 f6 6f 00     addr       FUN_006ff640
        009f4efc 70 f6 6f 00     addr       FUN_006ff670
        009f4f00 50 22 7a 00     addr       LAB_007a2250
        
        009f4f04 80 cd 70 00     addr       FUN_0070cd80
        009f4f08 e0 c2 96 00     addr       FUN_0096c2e0
        009f4f0c 30 e0 5c 00     addr       FUN_005ce030
        009f4f10 a0 01 70 00     addr       LAB_007001a0
        009f4f14 50 0b 70 00     addr       FUN_00700b50
        009f4f18 a0 fb 6f 00     addr       FUN_006ffba0
        009f4f1c 70 fb 6f 00     addr       FUN_006ffb70
        009f4f20 60 05 70 00     addr       LAB_00700560
        009f4f24 80 05 70 00     addr       LAB_00700580
        009f4f28 00 0c 70 00     addr       FUN_00700c00
        009f4f2c 80 00 70 00     addr       LAB_00700080
        009f4f30 f0 05 70 00     addr       LAB_007005f0
        009f4f34 d0 f6 6f 00     addr       LAB_006ff6d0

*/
#pragma pack(push, 1)
class cl_PropertyHolder : public cl_Serializable {
public:
  GENERATE_VTABLE_PADDING(pad_cl_Root, 7)
  GENERATE_VTABLE_PADDING(pad_cl_Serializable, 11)
  GENERATE_VTABLE_PADDING(pad_cl_PropertyHolder, 13)
  // offset after cl_Serializable: 0x18 == 24
  uint8_t padding[8];
};
#pragma pack(pop)
static_assert(sizeof(cl_PropertyHolder) == 0x20, "cl_PropertyHolder has invalid size"); // 32
