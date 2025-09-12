#pragma once

#include "../RTTIMeta.hpp"


/*
        009abb1c 30 88 40 00     addr       FUN_00408830
        009abb20 d0 10 40 00     addr       FUN_004010d0
        009abb24 70 14 70 00     addr       FUN_00701470
        009abb28 90 14 70 00     addr       FUN_00701490
        009abb2c e0 7d 74 00     addr       FUN_00747de0
        009abb30 a0 10 40 00     addr       FUN_004010a0
        009abb34 d0 13 70 00     addr       LAB_007013d0
*/
#pragma pack(push, 1)
class cl_Root {
public:
	GENERATE_VTABLE_PADDING(pad_cl_Root, 7)
	uint32_t refCount; // not sure, but looks like a ref count to me
};
#pragma pack(pop)
static_assert(sizeof(cl_Root) == 8, "cl_Root has invalid size");