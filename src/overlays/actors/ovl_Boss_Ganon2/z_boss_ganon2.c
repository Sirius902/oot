#include "z_boss_ganon2.h"

#define FLAGS 0x00000035

#define THIS ((BossGanon2*)thisx)

void BossGanon2_Init(Actor* thisx, GlobalContext* globalCtx);
void BossGanon2_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BossGanon2_Update(Actor* thisx, GlobalContext* globalCtx);
void BossGanon2_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_808FD5C4(BossGanon2* this, GlobalContext* globalCtx);
void func_808FD5F4(BossGanon2* this, GlobalContext* globalCtx);
void func_80900104(BossGanon2* this, GlobalContext* globalCtx);

extern SkeletonHeader D_060114E8;

/*
const ActorInit Boss_Ganon2_InitVars = {
    ACTOR_BOSS_GANON2,
    ACTORTYPE_BOSS,
    FLAGS,
    OBJECT_GANON2,
    sizeof(BossGanon2),
    (ActorFunc)BossGanon2_Init,
    (ActorFunc)BossGanon2_Destroy,
    (ActorFunc)BossGanon2_Update,
    (ActorFunc)BossGanon2_Draw,
};
*/

/*
// sJntSphInit
static ColliderJntSphInit D_80906FBC = {
    { COLTYPE_METAL_SHIELD, 0x11, 0x09, 0x09, 0x50, COLSHAPE_JNTSPH },
    16,
    D_80906D7C,
};

// sJntSphInit
static ColliderJntSphInit D_80907014 = {
    { COLTYPE_METAL_SHIELD, 0x11, 0x09, 0x09, 0x10, COLSHAPE_JNTSPH },
    2,
    D_80906FCC,
};

static SkelAnime D_8090EB38[100];
*/

extern u8 D_80906D78;
extern ColliderJntSphInit D_80906FBC;
extern ColliderJntSphInit D_80907014;
extern s16 D_80907074[4];
extern Vec3f D_8090EB20;
extern SkelAnime D_8090EB38[100];

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon2/func_808FCF40.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon2/func_808FCF5C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon2/func_808FD080.s")

void func_808FD108(BossGanon2* this, GlobalContext* globalCtx, s32 objectId, u8 arg3) {
    s32 pad;
    s32 objectIdx = Object_GetIndex(&globalCtx->objectCtx, objectId);

    gSegments[6] = PHYSICAL_TO_VIRTUAL(globalCtx->objectCtx.status[objectIdx].segment);

    if (arg3) {
        OPEN_DISPS(globalCtx->state.gfxCtx, "../z_boss_ganon2.c", 790);

        gSPSegment(POLY_OPA_DISP++, 0x06, globalCtx->objectCtx.status[objectIdx].segment);
        gSPSegment(POLY_XLU_DISP++, 0x06, globalCtx->objectCtx.status[objectIdx].segment);

        CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_boss_ganon2.c", 799);
    }
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon2/func_808FD210.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon2/func_808FD27C.s")

void BossGanon2_Init(Actor* thisx, GlobalContext* globalCtx) {
    BossGanon2* this = THIS;
    s32 pad;
    s16 i;

    globalCtx->unk_11E10 = D_8090EB38;

    for (i = 0; i < ARRAY_COUNT(D_8090EB38); i++) {
        D_8090EB38[i].limbCount = 0;
    }

    this->actor.colChkInfo.mass = 0xFF;
    this->actor.colChkInfo.health = 0x1E;
    Collider_InitJntSph(globalCtx, &this->unk_424);
    Collider_SetJntSph(globalCtx, &this->unk_424, &this->actor, &D_80906FBC, this->unk_464);
    Collider_InitJntSph(globalCtx, &this->unk_444);
    Collider_SetJntSph(globalCtx, &this->unk_444, &this->actor, &D_80907014, this->unk_864);
    func_808FD108(&this->actor, globalCtx, OBJECT_GANON, 0);
    SkelAnime_InitSV(globalCtx, &this->skelAnime, &D_060114E8, NULL, 0, 0, 0);
    func_808FD5C4(this, globalCtx);
    this->actor.naviEnemyId = 0x3E;
    this->actor.gravity = 0.0f;
}

void BossGanon2_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    BossGanon2* this = THIS;

    SkelAnime_Free(&this->skelAnime, globalCtx);
    Collider_DestroyJntSph(globalCtx, &this->unk_424);
    Collider_DestroyJntSph(globalCtx, &this->unk_444);
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon2/func_808FD4D4.s")

void func_808FD5C4(BossGanon2* this, GlobalContext* globalCtx) {
    this->actionFunc = func_808FD5F4;
    this->actor.flags &= ~1;
    this->actor.posRot.pos.y = -3000.0f;
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon2/func_808FD5F4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon2/func_808FF898.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon2/func_808FFA24.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon2/func_808FFAC8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon2/func_808FFBBC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon2/func_808FFC84.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon2/func_808FFCFC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon2/func_808FFDB0.s")

void func_808FFEBC(BossGanon2* this, GlobalContext* globalCtx);
#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon2/func_808FFEBC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon2/func_808FFF90.s")

void func_808FFFE0(BossGanon2* this, GlobalContext* globalCtx);
#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon2/func_808FFFE0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon2/func_809000A0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon2/func_80900104.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon2/func_80900210.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon2/func_8090026C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon2/func_809002CC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon2/func_80900344.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon2/func_80900580.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon2/func_80900650.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon2/func_80900818.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon2/func_80900890.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon2/func_80901020.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon2/func_8090109C.s")

void func_8090120C(BossGanon2* this, GlobalContext* globalCtx);
#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon2/func_8090120C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon2/func_80902348.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon2/func_80902524.s")

#ifdef NON_MATCHING
void BossGanon2_Update(Actor* thisx, GlobalContext* globalCtx) {
    BossGanon2* this = THIS;
    f32 sp68;
    Vec3f sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 temp_f10;
    f32 temp_f4;
    s32 temp_s0_4;
    u32 temp_a0;
    u32 temp_a0_2;
    s16 i;
    f32 phi_f2;
    s32 phi_s0_3;

    if ((this->unk_337 == 0) || (this->unk_337 == 2)) {
        func_808FD108(this, globalCtx, OBJECT_GANON_ANIME3, 0);
    } else {
        func_808FD108(this, globalCtx, OBJECT_GANON2, 0);
        Math_SmoothDownscaleMaxF(&this->unk_30C, 1.0f, 0.5f);
    }
    func_808FFC84(this);
    this->unk_312 = 0;
    this->unk_19C++;
    Actor_SetScale(&this->actor, 0.01f);
    this->actionFunc(this, globalCtx);
    for (i = 0; i < ARRAY_COUNT(this->unk_1A2); i++) {
        if (this->unk_1A2[i] != 0) {
            this->unk_1A2[i]--;
        }
    }
    if (this->unk_316 != 0) {
        this->unk_316--;
    }
    if (this->unk_342 != 0) {
        this->unk_342--;
    }
    if (this->unk_390 != 0) {
        this->unk_390--;
    }
    if (this->unk_392 != 0) {
        this->unk_392--;
    }
    Actor_MoveForward(&this->actor);
    this->actor.shape.rot = this->actor.posRot.rot;
    if (this->unk_335 != 0) {
        func_8002E4B4(globalCtx, &this->actor, 60.0f, 60.0f, 100.0f, 5);
        if (this->actor.bgCheckFlags & 1) {
            if (this->actor.velocity.y < -5.0f) {
                func_80033E88(&this->actor, globalCtx, 5, 20);
                func_80078884(NA_SE_IT_BOMB_EXPLOSION);
            }
            this->actor.velocity.y = 0.0f;
        }
    }
    if (((this->unk_19C & 0x1F) == 0) && (Math_Rand_ZeroOne() < 0.3f)) {
        this->unk_318 = 4;
    }
    this->unk_310 = D_80907074[this->unk_318];
    if (this->unk_318 != 0) {
        this->unk_318--;
    }
    this->unk_1B0 = (Math_Sins(this->unk_19C * 0x2AAA) * 64.0f) + 191.0f;
    if (this->unk_344 != 0) {
        this->unk_344--;
        Math_SmoothScaleMaxF(&this->unk_360.x, 5000.0f, 0.5f, 3000.0f);
        Math_SmoothScaleMaxF(&this->unk_370.x, 5500.0f, 0.5f, 3000.0f);
        Math_SmoothScaleMaxF(&this->unk_360.z, 8000.0f, 0.1f, 4000.0f);
        Math_SmoothScaleMaxF(&this->unk_370.z, 8000.0f, 0.1f, 4000.0f);
        Math_SmoothScaleMaxS(&this->unk_346, 0xFA0, 0xA, 0x7D0);
    } else {
        this->unk_360.y = 14000.0f;
        Math_SmoothScaleMaxF(&this->unk_360.x, 2000.0f, 0.1f, 100.0f);
        this->unk_370.y = 12000.0f;
        Math_SmoothScaleMaxF(&this->unk_370.x, 1500.0f, 0.1f, 100.0f);
        if ((this->actionFunc == func_808FFEBC) || (this->actionFunc == func_808FFFE0) ||
            (this->actionFunc == func_80900104)) {
            Math_SmoothScaleMaxF(&this->unk_360.z, 1000.0f, 0.1f, 100.0f);
            Math_SmoothScaleMaxF(&this->unk_370.z, 1000.0f, 0.1f, 100.0f);
            Math_SmoothScaleMaxS(&this->unk_346, -0xFA0, 0xA, 0x64);
        } else {
            Math_SmoothScaleMaxF(&this->unk_360.z, 5000.0f, 0.1f, 200.0f);
            Math_SmoothScaleMaxF(&this->unk_370.z, 5000.0f, 0.1f, 200.0f);
            Math_SmoothScaleMaxS(&this->unk_346, 0, 0xA, 0x64);
        }
    }
    if (this->unk_39C != 0x4B) {
        this->unk_35C += this->unk_360.x;
        this->unk_36C += this->unk_370.x;
    }
    if (this->unk_337 == 2) {
        this->unk_370.z = 0.0f;
        this->unk_360.z = 0.0f;
    }

    for (i = 0; i < ARRAY_COUNT(this->unk_348); i++) {
        if (i == 0) {
            phi_f2 = 0.2f;
        } else if (i == 1) {
            phi_f2 = 0.5f;
        } else {
            phi_f2 = 1.0f;
        }

        this->unk_348[i] = (s16)(s32)(Math_Sins((s16)((s32)this->unk_35C + (i * (s16)(s32)this->unk_360.y))) * phi_f2 *
                                      this->unk_360.z);
        this->unk_352[i] = (s16)(s32)(Math_Sins((s16)((s32)this->unk_36C + (i * (s16)(s32)this->unk_370.y))) * phi_f2 *
                                      this->unk_370.z);
    }

    func_808FF898(this, globalCtx);
    func_80902348(this, globalCtx);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &this->unk_424.base);
    if (this->actionFunc == func_8090120C) {
        func_80902524(this, globalCtx);
        CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &this->unk_424.base);
        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &this->unk_444.base);
        CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &this->unk_444.base);
        if (this->unk_39E == 0) {
            CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &this->unk_444.base);
        }
    }
    if ((this->unk_332 == 0) && (this->unk_336 != 0)) {
        if (this->unk_336 == 2) {
            this->unk_332 = (s16)((s32)Math_Rand_ZeroFloat(30.0f) + 8);
        } else {
            this->unk_332 = (s16)((s32)Math_Rand_ZeroFloat(60.0f) + 0xA);
        }
        this->unk_339 = (u8)0;
        globalCtx->envCtx.unk_BE = (u8)0U;
        globalCtx->envCtx.unk_BD = (s8)((s32)Math_Rand_ZeroFloat(1.9f) + 1);
        globalCtx->envCtx.unk_D8 = 1.0f;
        D_8090EB20.y = 0.0f;
        D_8090EB20.x = D_8090EB20.y;
        D_8090EB20.z = D_8090EB20.x;
        if (Math_Rand_ZeroOne() < 0.5f) {
            D_8090EB20.z = Math_Rand_ZeroFloat(1000.0f);
        }
        func_80078914(&D_8090EB20, NA_SE_EV_LIGHTNING);
        this->unk_328 = (u16)0xFF;
        this->unk_330 = (u16)5;
        this->unk_32C = 0.0f;
        this->unk_340 = (s16)(s32)Math_Rand_ZeroFloat(10000.0f);
    } else if (this->unk_332 != 0) {
        this->unk_332--;
    }
    if ((globalCtx->envCtx.unk_D8 > 0.0f) && (this->unk_336 != 0)) {
        globalCtx->envCtx.unk_E9 = 1;
        globalCtx->envCtx.unk_EA[0] = (u8)0xFF;
        globalCtx->envCtx.unk_EA[1] = (u8)0xFF;
        globalCtx->envCtx.unk_EA[2] = (u8)0xFF;
        globalCtx->envCtx.unk_EA[3] = (s8)(s32)(globalCtx->envCtx.unk_D8 * 200.0f);
    } else {
        globalCtx->envCtx.unk_E9 = 0;
    }
    globalCtx->envCtx.unk_BF = 0;
    globalCtx->envCtx.unk_DC = 2;

    switch (this->unk_339) {
        case 55:
            globalCtx->envCtx.unk_BE = (u8)2U;
            globalCtx->envCtx.unk_BD = (u8)0;
            Math_SmoothDownscaleMaxF(&globalCtx->envCtx.unk_D8, 1.0f, 0.05f);
            break;
        case 7:
            globalCtx->envCtx.unk_BE = (u8)2U;
            globalCtx->envCtx.unk_BD = (u8)8;
            Math_SmoothScaleMaxF(&this->unk_33C, 0.69f, 1.0f, 0.05f);
            temp_a0_2 = globalCtx->gameplayFrames;
            globalCtx->envCtx.unk_D8 = (Math_Sins(temp_a0_2 * 0x7000) * 0.15f) + (0.15f + this->unk_33C);
            break;
        case 8:
            globalCtx->envCtx.unk_BE = (u8)0U;
            globalCtx->envCtx.unk_BD = (u8)8;
            Math_SmoothDownscaleMaxF(&globalCtx->envCtx.unk_D8, 1.0f, 0.02f);
            break;
        case 21:
            globalCtx->envCtx.unk_BE = (u8)0U;
            globalCtx->envCtx.unk_BD = (u8)9;
            break;
        case 22:
            globalCtx->envCtx.unk_BE = (u8)0xAU;
            globalCtx->envCtx.unk_BD = (u8)9;
            break;
        case 23:
            globalCtx->envCtx.unk_BE = (u8)0xAU;
            globalCtx->envCtx.unk_BD = (u8)0xB;
            break;
        case 24:
            globalCtx->envCtx.unk_BE = (u8)9U;
            globalCtx->envCtx.unk_BD = (u8)0xB;
            break;
        case 25:
            globalCtx->envCtx.unk_BE = (u8)0U;
            globalCtx->envCtx.unk_BD = (u8)0xC;
            break;
        case 0:
            Math_SmoothDownscaleMaxF(&globalCtx->envCtx.unk_D8, 1.0f, 0.1f);
            break;
        case 3:
            globalCtx->envCtx.unk_BE = (u8)3U;
            globalCtx->envCtx.unk_BD = (u8)4;
            Math_SmoothScaleMaxF(&globalCtx->envCtx.unk_D8, 1.0f, 1.0f, 0.0125f);
            break;
        case 4:
            globalCtx->envCtx.unk_BE = (u8)5U;
            globalCtx->envCtx.unk_BD = (u8)6;
            Math_SmoothScaleMaxF(&globalCtx->envCtx.unk_D8, 1.0f, 1.0f, 0.0125f);
            break;
        case 5:
            globalCtx->envCtx.unk_BE = (u8)6U;
            globalCtx->envCtx.unk_BD = (u8)7;
            Math_SmoothScaleMaxF(&this->unk_33C, 0.69f, 1.0f, 0.05f);
            temp_a0 = globalCtx->gameplayFrames;
            globalCtx->envCtx.unk_D8 =
                (Math_Sins((s16)(((temp_a0 * 4) + temp_a0) << 0xC)) * 0.15f) + (0.15f + this->unk_33C);
            break;
    }

    if ((s32)this->unk_339 >= 0) {
        this->unk_339 = (u8)0;
    }
    if (D_80906D78 != 0) {
        D_80906D78 = (u8)0U;
        phi_s0_3 = 0;
    loop_81:
        sp48 = Math_Rand_ZeroFloat(6.2831855f);
        sp44 = Math_Rand_ZeroFloat(40.0f) + 10.0f;
        sp58 = this->actor.posRot.pos;
        sp58.y = 1200.0f;
        temp_f4 = cosf(sp48) * sp44;
        sp4C = temp_f4;
        sp54 = sinf(sp48) * sp44;
        temp_f10 = temp_f4 * 10.0f * 0.1f;
        sp50 = Math_Rand_ZeroFloat(15.0f) + 15.0f;
        sp58.x += temp_f10;
        sp58.z += (sp54 * 10.0f * 0.1f);
        func_808FD27C(globalCtx, &sp58, &sp4C, Math_Rand_ZeroFloat(0.3f) + 0.2f);
        temp_s0_4 = (phi_s0_3 + 1) & 0xFFFF;
        phi_s0_3 = temp_s0_4;
        if (temp_s0_4 < 100) {
            goto loop_81;
        }
    }
    this->unk_388 += 0.15f;
    func_80905DA8(this, globalCtx);
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon2/BossGanon2_Update.s")
#endif

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon2/func_809034E4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon2/func_80903F38.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon2/func_80904108.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon2/func_80904340.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon2/func_8090464C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon2/func_80904818.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon2/func_809049A0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon2/func_80904D88.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon2/func_80904FC8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon2/func_8090523C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon2/func_80905508.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon2/func_80905674.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon2/BossGanon2_Draw.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon2/func_80905DA8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon2/func_809060E8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon2/func_80906538.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon2/func_809069F8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Boss_Ganon2/func_80906AB0.s")
