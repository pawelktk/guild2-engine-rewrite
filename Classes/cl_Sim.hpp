#pragma once

#include "../RTTIMeta.hpp"
#include "cl_MovingSimObject.hpp"

//TODO Register the vtable padding correctly

/*  
        009e5e6c 00 54 65 00     addr       FUN_00655400
        009e5e70 20 e1 6f 00     addr       FUN_006fe120
        009e5e74 70 14 70 00     addr       FUN_00701470
        009e5e78 90 14 70 00     addr       FUN_00701490
        009e5e7c e0 7d 74 00     addr       FUN_00747de0
        009e5e80 a0 10 40 00     addr       FUN_004010a0
        009e5e84 60 8b 64 00     addr       LAB_00648b60
        009e5e88 c0 db 56 00     addr       FUN_0056dbc0
        009e5e8c e0 af 64 00     addr       FUN_0064afe0
        009e5e90 b0 f2 64 00     addr       FUN_0064f2b0
        009e5e94 20 54 65 00     addr       FUN_00655420
        009e5e98 70 8b 64 00     addr       FUN_00648b70
        009e5e9c 90 9b 64 00     addr       LAB_00649b90
        009e5ea0 d0 d4 56 00     addr       FUN_0056d4d0
        009e5ea4 00 d5 56 00     addr       FUN_0056d500
        009e5ea8 30 d5 56 00     addr       FUN_0056d530
        009e5eac 60 d5 56 00     addr       FUN_0056d560
        009e5eb0 50 22 7a 00     addr       LAB_007a2250
        009e5eb4 f0 90 50 00     addr       LAB_005090f0
        009e5eb8 f0 89 50 00     addr       FUN_005089f0
        009e5ebc 30 e0 5c 00     addr       FUN_005ce030
        009e5ec0 a0 01 70 00     addr       LAB_007001a0
        009e5ec4 50 0b 70 00     addr       FUN_00700b50
        009e5ec8 a0 fb 6f 00     addr       FUN_006ffba0
        009e5ecc 70 fb 6f 00     addr       FUN_006ffb70
        009e5ed0 60 05 70 00     addr       LAB_00700560
        009e5ed4 80 05 70 00     addr       LAB_00700580
        009e5ed8 00 0c 70 00     addr       FUN_00700c00
        009e5edc 80 00 70 00     addr       LAB_00700080
        009e5ee0 f0 05 70 00     addr       LAB_007005f0
        009e5ee4 d0 f6 6f 00     addr       LAB_006ff6d0
        009e5ee8 c0 e0 6f 00     addr       FUN_006fe0c0
        009e5eec 10 e2 6f 00     addr       LAB_006fe210
        009e5ef0 b0 6c 65 00     addr       FUN_00656cb0
        009e5ef4 70 b7 64 00     addr       FUN_0064b770
        009e5ef8 c0 51 54 00     addr       FUN_005451c0
        009e5efc 30 ae 68 00     addr       FUN_0068ae30
        009e5f00 40 af 68 00     addr       LAB_0068af40
        009e5f04 90 9d 68 00     addr       FUN_00689d90
        009e5f08 70 8a 50 00     addr       FUN_00508a70
        009e5f0c 00 91 50 00     addr       LAB_00509100
        009e5f10 10 91 50 00     addr       LAB_00509110
        009e5f14 20 91 50 00     addr       LAB_00509120
        009e5f18 f0 03 65 00     addr       LAB_006503f0
        009e5f1c e0 60 65 00     addr       FUN_006560e0
        009e5f20 b0 ff 64 00     addr       FUN_0064ffb0
        009e5f24 d0 51 54 00     addr       LAB_005451d0
        009e5f28 e0 51 54 00     addr       LAB_005451e0
        009e5f2c 20 8c 64 00     addr       FUN_00648c20
        009e5f30 80 cb 64 00     addr       LAB_0064cb80
        009e5f34 30 bc 64 00     addr       FUN_0064bc30
        009e5f38 30 91 50 00     addr       LAB_00509130
        009e5f3c 60 8c 64 00     addr       LAB_00648c60
        009e5f40 40 a7 64 00     addr       FUN_0064a740
        009e5f44 80 8c 50 00     addr       FUN_00508c80
        009e5f48 30 ae 5e 00     addr       LAB_005eae30
        009e5f4c 80 a7 64 00     addr       FUN_0064a780
        009e5f50 b0 8c 50 00     addr       FUN_00508cb0
        009e5f54 e0 8c 50 00     addr       FUN_00508ce0
        009e5f58 20 b4 4f 00     addr       FUN_004fb420
        009e5f5c a0 19 57 00     addr       FUN_005719a0
        009e5f60 80 7d 54 00     addr       FUN_00547d80
        009e5f64 b0 6f 54 00     addr       FUN_00546fb0
        009e5f68 40 21 65 00     addr       FUN_00652140
        009e5f6c 50 5f 54 00     addr       FUN_00545f50
        009e5f70 40 77 74 00     addr       FUN_00747740
        009e5f74 40 52 54 00     addr       LAB_00545240
        009e5f78 a0 72 54 00     addr       FUN_005472a0
        009e5f7c 10 8c 54 00     addr       LAB_00548c10
        009e5f80 20 80 54 00     addr       LAB_00548020
        009e5f84 60 8c 54 00     addr       FUN_00548c60
        009e5f88 d0 db 64 00     addr       LAB_0064dbd0
        009e5f8c 90 a0 64 00     addr       FUN_0064a090
        009e5f90 80 c2 64 00     addr       FUN_0064c280
        009e5f94 60 52 54 00     addr       LAB_00545260
        009e5f98 f0 52 54 00     addr       FUN_005452f0
        009e5f9c 80 53 54 00     addr       FUN_00545380
        009e5fa0 80 20 63 00     addr       LAB_00632080
        009e5fa4 d0 20 63 00     addr       FUN_006320d0
        009e5fa8 50 ad 68 00     addr       FUN_0068ad50
        009e5fac 70 5f 54 00     addr       FUN_00545f70
        009e5fb0 20 99 68 00     addr       thunk_FUN_0062da60
        009e5fb4 f0 f7 64 00     addr       LAB_0064f7f0
        009e5fb8 a0 16 65 00     addr       LAB_006516a0
        009e5fbc d0 f5 64 00     addr       FUN_0064f5d0
        009e5fc0 e0 c2 96 00     addr       FUN_0096c2e0
        009e5fc4 70 df 62 00     addr       FUN_0062df70
        009e5fc8 b0 df 62 00     addr       FUN_0062dfb0
        009e5fcc d0 e6 62 00     addr       LAB_0062e6d0
        009e5fd0 30 99 68 00     addr       LAB_00689930
        009e5fd4 80 b9 64 00     addr       LAB_0064b980
        009e5fd8 c0 b9 64 00     addr       LAB_0064b9c0
        009e5fdc 50 ad 5e 00     addr       LAB_005ead50
        009e5fe0 f0 9d 64 00     addr       FUN_00649df0
        009e5fe4 90 c1 68 00     addr       LAB_0068c190
        009e5fe8 c0 a6 64 00     addr       LAB_0064a6c0
        009e5fec 60 df 64 00     addr       LAB_0064df60
        009e5ff0 f0 ff 64 00     addr       FUN_0064fff0
        009e5ff4 80 ef 62 00     addr       FUN_0062ef80
        009e5ff8 f0 ef 62 00     addr       LAB_0062eff0
        009e5ffc f0 ef 62 00     addr       LAB_0062eff0
        009e6000 40 e2 64 00     addr       FUN_0064e240
        009e6004 60 b2 5c 00     addr       FUN_005cb260
        009e6008 10 dc 62 00     addr       LAB_0062dc10
        009e600c f0 db 62 00     addr       LAB_0062dbf0
        009e6010 c0 27 63 00     addr       FUN_006327c0
        009e6014 c0 27 63 00     addr       FUN_006327c0
        009e6018 20 be 64 00     addr       LAB_0064be20
        009e601c 80 bc 64 00     addr       FUN_0064bc80
        009e6020 50 22 7a 00     addr       LAB_007a2250
        009e6024 a0 a8 64 00     addr       LAB_0064a8a0
        009e6028 50 69 65 00     addr       LAB_00656950
        009e602c e0 f0 62 00     addr       FUN_0062f0e0
        009e6030 f0 64 65 00     addr       FUN_006564f0
        009e6034 50 a2 64 00     addr       FUN_0064a250
        009e6038 70 ad 5e 00     addr       LAB_005ead70
        009e603c a0 ad 5e 00     addr       FUN_005eada0
        009e6040 d0 ad 5e 00     addr       FUN_005eadd0
        009e6044 f0 ad 5e 00     addr       LAB_005eadf0
        009e6048 60 a9 64 00     addr       FUN_0064a960
        009e604c f0 03 63 00     addr       FUN_006303f0
        009e6050 00 a1 64 00     addr       LAB_0064a100
        009e6054 40 04 63 00     addr       LAB_00630440
        009e6058 30 e7 62 00     addr       LAB_0062e730
        009e605c d0 e7 62 00     addr       LAB_0062e7d0
        009e6060 b0 f1 62 00     addr       LAB_0062f1b0
        009e6064 20 a5 64 00     addr       FUN_0064a520
        009e6068 b0 9f 64 00     addr       FUN_00649fb0
        009e606c 70 de 62 00     addr       FUN_0062de70
        009e6070 50 dd 62 00     addr       FUN_0062dd50
        009e6074 e0 dd 62 00     addr       FUN_0062dde0
        009e6078 40 ec 64 00     addr       FUN_0064ec40
        009e607c 30 09 63 00     addr       FUN_00630930
        009e6080 50 09 63 00     addr       FUN_00630950
        009e6084 50 22 7a 00     addr       LAB_007a2250
        009e6088 10 ae 5e 00     addr       LAB_005eae10
        009e608c d0 3b 65 00     addr       LAB_00653bd0
        009e6090 60 aa 64 00     addr       FUN_0064aa60
        009e6094 a0 a4 68 00     addr       FUN_0068a4a0
        009e6098 b0 a5 68 00     addr       LAB_0068a5b0
        009e609c 30 a3 68 00     addr       FUN_0068a330
        009e60a0 40 a1 68 00     addr       LAB_0068a140
        009e60a4 00 ba 68 00     addr       LAB_0068ba00
        009e60a8 60 a1 68 00     addr       LAB_0068a160
        009e60ac 00 a2 68 00     addr       FUN_0068a200
        009e60b0 60 b6 68 00     addr       FUN_0068b660
        009e60b4 e0 3b 65 00     addr       LAB_00653be0
        009e60b8 c0 97 68 00     addr       LAB_006897c0
        009e60bc e0 83 64 00     addr       LAB_006483e0
        009e60c0 00 84 64 00     addr       LAB_00648400
        009e60c4 d0 ba 68 00     addr       LAB_0068bad0
        009e60c8 40 84 64 00     addr       LAB_00648440
        009e60cc f0 c2 68 00     addr       LAB_0068c2f0
        009e60d0 10 24 65 00     addr       LAB_00652410
        009e60d4 80 9a 64 00     addr       LAB_00649a80
        009e60d8 20 9a 64 00     addr       LAB_00649a20
        009e60dc 50 9a 64 00     addr       LAB_00649a50
        009e60e0 b0 43 65 00     addr       LAB_006543b0
        009e60e4 00 c0 64 00     addr       LAB_0064c000
        009e60e8 e0 bf 64 00     addr       LAB_0064bfe0
        009e60ec f0 8c 64 00     addr       LAB_00648cf0


*/
#pragma pack(push, 1)
class cl_Sim : public cl_MovingSimObject {
public:
	GENERATE_VTABLE_PADDING(pad_cl_Root, 7)
	GENERATE_VTABLE_PADDING(pad_cl_Serializable, 11)
	GENERATE_VTABLE_PADDING(pad_cl_PropertyHolder, 13)
	GENERATE_VTABLE_PADDING(pad_cl_CoreNode, 2)
	GENERATE_VTABLE_PADDING(pad_cl_SimObject, 28)
	GENERATE_VTABLE_PADDING(pad_cl_MeasureSimObject, 20)
	GENERATE_VTABLE_PADDING(pad_cl_GuildObject, 56)
	// offset after cl_MovingSimObject: 0x510 == 1296
	uint8_t padding[184];
	cl_GuildObject *courtingSim; // 0x5c8 == 1480
	uint8_t padding2[436];
	
	bool ArrangeLiaison(cl_Sim *secondSim) { return reinterpret_cast<bool(__thiscall*)(void*, cl_Sim*)>(0x0064d6d0)(this, secondSim); }
	bool SetProgress(int progress) { return reinterpret_cast<bool(__thiscall*)(void*, int)>(0x006066b0)(this, progress); }

    bool SetCourtLover(cl_Sim* secondSim) {
        return reinterpret_cast<bool(__thiscall*)(void*, cl_Sim*)>(0x00654f20)(this, secondSim);
    }
    bool AddCourtingProgress() {
        return reinterpret_cast<bool(__thiscall*)(void*)>(0x0064dec0)(this);
    }
    bool Marry(cl_Sim* pTransferredSim) {
        return reinterpret_cast<bool(__thiscall*)(void*, cl_Sim*)>(0x00652f50)(this, pTransferredSim);
    }
	//float GetHP() { return reinterpret_cast<float(__thiscall*)(void*)>(0x0062db00)(this); }
	//float GetHPRelative() { return reinterpret_cast<float(__thiscall*)(void*)>(0x0062e700)(this); }
};
#pragma pack(pop)
static_assert(offsetof(cl_Sim, courtingSim) == 0x5c8, "Incorrect member offset");
//static_assert(offsetof(cl_GuildObject, hp) == 0x184, "Incorrect member offset");
//static_assert(offsetof(cl_GuildObject, maxHP) == 0x188, "Incorrect member offset");

static_assert(sizeof(cl_Sim) == 0x780, "cl_Sim has incorrect size"); // 1920
