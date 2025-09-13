#pragma once

#include "../RTTIMeta.hpp"
#include "cl_PropertyHolder.hpp"

/*
        009f99cc 90 f5 71 00     addr       FUN_0071f590
        009f99d0 20 e1 6f 00     addr       FUN_006fe120
        009f99d4 70 14 70 00     addr       FUN_00701470
        009f99d8 90 14 70 00     addr       FUN_00701490
        009f99dc e0 7d 74 00     addr       FUN_00747de0
        009f99e0 a0 10 40 00     addr       FUN_004010a0
        009f99e4 20 e2 6f 00     addr       LAB_006fe220
        
        009f99e8 a0 f6 6f 00     addr       FUN_006ff6a0
        009f99ec b0 e5 6f 00     addr       FUN_006fe5b0
        009f99f0 30 e6 6f 00     addr       FUN_006fe630
        009f99f4 a0 ef 6f 00     addr       FUN_006fefa0
        009f99f8 50 f1 6f 00     addr       FUN_006ff150
        009f99fc 00 0f 70 00     addr       FUN_00700f00
        009f9a00 e0 f5 6f 00     addr       FUN_006ff5e0
        009f9a04 10 f6 6f 00     addr       FUN_006ff610
        009f9a08 40 f6 6f 00     addr       FUN_006ff640
        009f9a0c 70 f6 6f 00     addr       FUN_006ff670
        009f9a10 50 22 7a 00     addr       LAB_007a2250
        
        009f9a14 80 cd 70 00     addr       FUN_0070cd80
        009f9a18 e0 c2 96 00     addr       FUN_0096c2e0
        009f9a1c 30 e0 5c 00     addr       FUN_005ce030
        009f9a20 a0 01 70 00     addr       LAB_007001a0
        009f9a24 50 0b 70 00     addr       FUN_00700b50
        009f9a28 a0 fb 6f 00     addr       FUN_006ffba0
        009f9a2c 70 fb 6f 00     addr       FUN_006ffb70
        009f9a30 60 05 70 00     addr       LAB_00700560
        009f9a34 80 05 70 00     addr       LAB_00700580
        009f9a38 00 0c 70 00     addr       FUN_00700c00
        009f9a3c 80 00 70 00     addr       LAB_00700080
        009f9a40 f0 05 70 00     addr       LAB_007005f0
        009f9a44 d0 f6 6f 00     addr       LAB_006ff6d0
        
        009f9a48 c0 e0 6f 00     addr       FUN_006fe0c0
        009f9a4c 10 e2 6f 00     addr       LAB_006fe210
*/
#pragma pack(push, 1)
class cl_CoreNode : public cl_PropertyHolder {
public:
  GENERATE_VTABLE_PADDING(pad_cl_Root, 7)
  GENERATE_VTABLE_PADDING(pad_cl_Serializable, 11)
  GENERATE_VTABLE_PADDING(pad_cl_PropertyHolder, 13)
  GENERATE_VTABLE_PADDING(pad_cl_CoreNode, 2)
  // offset after cl_PropertyHolder: 0x20 == 32
  uint8_t padding_0[28];
  char *name; // 0x3c == 60
  uint8_t padding[4];
};
#pragma pack(pop)

static_assert(offsetof(cl_CoreNode, name) == 0x3c, "Incorrect member offset");

static_assert(sizeof(cl_CoreNode) == 0x44, "cl_CoreNode has invalid size"); // 68
