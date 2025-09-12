#pragma once

#include "../RTTIMeta.hpp"
#include "cl_MeasureSimObject.hpp"

/* 
        009e3804 40 6b 63 00     addr       FUN_00636b40
        009e3808 20 e1 6f 00     addr       FUN_006fe120
        009e380c 70 14 70 00     addr       FUN_00701470
        009e3810 90 14 70 00     addr       FUN_00701490
        009e3814 e0 7d 74 00     addr       FUN_00747de0
        009e3818 a0 10 40 00     addr       FUN_004010a0
        009e381c 20 da 62 00     addr       FUN_0062da20
        
        009e3820 c0 db 56 00     addr       FUN_0056dbc0
        009e3824 40 0e 63 00     addr       FUN_00630e40
        009e3828 60 1b 63 00     addr       FUN_00631b60
        009e382c 60 5b 63 00     addr       FUN_00635b60
        009e3830 10 a3 54 00     addr       FUN_0054a310
        009e3834 c0 6c 63 00     addr       FUN_00636cc0
        009e3838 d0 d4 56 00     addr       FUN_0056d4d0
        009e383c 00 d5 56 00     addr       FUN_0056d500
        009e3840 30 d5 56 00     addr       FUN_0056d530
        009e3844 60 d5 56 00     addr       FUN_0056d560
        009e3848 50 22 7a 00     addr       LAB_007a2250
        009e384c f0 90 50 00     addr       LAB_005090f0
        009e3850 f0 89 50 00     addr       FUN_005089f0
        009e3854 30 e0 5c 00     addr       FUN_005ce030
        009e3858 a0 01 70 00     addr       LAB_007001a0
        009e385c 50 0b 70 00     addr       FUN_00700b50
        009e3860 a0 fb 6f 00     addr       FUN_006ffba0
        009e3864 70 fb 6f 00     addr       FUN_006ffb70
        009e3868 60 05 70 00     addr       LAB_00700560
        009e386c 80 05 70 00     addr       LAB_00700580
        009e3870 00 0c 70 00     addr       FUN_00700c00
        009e3874 80 00 70 00     addr       LAB_00700080
        009e3878 f0 05 70 00     addr       LAB_007005f0
        009e387c d0 f6 6f 00     addr       LAB_006ff6d0
        009e3880 c0 e0 6f 00     addr       FUN_006fe0c0
        
        009e3884 10 e2 6f 00     addr       LAB_006fe210
        009e3888 60 6b 63 00     addr       FUN_00636b60
        
        009e388c 30 44 63 00     addr       FUN_00634430
        009e3890 c0 51 54 00     addr       FUN_005451c0
        009e3894 90 f9 62 00     addr       FUN_0062f990
        009e3898 30 da 62 00     addr       FUN_0062da30
        009e389c 60 8a 50 00     addr       FUN_00508a60
        009e38a0 70 8a 50 00     addr       FUN_00508a70
        009e38a4 00 91 50 00     addr       LAB_00509100
        009e38a8 10 91 50 00     addr       LAB_00509110
        009e38ac 20 91 50 00     addr       LAB_00509120
        009e38b0 f0 04 63 00     addr       FUN_006304f0
        009e38b4 a0 19 57 00     addr       FUN_005719a0
        009e38b8 60 6d 63 00     addr       FUN_00636d60
        009e38bc d0 51 54 00     addr       LAB_005451d0
        009e38c0 e0 51 54 00     addr       LAB_005451e0
        009e38c4 90 da 62 00     addr       FUN_0062da90
        009e38c8 90 8b 50 00     addr       FUN_00508b90
        009e38cc 80 e6 62 00     addr       FUN_0062e680
        009e38d0 30 91 50 00     addr       LAB_00509130
        009e38d4 b0 8b 50 00     addr       FUN_00508bb0
        009e38d8 60 fb 62 00     addr       FUN_0062fb60
        009e38dc 80 8c 50 00     addr       FUN_00508c80
        009e38e0 30 ae 5e 00     addr       LAB_005eae30
        009e38e4 f0 07 63 00     addr       FUN_006307f0
        009e38e8 b0 8c 50 00     addr       FUN_00508cb0
        009e38ec e0 8c 50 00     addr       FUN_00508ce0
        009e38f0 20 b4 4f 00     addr       FUN_004fb420
        009e38f4 a0 19 57 00     addr       FUN_005719a0
        009e38f8 80 7d 54 00     addr       FUN_00547d80
        
        009e38fc b0 6f 54 00     addr       FUN_00546fb0
        009e3900 40 f9 6e 00     addr       FUN_006ef940
        009e3904 50 5f 54 00     addr       FUN_00545f50
        009e3908 40 77 74 00     addr       FUN_00747740
        009e390c 40 52 54 00     addr       LAB_00545240
        009e3910 a0 72 54 00     addr       FUN_005472a0
        009e3914 10 8c 54 00     addr       LAB_00548c10
        009e3918 20 80 54 00     addr       LAB_00548020
        009e391c 60 8c 54 00     addr       FUN_00548c60
        009e3920 30 e0 5c 00     addr       FUN_005ce030
        009e3924 30 e0 5c 00     addr       FUN_005ce030
        009e3928 70 2b 4f 00     addr       FUN_004f2b70
        009e392c 60 52 54 00     addr       LAB_00545260
        009e3930 f0 52 54 00     addr       FUN_005452f0
        009e3934 80 53 54 00     addr       FUN_00545380
        009e3938 80 20 63 00     addr       LAB_00632080
        009e393c d0 20 63 00     addr       FUN_006320d0
        009e3940 d0 5e 54 00     addr       FUN_00545ed0
        009e3944 70 5f 54 00     addr       FUN_00545f70
        009e3948 60 da 62 00     addr       FUN_0062da60
        
        009e394c 00 40 63 00     addr       FUN_00634000
        009e3950 e0 c2 96 00     addr       FUN_0096c2e0
        009e3954 60 13 63 00     addr       FUN_00631360
        009e3958 e0 c2 96 00     addr       FUN_0096c2e0
        009e395c 70 df 62 00     addr       FUN_0062df70
        009e3960 b0 df 62 00     addr       FUN_0062dfb0
        009e3964 d0 e6 62 00     addr       LAB_0062e6d0
        009e3968 d0 e6 62 00     addr       LAB_0062e6d0
        009e396c 10 d4 6a 00     addr       LAB_006ad410
        009e3970 80 cd 70 00     addr       FUN_0070cd80
        009e3974 50 ad 5e 00     addr       LAB_005ead50
        009e3978 30 e6 62 00     addr       FUN_0062e630
        009e397c c0 da 62 00     addr       FUN_0062dac0
        009e3980 e0 da 62 00     addr       LAB_0062dae0
        009e3984 40 f9 6e 00     addr       FUN_006ef940
        009e3988 10 ed 62 00     addr       FUN_0062ed10
        009e398c 80 ef 62 00     addr       FUN_0062ef80
        009e3990 f0 ef 62 00     addr       LAB_0062eff0
        009e3994 f0 ef 62 00     addr       LAB_0062eff0
        009e3998 10 09 63 00     addr       LAB_00630910
        009e399c 60 b2 5c 00     addr       FUN_005cb260
        009e39a0 10 dc 62 00     addr       LAB_0062dc10
        009e39a4 f0 db 62 00     addr       LAB_0062dbf0
        009e39a8 c0 27 63 00     addr       FUN_006327c0
        009e39ac c0 27 63 00     addr       FUN_006327c0
        009e39b0 20 ae 5e 00     addr       LAB_005eae20
        009e39b4 80 cd 70 00     addr       FUN_0070cd80
        009e39b8 50 22 7a 00     addr       LAB_007a2250
        009e39bc 00 e8 62 00     addr       FUN_0062e800
        009e39c0 f0 4c 63 00     addr       FUN_00634cf0
        009e39c4 e0 f0 62 00     addr       FUN_0062f0e0
        009e39c8 10 f0 62 00     addr       FUN_0062f010
        009e39cc 80 cd 70 00     addr       FUN_0070cd80
        009e39d0 70 ad 5e 00     addr       LAB_005ead70
        009e39d4 a0 ad 5e 00     addr       FUN_005eada0
        009e39d8 d0 ad 5e 00     addr       FUN_005eadd0
        009e39dc f0 ad 5e 00     addr       LAB_005eadf0
        009e39e0 50 21 63 00     addr       FUN_00632150
        009e39e4 f0 03 63 00     addr       FUN_006303f0
        009e39e8 d0 95 69 00     addr       LAB_006995d0
        009e39ec 40 04 63 00     addr       LAB_00630440
        009e39f0 30 e7 62 00     addr       LAB_0062e730
        009e39f4 d0 e7 62 00     addr       LAB_0062e7d0
        009e39f8 b0 f1 62 00     addr       LAB_0062f1b0
        009e39fc 80 cd 70 00     addr       FUN_0070cd80
        009e3a00 80 cd 70 00     addr       FUN_0070cd80
        009e3a04 70 de 62 00     addr       FUN_0062de70
        009e3a08 50 dd 62 00     addr       FUN_0062dd50
        009e3a0c e0 dd 62 00     addr       FUN_0062dde0
        009e3a10 e0 f6 62 00     addr       FUN_0062f6e0
        009e3a14 30 09 63 00     addr       FUN_00630930
        009e3a18 50 09 63 00     addr       FUN_00630950
        009e3a1c 50 22 7a 00     addr       LAB_007a2250
        009e3a20 10 ae 5e 00     addr       LAB_005eae10
        009e3a24 10 ae 5e 00     addr       LAB_005eae10
        009e3a28 30 e0 5c 00     addr       FUN_005ce030

*/



#pragma pack(push, 1)
class cl_GuildObject : public cl_MeasureSimObject {
public:
	GENERATE_VTABLE_PADDING(pad_cl_Root, 7)
	GENERATE_VTABLE_PADDING(pad_cl_Serializable, 11)
	GENERATE_VTABLE_PADDING(pad_cl_PropertyHolder, 13)
	GENERATE_VTABLE_PADDING(pad_cl_CoreNode, 2)
	GENERATE_VTABLE_PADDING(pad_cl_SimObject, 28)
	GENERATE_VTABLE_PADDING(pad_cl_MeasureSimObject, 20)
	GENERATE_VTABLE_PADDING(pad_cl_GuildObject, 56)
	// offset after cl_MeasureSimObject: 0x144 == 324
	uint8_t padding_1[46];
	uint8_t pad[4];
	//cl_GuildObject *courtingSim; // 0x172 == 370 // it doesn't really work right now
	uint8_t padding0[14];
	float hp; // 0x184 == 388
	float maxHP; // 0x188 == 392
	uint8_t padding1[492];
	
	float GetHP() { return reinterpret_cast<float(__thiscall*)(void*)>(0x0062db00)(this); }
	float GetHPRelative() { return reinterpret_cast<float(__thiscall*)(void*)>(0x0062e700)(this); }
};
#pragma pack(pop)

//static_assert(offsetof(cl_GuildObject, courtingSim) == 0x172, "Incorrect member offset");
static_assert(offsetof(cl_GuildObject, hp) == 0x184, "Incorrect member offset");
static_assert(offsetof(cl_GuildObject, maxHP) == 0x188, "Incorrect member offset");


static_assert(sizeof(cl_GuildObject) == 0x378, "cl_GuildObject has incorrect size"); // 888
