#pragma once

#include "../RTTIMeta.hpp"
#include "cl_CoreNode.hpp"

/*
        009c8d1c 40 91 50 00     addr       FUN_00509140
        009c8d20 20 e1 6f 00     addr       FUN_006fe120
        009c8d24 70 14 70 00     addr       FUN_00701470
        009c8d28 90 14 70 00     addr       FUN_00701490
        009c8d2c e0 7d 74 00     addr       FUN_00747de0
        009c8d30 a0 10 40 00     addr       FUN_004010a0
        009c8d34 10 8d 50 00     addr       LAB_00508d10
        
        009c8d38 70 8f 50 00     addr       FUN_00508f70
        009c8d3c d0 8d 50 00     addr       FUN_00508dd0
        009c8d40 10 8e 50 00     addr       FUN_00508e10
        009c8d44 b0 93 50 00     addr       FUN_005093b0
        009c8d48 50 f1 6f 00     addr       FUN_006ff150
        009c8d4c 00 0f 70 00     addr       FUN_00700f00
        009c8d50 30 89 50 00     addr       FUN_00508930
        009c8d54 60 89 50 00     addr       FUN_00508960
        009c8d58 90 89 50 00     addr       FUN_00508990
        009c8d5c c0 89 50 00     addr       FUN_005089c0
        009c8d60 50 22 7a 00     addr       LAB_007a2250
        
        009c8d64 f0 90 50 00     addr       LAB_005090f0
        009c8d68 f0 89 50 00     addr       FUN_005089f0
        009c8d6c 30 e0 5c 00     addr       FUN_005ce030
        009c8d70 a0 01 70 00     addr       LAB_007001a0
        009c8d74 50 0b 70 00     addr       FUN_00700b50
        009c8d78 a0 fb 6f 00     addr       FUN_006ffba0
        009c8d7c 70 fb 6f 00     addr       FUN_006ffb70
        009c8d80 60 05 70 00     addr       LAB_00700560
        009c8d84 80 05 70 00     addr       LAB_00700580
        009c8d88 00 0c 70 00     addr       FUN_00700c00
        009c8d8c 80 00 70 00     addr       LAB_00700080
        009c8d90 f0 05 70 00     addr       LAB_007005f0
        009c8d94 d0 f6 6f 00     addr       LAB_006ff6d0
        
        009c8d98 c0 e0 6f 00     addr       FUN_006fe0c0
        009c8d9c 10 e2 6f 00     addr       LAB_006fe210
        
        009c8da0 10 8a 50 00     addr       FUN_00508a10
        009c8da4 20 8d 50 00     addr       FUN_00508d20
        009c8da8 50 8d 50 00     addr       FUN_00508d50
        009c8dac 20 8a 50 00     addr       FUN_00508a20
        009c8db0 40 8a 50 00     addr       FUN_00508a40
        009c8db4 60 8a 50 00     addr       FUN_00508a60
        009c8db8 70 8a 50 00     addr       FUN_00508a70
        009c8dbc 00 91 50 00     addr       LAB_00509100
        009c8dc0 10 91 50 00     addr       LAB_00509110
        009c8dc4 20 91 50 00     addr       LAB_00509120
        009c8dc8 40 f9 6e 00     addr       FUN_006ef940
        009c8dcc a0 19 57 00     addr       FUN_005719a0
        009c8dd0 a0 8a 50 00     addr       FUN_00508aa0
        009c8dd4 20 b4 4f 00     addr       FUN_004fb420
        009c8dd8 e0 8a 50 00     addr       FUN_00508ae0
        009c8ddc 70 8d 50 00     addr       FUN_00508d70
        009c8de0 90 8b 50 00     addr       FUN_00508b90
        009c8de4 90 58 49 00     addr       FUN_00495890
        009c8de8 30 91 50 00     addr       LAB_00509130
        009c8dec b0 8b 50 00     addr       FUN_00508bb0
        009c8df0 90 8d 50 00     addr       FUN_00508d90
        009c8df4 80 8c 50 00     addr       FUN_00508c80
        009c8df8 80 cd 70 00     addr       FUN_0070cd80
        009c8dfc 60 b2 5c 00     addr       FUN_005cb260
        009c8e00 b0 8c 50 00     addr       FUN_00508cb0
        009c8e04 e0 8c 50 00     addr       FUN_00508ce0
        009c8e08 20 b4 4f 00     addr       FUN_004fb420
        009c8e0c a0 19 57 00     addr       FUN_005719a0

*/

class cl_SimObject : public cl_CoreNode {
public:
	GENERATE_VTABLE_PADDING(pad_cl_Root, 7)
	GENERATE_VTABLE_PADDING(pad_cl_Serializable, 11)
	GENERATE_VTABLE_PADDING(pad_cl_PropertyHolder, 13)
	GENERATE_VTABLE_PADDING(pad_cl_CoreNode, 2)
	GENERATE_VTABLE_PADDING(pad_cl_SimObject, 28)
	uint8_t padding[80];
};

static_assert(sizeof(cl_SimObject) == 0x94, "cl_SimObject has invalid size"); // 148
