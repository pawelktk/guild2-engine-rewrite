#pragma once

#include "../RTTIMeta.hpp"
#include "cl_GuildObject.hpp"

//TODO Register the vtable padding correctly

/* 
        009e9d84 f0 cb 68 00     addr       FUN_0068cbf0
        009e9d88 20 e1 6f 00     addr       FUN_006fe120
        009e9d8c 70 14 70 00     addr       FUN_00701470
        009e9d90 90 14 70 00     addr       FUN_00701490
        009e9d94 e0 7d 74 00     addr       FUN_00747de0
        009e9d98 a0 10 40 00     addr       FUN_004010a0
        009e9d9c a0 97 68 00     addr       LAB_006897a0
        009e9da0 c0 db 56 00     addr       FUN_0056dbc0
        009e9da4 30 a8 68 00     addr       NiParticleSystemController::RegisterStreamables
        009e9da8 80 a8 68 00     addr       FUN_0068a880
        009e9dac 90 ca 68 00     addr       FUN_0068ca90
        009e9db0 10 a3 54 00     addr       FUN_0054a310
        009e9db4 c0 6c 63 00     addr       FUN_00636cc0
        009e9db8 d0 d4 56 00     addr       FUN_0056d4d0
        009e9dbc 00 d5 56 00     addr       FUN_0056d500
        009e9dc0 30 d5 56 00     addr       FUN_0056d530
        009e9dc4 60 d5 56 00     addr       FUN_0056d560
        009e9dc8 50 22 7a 00     addr       LAB_007a2250
        009e9dcc f0 90 50 00     addr       LAB_005090f0
        009e9dd0 f0 89 50 00     addr       FUN_005089f0
        009e9dd4 30 e0 5c 00     addr       FUN_005ce030
        009e9dd8 a0 01 70 00     addr       LAB_007001a0
        009e9ddc 50 0b 70 00     addr       FUN_00700b50
        009e9de0 a0 fb 6f 00     addr       FUN_006ffba0
        009e9de4 70 fb 6f 00     addr       FUN_006ffb70
        009e9de8 60 05 70 00     addr       LAB_00700560
        009e9dec 80 05 70 00     addr       LAB_00700580
        009e9df0 00 0c 70 00     addr       FUN_00700c00
        009e9df4 80 00 70 00     addr       LAB_00700080
        009e9df8 f0 05 70 00     addr       LAB_007005f0
        009e9dfc d0 f6 6f 00     addr       LAB_006ff6d0
        009e9e00 c0 e0 6f 00     addr       FUN_006fe0c0
        009e9e04 10 e2 6f 00     addr       LAB_006fe210
        009e9e08 30 9c 68 00     addr       FUN_00689c30
        009e9e0c 80 c6 68 00     addr       FUN_0068c680
        009e9e10 c0 51 54 00     addr       FUN_005451c0
        009e9e14 30 ae 68 00     addr       FUN_0068ae30
        009e9e18 40 af 68 00     addr       LAB_0068af40
        009e9e1c 90 9d 68 00     addr       FUN_00689d90
        009e9e20 70 8a 50 00     addr       FUN_00508a70
        009e9e24 00 91 50 00     addr       LAB_00509100
        009e9e28 10 91 50 00     addr       LAB_00509110
        009e9e2c 20 91 50 00     addr       LAB_00509120
        009e9e30 f0 04 63 00     addr       FUN_006304f0
        009e9e34 a0 19 57 00     addr       FUN_005719a0
        009e9e38 60 6d 63 00     addr       FUN_00636d60
        009e9e3c d0 51 54 00     addr       LAB_005451d0
        009e9e40 e0 51 54 00     addr       LAB_005451e0
        009e9e44 10 c3 68 00     addr       FUN_0068c310
        009e9e48 90 8b 50 00     addr       FUN_00508b90
        009e9e4c 50 c3 68 00     addr       FUN_0068c350
        009e9e50 30 91 50 00     addr       LAB_00509130
        009e9e54 e0 9d 68 00     addr       FUN_00689de0
        009e9e58 60 fb 62 00     addr       FUN_0062fb60
        009e9e5c 80 8c 50 00     addr       FUN_00508c80
        009e9e60 30 ae 5e 00     addr       LAB_005eae30
        009e9e64 f0 07 63 00     addr       FUN_006307f0
        009e9e68 b0 8c 50 00     addr       FUN_00508cb0
        009e9e6c e0 8c 50 00     addr       FUN_00508ce0
        009e9e70 20 b4 4f 00     addr       FUN_004fb420
        009e9e74 a0 19 57 00     addr       FUN_005719a0
        009e9e78 80 7d 54 00     addr       FUN_00547d80
        009e9e7c b0 6f 54 00     addr       FUN_00546fb0
        009e9e80 40 f9 6e 00     addr       FUN_006ef940
        009e9e84 50 5f 54 00     addr       FUN_00545f50
        009e9e88 40 77 74 00     addr       FUN_00747740
        009e9e8c 40 52 54 00     addr       LAB_00545240
        009e9e90 a0 72 54 00     addr       FUN_005472a0
        009e9e94 10 8c 54 00     addr       LAB_00548c10
        009e9e98 20 80 54 00     addr       LAB_00548020
        009e9e9c 60 8c 54 00     addr       FUN_00548c60
        009e9ea0 30 e0 5c 00     addr       FUN_005ce030
        009e9ea4 20 c4 68 00     addr       FUN_0068c420
        009e9ea8 70 2b 4f 00     addr       FUN_004f2b70
        009e9eac 60 52 54 00     addr       LAB_00545260
        009e9eb0 f0 52 54 00     addr       FUN_005452f0
        009e9eb4 80 53 54 00     addr       FUN_00545380
        009e9eb8 80 20 63 00     addr       LAB_00632080
        009e9ebc d0 20 63 00     addr       FUN_006320d0
        009e9ec0 50 ad 68 00     addr       FUN_0068ad50
        009e9ec4 70 5f 54 00     addr       FUN_00545f70
        009e9ec8 20 99 68 00     addr       thunk_FUN_0062da60
        009e9ecc 00 40 63 00     addr       FUN_00634000
        009e9ed0 e0 c2 96 00     addr       FUN_0096c2e0
        009e9ed4 60 13 63 00     addr       FUN_00631360
        009e9ed8 e0 c2 96 00     addr       FUN_0096c2e0
        009e9edc 70 df 62 00     addr       FUN_0062df70
        009e9ee0 b0 df 62 00     addr       FUN_0062dfb0
        009e9ee4 d0 e6 62 00     addr       LAB_0062e6d0
        009e9ee8 30 99 68 00     addr       LAB_00689930
        009e9eec 10 d4 6a 00     addr       LAB_006ad410
        009e9ef0 80 cd 70 00     addr       FUN_0070cd80
        009e9ef4 50 ad 5e 00     addr       LAB_005ead50
        009e9ef8 30 e6 62 00     addr       FUN_0062e630
        009e9efc 90 c1 68 00     addr       LAB_0068c190
        009e9f00 e0 da 62 00     addr       LAB_0062dae0
        009e9f04 40 f9 6e 00     addr       FUN_006ef940
        009e9f08 10 ed 62 00     addr       FUN_0062ed10
        009e9f0c 80 ef 62 00     addr       FUN_0062ef80
        009e9f10 f0 ef 62 00     addr       LAB_0062eff0
        009e9f14 f0 ef 62 00     addr       LAB_0062eff0
        009e9f18 10 09 63 00     addr       LAB_00630910
        009e9f1c 60 b2 5c 00     addr       FUN_005cb260
        009e9f20 10 dc 62 00     addr       LAB_0062dc10
        009e9f24 f0 db 62 00     addr       LAB_0062dbf0
        009e9f28 c0 27 63 00     addr       FUN_006327c0
        009e9f2c c0 27 63 00     addr       FUN_006327c0
        009e9f30 20 ae 5e 00     addr       LAB_005eae20
        009e9f34 80 cd 70 00     addr       FUN_0070cd80
        009e9f38 50 22 7a 00     addr       LAB_007a2250
        009e9f3c 20 98 68 00     addr       FUN_00689820
        009e9f40 f0 4c 63 00     addr       FUN_00634cf0
        009e9f44 e0 f0 62 00     addr       FUN_0062f0e0
        009e9f48 50 c7 68 00     addr       FUN_0068c750
        009e9f4c 80 cd 70 00     addr       FUN_0070cd80
        009e9f50 70 ad 5e 00     addr       LAB_005ead70
        009e9f54 a0 ad 5e 00     addr       FUN_005eada0
        009e9f58 d0 ad 5e 00     addr       FUN_005eadd0
        009e9f5c f0 ad 5e 00     addr       LAB_005eadf0
        009e9f60 50 21 63 00     addr       FUN_00632150
        009e9f64 f0 03 63 00     addr       FUN_006303f0
        009e9f68 d0 95 69 00     addr       LAB_006995d0
        009e9f6c 40 04 63 00     addr       LAB_00630440
        009e9f70 30 e7 62 00     addr       LAB_0062e730
        009e9f74 d0 e7 62 00     addr       LAB_0062e7d0
        009e9f78 b0 f1 62 00     addr       LAB_0062f1b0
        009e9f7c 80 cd 70 00     addr       FUN_0070cd80
        009e9f80 80 cd 70 00     addr       FUN_0070cd80
        009e9f84 70 de 62 00     addr       FUN_0062de70
        009e9f88 50 dd 62 00     addr       FUN_0062dd50
        009e9f8c e0 dd 62 00     addr       FUN_0062dde0
        009e9f90 b0 ab 68 00     addr       FUN_0068abb0
        009e9f94 30 09 63 00     addr       FUN_00630930
        009e9f98 50 09 63 00     addr       FUN_00630950
        009e9f9c 50 22 7a 00     addr       LAB_007a2250
        009e9fa0 10 ae 5e 00     addr       LAB_005eae10
        009e9fa4 10 ae 5e 00     addr       LAB_005eae10
        009e9fa8 30 e0 5c 00     addr       FUN_005ce030
        009e9fac a0 a4 68 00     addr       FUN_0068a4a0
        009e9fb0 b0 a5 68 00     addr       LAB_0068a5b0
        009e9fb4 30 a3 68 00     addr       FUN_0068a330
        009e9fb8 40 a1 68 00     addr       LAB_0068a140
        009e9fbc 00 ba 68 00     addr       LAB_0068ba00
        009e9fc0 60 a1 68 00     addr       LAB_0068a160
        009e9fc4 00 a2 68 00     addr       FUN_0068a200
        009e9fc8 60 b6 68 00     addr       FUN_0068b660
        009e9fcc e0 3b 65 00     addr       LAB_00653be0
        009e9fd0 c0 97 68 00     addr       LAB_006897c0
        009e9fd4 e0 83 64 00     addr       LAB_006483e0
        009e9fd8 00 84 64 00     addr       LAB_00648400
        009e9fdc d0 ba 68 00     addr       LAB_0068bad0
        009e9fe0 40 84 64 00     addr       LAB_00648440
        009e9fe4 f0 c2 68 00     addr       LAB_0068c2f0
        009e9fe8 00 8a 64 00     addr       LAB_00648a00


*/
#pragma pack(push, 1)
class cl_MovingSimObject : public cl_GuildObject {
public:
	GENERATE_VTABLE_PADDING(pad_cl_Root, 7)
	GENERATE_VTABLE_PADDING(pad_cl_Serializable, 11)
	GENERATE_VTABLE_PADDING(pad_cl_PropertyHolder, 13)
	GENERATE_VTABLE_PADDING(pad_cl_CoreNode, 2)
	GENERATE_VTABLE_PADDING(pad_cl_SimObject, 28)
	GENERATE_VTABLE_PADDING(pad_cl_MeasureSimObject, 20)
	GENERATE_VTABLE_PADDING(pad_cl_GuildObject, 56)
	// offset after cl_GuildObject: 0x378 == 888
	uint8_t padding[408];
	
	//float GetHP() { return reinterpret_cast<float(__thiscall*)(void*)>(0x0062db00)(this); }
	//float GetHPRelative() { return reinterpret_cast<float(__thiscall*)(void*)>(0x0062e700)(this); }
};
#pragma pack(pop)
//static_assert(offsetof(cl_GuildObject, hp) == 0x184, "Incorrect member offset");
//static_assert(offsetof(cl_GuildObject, maxHP) == 0x188, "Incorrect member offset");

static_assert(sizeof(cl_MovingSimObject) == 0x510, "cl_GuildObject has incorrect size"); // 1296
