#pragma once

#include "../RTTIMeta.hpp"
#include "cl_Root.hpp"

/*
        009aac98 90 01 59 00     addr       FUN_00590190
        009aac9c d0 10 40 00     addr       FUN_004010d0
        009aaca0 70 14 70 00     addr       FUN_00701470
        009aaca4 90 14 70 00     addr       FUN_00701490
        009aaca8 e0 7d 74 00     addr       FUN_00747de0
        009aacac a0 10 40 00     addr       FUN_004010a0
        009aacb0 80 4e 70 00     addr       FUN_00704e80
*/
#pragma pack(push, 1)
class cl_RootRef : public cl_Root {
public:
  GENERATE_VTABLE_PADDING(pad_cl_Root, 7)
  uint8_t padding[16];
};
#pragma pack(pop)
static_assert(sizeof(cl_RootRef) == 0x18, "cl_RootRef has invalid size"); // 24
