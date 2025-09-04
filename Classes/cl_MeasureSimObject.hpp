#pragma once

#include "../RTTIMeta.hpp"
#include "cl_ScriptSimObject.hpp"

/* 
        009ce1cc a0 82 54 00     addr       FUN_005482a0
        009ce1d0 20 e1 6f 00     addr       FUN_006fe120
        009ce1d4 70 14 70 00     addr       FUN_00701470
        009ce1d8 90 14 70 00     addr       FUN_00701490
        009ce1dc e0 7d 74 00     addr       FUN_00747de0
        009ce1e0 a0 10 40 00     addr       FUN_004010a0
        009ce1e4 b0 51 54 00     addr       LAB_005451b0
        
        009ce1e8 c0 db 56 00     addr       FUN_0056dbc0
        009ce1ec f0 60 54 00     addr       FUN_005460f0
        009ce1f0 f0 6c 54 00     addr       FUN_00546cf0
        009ce1f4 70 87 54 00     addr       FUN_00548770
        009ce1f8 10 a3 54 00     addr       FUN_0054a310
        009ce1fc e0 a2 54 00     addr       FUN_0054a2e0
        009ce200 d0 d4 56 00     addr       FUN_0056d4d0
        009ce204 00 d5 56 00     addr       FUN_0056d500
        009ce208 30 d5 56 00     addr       FUN_0056d530
        009ce20c 60 d5 56 00     addr       FUN_0056d560
        009ce210 50 22 7a 00     addr       LAB_007a2250
        
        009ce214 f0 90 50 00     addr       LAB_005090f0
        009ce218 f0 89 50 00     addr       FUN_005089f0
        009ce21c 30 e0 5c 00     addr       FUN_005ce030
        009ce220 a0 01 70 00     addr       LAB_007001a0
        009ce224 50 0b 70 00     addr       FUN_00700b50
        009ce228 a0 fb 6f 00     addr       FUN_006ffba0
        009ce22c 70 fb 6f 00     addr       FUN_006ffb70
        009ce230 60 05 70 00     addr       LAB_00700560
        009ce234 80 05 70 00     addr       LAB_00700580
        009ce238 00 0c 70 00     addr       FUN_00700c00
        009ce23c 80 00 70 00     addr       LAB_00700080
        009ce240 f0 05 70 00     addr       LAB_007005f0
        009ce244 d0 f6 6f 00     addr       LAB_006ff6d0
        
        009ce248 c0 e0 6f 00     addr       FUN_006fe0c0
        009ce24c 10 e2 6f 00     addr       LAB_006fe210
        
        009ce250 f0 a2 54 00     addr       FUN_0054a2f0
        009ce254 b0 5e 54 00     addr       FUN_00545eb0
        009ce258 c0 51 54 00     addr       FUN_005451c0
        009ce25c 20 8a 50 00     addr       FUN_00508a20
        009ce260 40 8a 50 00     addr       FUN_00508a40
        009ce264 60 8a 50 00     addr       FUN_00508a60
        009ce268 70 8a 50 00     addr       FUN_00508a70
        009ce26c 00 91 50 00     addr       LAB_00509100
        009ce270 10 91 50 00     addr       LAB_00509110
        009ce274 20 91 50 00     addr       LAB_00509120
        009ce278 c0 82 54 00     addr       FUN_005482c0
        009ce27c a0 19 57 00     addr       FUN_005719a0
        009ce280 40 69 54 00     addr       FUN_00546940
        009ce284 d0 51 54 00     addr       LAB_005451d0
        009ce288 e0 51 54 00     addr       LAB_005451e0
        009ce28c 70 8d 50 00     addr       FUN_00508d70
        009ce290 90 8b 50 00     addr       FUN_00508b90
        009ce294 90 58 49 00     addr       FUN_00495890
        009ce298 30 91 50 00     addr       LAB_00509130
        009ce29c b0 8b 50 00     addr       FUN_00508bb0
        009ce2a0 90 8d 50 00     addr       FUN_00508d90
        009ce2a4 80 8c 50 00     addr       FUN_00508c80
        009ce2a8 80 cd 70 00     addr       FUN_0070cd80
        009ce2ac 60 b2 5c 00     addr       FUN_005cb260
        009ce2b0 b0 8c 50 00     addr       FUN_00508cb0
        009ce2b4 e0 8c 50 00     addr       FUN_00508ce0
        009ce2b8 20 b4 4f 00     addr       FUN_004fb420
        009ce2bc a0 19 57 00     addr       FUN_005719a0
        
        009ce2c0 80 7d 54 00     addr       FUN_00547d80
        009ce2c4 b0 6f 54 00     addr       FUN_00546fb0
        009ce2c8 40 f9 6e 00     addr       FUN_006ef940
        009ce2cc 50 5f 54 00     addr       FUN_00545f50
        009ce2d0 40 77 74 00     addr       FUN_00747740
        009ce2d4 40 52 54 00     addr       LAB_00545240
        009ce2d8 a0 72 54 00     addr       FUN_005472a0
        009ce2dc 10 8c 54 00     addr       LAB_00548c10
        009ce2e0 20 80 54 00     addr       LAB_00548020
        009ce2e4 60 8c 54 00     addr       FUN_00548c60
        009ce2e8 30 e0 5c 00     addr       FUN_005ce030
        009ce2ec 30 e0 5c 00     addr       FUN_005ce030
        009ce2f0 70 2b 4f 00     addr       FUN_004f2b70
        009ce2f4 60 52 54 00     addr       LAB_00545260
        009ce2f8 f0 52 54 00     addr       FUN_005452f0
        009ce2fc 80 53 54 00     addr       FUN_00545380
        009ce300 a0 19 57 00     addr       FUN_005719a0
        009ce304 20 b4 4f 00     addr       FUN_004fb420
        009ce308 d0 5e 54 00     addr       FUN_00545ed0
        009ce30c 70 5f 54 00     addr       FUN_00545f70

*/

class cl_MeasureSimObject : public cl_ScriptSimObject {
public:
	GENERATE_VTABLE_PADDING(pad_cl_Root, 7)
	GENERATE_VTABLE_PADDING(pad_cl_Serializable, 11)
	GENERATE_VTABLE_PADDING(pad_cl_PropertyHolder, 13)
	GENERATE_VTABLE_PADDING(pad_cl_CoreNode, 2)
	GENERATE_VTABLE_PADDING(pad_cl_SimObject, 28)
	GENERATE_VTABLE_PADDING(pad_cl_MeasureSimObject, 20)
	uint8_t padding[124];
};

static_assert(sizeof(cl_MeasureSimObject) == 0x144, "cl_MeasureSimObject has incorrect size"); // 324
