#pragma once

#include "../RTTIMeta.hpp"
#include "cl_SimObject.hpp"

/*
        009d2c74 10 d7 56 00     addr       FUN_0056d710
        009d2c78 20 e1 6f 00     addr       FUN_006fe120
        009d2c7c 70 14 70 00     addr       FUN_00701470
        009d2c80 90 14 70 00     addr       FUN_00701490
        009d2c84 e0 7d 74 00     addr       FUN_00747de0
        009d2c88 a0 10 40 00     addr       FUN_004010a0
        009d2c8c a0 d5 56 00     addr       LAB_0056d5a0
        
        009d2c90 c0 db 56 00     addr       FUN_0056dbc0
        009d2c94 d0 8d 50 00     addr       FUN_00508dd0
        009d2c98 10 8e 50 00     addr       FUN_00508e10
        009d2c9c b0 93 50 00     addr       FUN_005093b0
        009d2ca0 50 f1 6f 00     addr       FUN_006ff150
        009d2ca4 00 0f 70 00     addr       FUN_00700f00
        009d2ca8 d0 d4 56 00     addr       FUN_0056d4d0
        009d2cac 00 d5 56 00     addr       FUN_0056d500
        009d2cb0 30 d5 56 00     addr       FUN_0056d530
        009d2cb4 60 d5 56 00     addr       FUN_0056d560
        009d2cb8 50 22 7a 00     addr       LAB_007a2250
        
        009d2cbc f0 90 50 00     addr       LAB_005090f0
        009d2cc0 f0 89 50 00     addr       FUN_005089f0
        009d2cc4 30 e0 5c 00     addr       FUN_005ce030
        009d2cc8 a0 01 70 00     addr       LAB_007001a0
        009d2ccc 50 0b 70 00     addr       FUN_00700b50
        009d2cd0 a0 fb 6f 00     addr       FUN_006ffba0
        009d2cd4 70 fb 6f 00     addr       FUN_006ffb70
        009d2cd8 60 05 70 00     addr       LAB_00700560
        009d2cdc 80 05 70 00     addr       LAB_00700580
        009d2ce0 00 0c 70 00     addr       FUN_00700c00
        009d2ce4 80 00 70 00     addr       LAB_00700080
        009d2ce8 f0 05 70 00     addr       LAB_007005f0
        009d2cec d0 f6 6f 00     addr       LAB_006ff6d0
        
        009d2cf0 c0 e0 6f 00     addr       FUN_006fe0c0
        009d2cf4 10 e2 6f 00     addr       LAB_006fe210
        
        009d2cf8 70 d7 56 00     addr       FUN_0056d770
        009d2cfc c0 d8 56 00     addr       FUN_0056d8c0
        009d2d00 50 8d 50 00     addr       FUN_00508d50
        009d2d04 20 8a 50 00     addr       FUN_00508a20
        009d2d08 40 8a 50 00     addr       FUN_00508a40
        009d2d0c 60 8a 50 00     addr       FUN_00508a60
        009d2d10 70 8a 50 00     addr       FUN_00508a70
        009d2d14 00 91 50 00     addr       LAB_00509100
        009d2d18 10 91 50 00     addr       LAB_00509110
        009d2d1c 20 91 50 00     addr       LAB_00509120
        009d2d20 40 f9 6e 00     addr       FUN_006ef940
        009d2d24 a0 19 57 00     addr       FUN_005719a0
        009d2d28 90 d5 56 00     addr       thunk_FUN_00508aa0
        009d2d2c 50 d9 56 00     addr       FUN_0056d950
        009d2d30 f0 d9 56 00     addr       FUN_0056d9f0
        009d2d34 70 8d 50 00     addr       FUN_00508d70
        009d2d38 90 8b 50 00     addr       FUN_00508b90
        009d2d3c 90 58 49 00     addr       FUN_00495890
        009d2d40 30 91 50 00     addr       LAB_00509130
        009d2d44 b0 8b 50 00     addr       FUN_00508bb0
        009d2d48 90 8d 50 00     addr       FUN_00508d90
        009d2d4c 80 8c 50 00     addr       FUN_00508c80
        009d2d50 80 cd 70 00     addr       FUN_0070cd80
        009d2d54 60 b2 5c 00     addr       FUN_005cb260
        009d2d58 b0 8c 50 00     addr       FUN_00508cb0
        009d2d5c e0 8c 50 00     addr       FUN_00508ce0
        009d2d60 20 b4 4f 00     addr       FUN_004fb420
        009d2d64 a0 19 57 00     addr       FUN_005719a0

*/

class cl_ScriptSimObject : public cl_SimObject {
public:
	GENERATE_VTABLE_PADDING(pad_cl_Root, 7)
	GENERATE_VTABLE_PADDING(pad_cl_Serializable, 11)
	GENERATE_VTABLE_PADDING(pad_cl_PropertyHolder, 13)
	GENERATE_VTABLE_PADDING(pad_cl_CoreNode, 2)
	GENERATE_VTABLE_PADDING(pad_cl_SimObject, 28)
	uint8_t padding[52];
};

static_assert(sizeof(cl_ScriptSimObject) == 0xc8, "cl_ScriptSimObject has incorrect size"); // 200
