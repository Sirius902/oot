/*
 * File: z_en_goroiwa.c
 * Overlay: ovl_En_Goroiwa
 * Description: Rolling boulders
 */

#include "z_en_goroiwa.h"

#define FLAGS 0x00000010

#define THIS ((EnGoroiwa*)thisx)

void EnGoroiwa_Init(Actor* thisx, GlobalContext* globalCtx);
void EnGoroiwa_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnGoroiwa_Update(Actor* thisx, GlobalContext* globalCtx);
void EnGoroiwa_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_80A4BE10(EnGoroiwa* this, GlobalContext* globalCtx);
void func_80A4C1C4(EnGoroiwa* this, GlobalContext* globalCtx, s32 arg2);
void func_80A4C264(EnGoroiwa* this);
void func_80A4CED8(EnGoroiwa* this, GlobalContext* globalCtx);
void func_80A4D5E0(EnGoroiwa* this);

/*
const ActorInit En_Goroiwa_InitVars = {
    ACTOR_EN_GOROIWA,
    ACTORTYPE_PROP,
    FLAGS,
    OBJECT_GOROIWA,
    sizeof(EnGoroiwa),
    (ActorFunc)EnGoroiwa_Init,
    (ActorFunc)EnGoroiwa_Destroy,
    (ActorFunc)EnGoroiwa_Update,
    (ActorFunc)EnGoroiwa_Draw,
};
*/

extern ColliderJntSphInit D_80A4DEA4;
extern CollisionCheckInfoInit D_80A4DEB4;
extern f32 D_80A4DEC4[];
extern InitChainEntry D_80A4DEF8;
extern f32 D_80A4DF10[];

extern Gfx D_060006B0[];

void func_80A4BCA0(EnGoroiwa* this) {
    Sphere16* worldSphere = &this->collider.list->dim.worldSphere;

    worldSphere->center.x = this->actor.posRot.pos.x;
    worldSphere->center.y = D_80A4DEC4[(this->actor.params >> 10) & 1] + this->actor.posRot.pos.y;
    worldSphere->center.z = this->actor.posRot.pos.z;
}

void func_80A4BD04(EnGoroiwa* this, GlobalContext* globalCtx) {
    s32 pad;

    Collider_InitJntSph(globalCtx, &this->collider);
    Collider_SetJntSph(globalCtx, &this->collider, &this->actor, &D_80A4DEA4, &this->colliderItem);
    func_80A4BCA0(this);
    this->collider.list->dim.worldSphere.radius = 0x3A;
}

void func_80A4BD70(EnGoroiwa* this, u8 arg1) {
    this->unk_1D3 &= ~3;
    this->unk_1D3 |= arg1;
}

bool func_80A4BD8C(Vec3f* arg0, Vec3f* arg1) {
    f32 temp_f0 = Math3D_Vec3fMagnitude(arg1);
    f32 temp_f2;

    if (temp_f0 < 0.001f) {
        return false;
    }

    temp_f2 = 1.0f / temp_f0;

    arg0->x = arg1->x * temp_f2;
    arg0->y = arg1->y * temp_f2;
    arg0->z = arg1->z * temp_f2;

    return true;
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Goroiwa/func_80A4BE10.s")

void func_80A4BE54(EnGoroiwa* this, GlobalContext* globalCtx) {
    Path* path = &globalCtx->setupPathList[this->actor.params & 0xFF];
    Vec3s* temp = &((Vec3s*)SEGMENTED_TO_VIRTUAL(path->points))[this->unk_1CE];
    Vec3f temp2;

    temp2.x = temp->x;
    temp2.y = temp->y;
    temp2.z = temp->z;

    this->actor.posRot.rot.y = Math_Vec3f_Yaw(&this->actor.posRot.pos, &temp2);
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Goroiwa/func_80A4BF28.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Goroiwa/func_80A4C080.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Goroiwa/func_80A4C134.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Goroiwa/func_80A4C164.s")

void func_80A4C188(EnGoroiwa* this, GlobalContext* globalCtx) {
    this->unk_1CA = globalCtx->setupPathList[this->actor.params & 0xFF].count - 1;
    this->unk_1CC = 0;
    this->unk_1CE = 1;
    this->unk_1D0 = 1;
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Goroiwa/func_80A4C1C4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Goroiwa/func_80A4C264.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Goroiwa/func_80A4C27C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Goroiwa/func_80A4C3A4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Goroiwa/func_80A4C594.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Goroiwa/func_80A4C6C8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Goroiwa/func_80A4C814.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Goroiwa/func_80A4CA50.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Goroiwa/func_80A4CB78.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Goroiwa/func_80A4CED8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Goroiwa/func_80A4D074.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Goroiwa/func_80A4D0FC.s")

void EnGoroiwa_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnGoroiwa* this = THIS;
    s32 params;

    Actor_ProcessInitChain(&this->actor, &D_80A4DEF8);
    func_80A4BD04(this, globalCtx);
    params = this->actor.params & 0xFF;
    if (params == 0xFF) {
        // Translation: Error: Invalid arg_data
        osSyncPrintf("Ｅｒｒｏｒ : arg_data が不正(%s %d)(arg_data 0x%04x)\n", "../z_en_gr.c", 1033, this->actor.params);
        Actor_Kill(&this->actor);
        return;
    }
    if (globalCtx->setupPathList[params].count < 2) {
        // Translation: Error: Invalid Path Data
        osSyncPrintf("Ｅｒｒｏｒ : レールデータ が不正(%s %d)\n", "../z_en_gr.c", 1043);
        Actor_Kill(&this->actor);
        return;
    }
    func_80061ED4(&this->actor.colChkInfo, NULL, &D_80A4DEB4);
    ActorShape_Init(&this->actor.shape, D_80A4DF10[(this->actor.params >> 10) & 1], ActorShadow_DrawFunc_Circle, 9.4f);
    this->actor.shape.unk_14 = 200;
    func_80A4BE10(this, globalCtx);
    func_80A4C188(this, globalCtx);
    func_80A4C1C4(this, globalCtx, 0);
    func_80A4C264(this);
    func_80A4BE54(this, globalCtx);
    func_80A4D5E0(this);
    // Translation: (Goroiwa)
    osSyncPrintf("(ごろ岩)(arg 0x%04x)(rail %d)(end %d)(bgc %d)(hit %d)\n", this->actor.params, this->actor.params & 0xFF, (this->actor.params >> 8) & 3, (this->actor.params >> 10) & 1, this->actor.initPosRot.rot.z & 1);
}

void EnGoroiwa_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    Collider_DestroyJntSph(globalCtx, &THIS->collider);
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Goroiwa/func_80A4D5E0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Goroiwa/func_80A4D624.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Goroiwa/func_80A4D8CC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Goroiwa/func_80A4D944.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Goroiwa/func_80A4D9DC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Goroiwa/func_80A4DA3C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Goroiwa/func_80A4DA7C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Goroiwa/func_80A4DAD0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Goroiwa/func_80A4DB90.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Goroiwa/func_80A4DC00.s")

void EnGoroiwa_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnGoroiwa* this = THIS;
    Player* player = PLAYER;
    s32 pad;
    UNK_TYPE sp30;
    s32 temp_v0_2;

    if (!(player->stateFlags1 & 0x300000C0)) {
        if (this->timer > 0) {
            this->timer--;
        }
        this->actionFunc(this, globalCtx);
        temp_v0_2 = (this->actor.params >> 10) & 1;
        if (temp_v0_2 != 0) {
            if (temp_v0_2 == 1) {
                func_8002E4B4(globalCtx, &this->actor, 0.0f, 0.0f, 0.0f, 0x1C);
            }
        } else {
            this->actor.groundY = func_8003C9A4(&globalCtx->colCtx, &this->actor.floorPoly, &sp30, &this->actor, &this->actor.posRot.pos);
        }
        func_80A4CED8(this, globalCtx);
        if (this->actor.xzDistFromLink < 300.0f) {
            func_80A4BCA0(this);
            if (this->unk_1D3 & 1 && this->timer <= 0) {
                CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &this->collider.base);
            }
            if (this->unk_1D3 & 2 && this->timer <= 0) {
                CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &this->collider.base);
            }
        }
    }
}

void EnGoroiwa_Draw(Actor* thisx, GlobalContext* globalCtx) {
    Gfx_DrawDListOpa(globalCtx, D_060006B0);
}
