/*
 * File: z_en_ik.c
 * Overlay: ovl_En_Ik
 * Description: Iron Knuckle
 */

#include "z_en_ik.h"

#include "vt.h"

#define FLAGS 0x00000010

#define THIS ((EnIk*)thisx)

typedef void (*EnIkDrawFunc)(struct EnIk*, GlobalContext*);

void EnIk_Init(Actor* thisx, GlobalContext* globalCtx);
void EnIk_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnIk_Update(Actor* thisx, GlobalContext* globalCtx);
void EnIk_Draw(Actor* thisx, GlobalContext* globalCtx);

Actor* func_80A74674(GlobalContext* globalCtx, Actor* actor);
void func_80A74714(EnIk* this);
void func_80A747C0(EnIk* this, GlobalContext* globalCtx);
void func_80A7492C(EnIk* this, GlobalContext* globalCtx);
void func_80A74AAC(EnIk* this);
void func_80A74BA4(EnIk* this, GlobalContext* globalCtx);
void func_80A74E2C(EnIk* this);
void func_80A74EBC(EnIk* this, GlobalContext* globalCtx);
void func_80A7506C(EnIk* this);
void func_80A7510C(EnIk* this, GlobalContext* globalCtx);
void func_80A751C8(EnIk* this);
void func_80A75260(EnIk* this, GlobalContext* globalCtx);
void func_80A753D0(EnIk* this);
void func_80A7545C(EnIk* this, GlobalContext* globalCtx);
void func_80A754A0(EnIk* this);
void func_80A75530(EnIk* this, GlobalContext* globalCtx);
void func_80A755F0(EnIk* this);
void func_80A7567C(EnIk* this, GlobalContext* globalCtx);
void func_80A758B0(EnIk* this, GlobalContext* globalCtx);
void func_80A75A38(EnIk* this, GlobalContext* globalCtx);
void func_80A75FA0(Actor* thisx, GlobalContext* globalCtx);
void func_80A76798(Actor* thisx, GlobalContext* globalCtx);
void func_80A7748C(EnIk* this, GlobalContext* globalCtx);
void func_80A774BC(EnIk* this, GlobalContext* globalCtx);
void func_80A774F8(EnIk* this, GlobalContext* globalCtx);
void func_80A77844(EnIk* this, GlobalContext* globalCtx);
void func_80A77AEC(EnIk* this, GlobalContext* globalCtx);
void func_80A77B0C(EnIk* this, GlobalContext* globalCtx);
void func_80A77B3C(EnIk* this, GlobalContext* globalCtx);
void func_80A77ED0(EnIk* this, GlobalContext* globalCtx);
void func_80A77EDC(EnIk* this, GlobalContext* globalCtx);
void func_80A78160(EnIk* this, GlobalContext* globalCtx);
void func_80A779DC(EnIk* this, GlobalContext* globalCtx);

extern UNK_TYPE D_02003F80;
extern AnimationHeader D_06001C28;
extern AnimationHeader D_06002538;
extern AnimationHeader D_060029FC;
extern AnimationHeader D_060033C4;
extern AnimationHeader D_06003DBC;
extern AnimationHeader D_060045BC;
extern AnimationHeader D_0600485C;
extern AnimationHeader D_06005944;
extern AnimationHeader D_06006194;
extern AnimationHeader D_06006734;
extern AnimationHeader D_0600C114;
extern AnimationHeader D_0600CD70;
extern AnimationHeader D_0600DD50;
extern AnimationHeader D_0600ED24;
extern Gfx D_06018E78[];
extern Gfx D_06019100[];
extern SkeletonHeader D_0601E178;
extern AnimationHeader D_060203D8;
extern SkeletonHeader D_060205C0;

static ColliderCylinderInit sCylinderInit = {
    { COLTYPE_UNK10, 0x00, 0x09, 0x39, 0x20, COLSHAPE_CYLINDER },
    { 0x00, { 0x00000000, 0x00, 0x00 }, { 0xFFCFFFFF, 0x00, 0x00 }, 0x00, 0x05, 0x01 },
    { 25, 80, 0, { 0, 0, 0 } },
};

static ColliderTrisItemInit sTrisItemsInit[] = {
    {
        { 0x02, { 0x00000000, 0x00, 0x00 }, { 0xFFC3FFFF, 0x00, 0x00 }, 0x00, 0x09, 0x00 },
        { { { -10.0f, 14.0f, 2.0f }, { -10.0f, -6.0f, 2.0f }, { 9.0f, 14.0f, 2.0f } } },
    },
    {
        { 0x02, { 0x00000000, 0x00, 0x00 }, { 0xFFC3FFFF, 0x00, 0x00 }, 0x00, 0x09, 0x00 },
        { { { -10.0f, -6.0f, 2.0f }, { 9.0f, -6.0f, 2.0f }, { 9.0f, 14.0f, 2.0f } } },
    },
};

static ColliderTrisInit sTrisInit = {
    { COLTYPE_METAL_SHIELD, 0x00, 0x0D, 0x00, 0x00, COLSHAPE_TRIS },
    ARRAY_COUNT(sTrisItemsInit),
    sTrisItemsInit,
};

static ColliderQuadInit sQuadInit = {
    { COLTYPE_UNK10, 0x11, 0x00, 0x00, 0x00, COLSHAPE_QUAD },
    { 0x00, { 0x20000000, 0x00, 0x40 }, { 0x00000000, 0x00, 0x00 }, 0x81, 0x00, 0x00 },
    { { { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } } },
};

static DamageTable sDamageTable = { {
    0xD0, 0xF2, 0xE1, 0xF2, 0xD0, 0xE2, 0xF2, 0xD0, 0xF1, 0xF2, 0xF4, 0xE2, 0xE2, 0xE2, 0xE2, 0xE2,
    0xEF, 0x60, 0x60, 0x60, 0x00, 0x00, 0xF1, 0xF4, 0xF2, 0xF2, 0xF8, 0xF4, 0xFA, 0x00, 0xF4, 0x00,
} };

Vec3f D_80A78464 = { 0.0f, 0.5f, 0.0f };

// unused
Vec3f D_80A78470 = { 300.0f, 0.0f, 0.0f };

Vec3f D_80A7847C = { 800.0f, -200.0f, -5200.0f };

Vec3f D_80A78488 = { 0.0f, 0.0f, 0.0f };

Vec3f D_80A78494 = { -200.0f, -2200.0f, -200.0f };

Vec3f D_80A784A0 = { -6000.0f, 2000.0f, -3000.0f };

Vec3f D_80A784AC[] = {
    { -3000.0, -700.0, -5000.0 },
    { -3000.0, -700.0, 2000.0 },
    { 4000.0, -700.0, 2000.0 },
};

Vec3f D_80A784D0[] = {
    { 4000.0, -700.0, 2000.0 },
    { 4000.0, -700.0, -5000.0 },
    { -3000.0, -700.0, -5000.0 },
};

Vec3f D_80A784F4 = { 0.0f, 0.0f, 0.0f };

Vec3f D_80A78500 = { 0.0f, 0.3f, 0.0f };

Color_RGBA8 D_80A7850C = { 200, 200, 200, 255 };

Color_RGBA8 D_80A78510 = { 150, 150, 150, 0 };

Vec3f D_80A78514[] = {
    { 1000.0, -1000.0, 1000.0 },  { 0.0, -1000.0, 0.0 },        { -1000.0, -5000.0, -4000.0 },
    { 1000.0, -5000.0, -3000.0 }, { -1000.0, 1000.0, -6000.0 }, { -1000.0, 3000.0, -5000.0 },
    { -800.0, 1000.0, -3000.0 },  { 0.0, -4000.0, -2000.0 },    { -1000.0, -2000.0, -6000.0 },
    { 1000.0, -3000.0, 0.0 },     { 2000.0, -2000.0, -4000.0 }, { -1000.0, 0.0, -6000.0 },
    { 1000.0, -2000.0, -2000.0 }, { 0.0, -2000.0, 2100.0 },     { 0.0, 0.0, 0.0 },
    { 1000.0, -1000.0, -6000.0 }, { 2000.0, 0.0, -3000.0 },     { -1000.0, -1000.0, -4000.0 },
    { 900.0, -800.0, 2700.0 },    { 720.0f, 900.0f, 2500.0f },
};

static EnIkActionFunc sActionFuncs[] = {
    func_80A77AEC, func_80A77B0C, func_80A77B3C, func_80A7748C, func_80A774BC, func_80A774F8,
};

static EnIkDrawFunc sDrawFuncs[] = { func_80A77ED0, func_80A77EDC, func_80A77844 };

const ActorInit En_Ik_InitVars = {
    ACTOR_EN_IK,
    ACTORTYPE_BOSS,
    FLAGS,
    OBJECT_IK,
    sizeof(EnIk),
    (ActorFunc)EnIk_Init,
    (ActorFunc)EnIk_Destroy,
    (ActorFunc)EnIk_Update,
    (ActorFunc)EnIk_Draw,
};

void EnIk_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnIk* this = THIS;

    if (Actor_FindNearby(globalCtx, &this->actor, ACTOR_EN_IK, ACTORTYPE_ENEMY, 8000.0f) == NULL) {
        func_800F5B58();
    }

    Collider_DestroyTris(globalCtx, &this->unk_3EC);
    Collider_DestroyCylinder(globalCtx, &this->unk_320);
    Collider_DestroyQuad(globalCtx, &this->unk_36C);
}

void EnIk_SetupAction(EnIk* this, EnIkActionFunc actionFunc) {
    this->actionFunc = actionFunc;
}

void func_80A74398(Actor* thisx, GlobalContext* globalCtx) {
    EnIk* this = THIS;
    s32 pad;
    EffectBlureInit1 blureInit;

    thisx->update = func_80A75FA0;
    thisx->draw = func_80A76798;
    thisx->flags |= 0x400;

    Collider_InitCylinder(globalCtx, &this->unk_320);
    Collider_SetCylinder(globalCtx, &this->unk_320, thisx, &sCylinderInit);
    Collider_InitTris(globalCtx, &this->unk_3EC);
    Collider_SetTris(globalCtx, &this->unk_3EC, thisx, &sTrisInit, this->unk_40C);
    Collider_InitQuad(globalCtx, &this->unk_36C);
    Collider_SetQuad(globalCtx, &this->unk_36C, thisx, &sQuadInit);

    thisx->colChkInfo.damageTable = &sDamageTable;
    thisx->colChkInfo.mass = 0xFE;
    this->unk_2FC = 0;
    thisx->colChkInfo.health = 30;
    thisx->gravity = -1.0f;
    this->switchFlags = (thisx->params >> 8) & 0xFF;
    thisx->params &= 0xFF;

    if (thisx->params == 0) {
        thisx->colChkInfo.health += 20;
        thisx->naviEnemyId = 52;
    } else {
        Actor_SetScale(thisx, 0.012f);
        thisx->naviEnemyId = 53;
        Actor_ChangeType(globalCtx, &globalCtx->actorCtx, thisx, ACTORTYPE_ENEMY);
    }

    blureInit.p1StartColor[0] = blureInit.p1StartColor[1] = blureInit.p2StartColor[0] = blureInit.p2StartColor[1] =
        blureInit.p2StartColor[2] = blureInit.p1EndColor[0] = blureInit.p1EndColor[1] = blureInit.p2EndColor[0] =
            blureInit.p2EndColor[1] = blureInit.p2EndColor[2] = 255;

    blureInit.p2StartColor[3] = 64;
    blureInit.p1StartColor[3] = 200;
    blureInit.p1StartColor[2] = blureInit.p1EndColor[2] = 150;
    blureInit.p1EndColor[3] = blureInit.p2EndColor[3] = 0;

    blureInit.elemDuration = 8;
    blureInit.unkFlag = 0;
    blureInit.calcMode = 2;

    Effect_Add(globalCtx, &this->blureIdx, EFFECT_BLURE1, 0, 0, &blureInit);
    func_80A74714(this);

    if (this->switchFlags != 0xFF) {
        if (Flags_GetSwitch(globalCtx, this->switchFlags)) {
            Actor_Kill(thisx);
        }
    } else if (thisx->params != 0 && Flags_GetClear(globalCtx, globalCtx->roomCtx.curRoom.num)) {
        Actor_Kill(thisx);
    }
}

s32 func_80A745E4(EnIk* this, GlobalContext* globalCtx) {
    if (((this->unk_2FB != 0) || (this->actor.params == 0)) &&
        (func_800354B4(globalCtx, &this->actor, 100.0f, 0x2710, 0x4000, this->actor.shape.rot.y) != 0) &&
        (globalCtx->gameplayFrames & 1)) {
        func_80A755F0(this);
        return true;
    }
    return false;
}

Actor* func_80A74674(GlobalContext* globalCtx, Actor* actor) {
    Actor* prop = globalCtx->actorCtx.actorList[ACTORTYPE_PROP].first;

    while (prop != NULL) {
        if ((prop == actor) || (prop->id != ACTOR_BG_JYA_IRONOBJ)) {
            prop = prop->next;
            continue;
        } else if (func_8002E1A8(actor, prop, 80.0f, 0x2710)) {
            return prop;
        }

        prop = prop->next;
    }

    return NULL;
}

void func_80A74714(EnIk* this) {
    f32 frames = SkelAnime_GetFrameCount(&D_0600CD70.genericHeader);
    f32 frame;

    if (this->actor.params >= 2) {
        frame = frames - 1.0f;
    } else {
        frame = 0.0f;
    }

    SkelAnime_ChangeAnim(&this->skelAnime, &D_0600CD70, 0.0f, frame, frames, 2, 0.0f);
    this->unk_2F8 = 3;
    this->actor.speedXZ = 0.0f;
    EnIk_SetupAction(this, func_80A747C0);
}

void func_80A747C0(EnIk* this, GlobalContext* globalCtx) {
    Vec3f sp24;

    if (this->unk_320.base.acFlags & 2) {
        sp24 = this->actor.posRot.pos;
        Audio_PlayActorSound2(&this->actor, NA_SE_EN_IRONNACK_ARMOR_HIT);
        sp24.y += 30.0f;
        func_8003424C(globalCtx, &sp24);
        this->skelAnime.animPlaybackSpeed = 1.0f;
        func_800F5ACC(0x38);
    }
    if (this->skelAnime.animCurrentFrame == 5.0f) {
        Audio_PlayActorSound2(&this->actor, NA_SE_EN_IRONNACK_WAKEUP);
    }
    if (SkelAnime_FrameUpdateMatrix(&this->skelAnime)) {
        this->actor.flags |= 5;
        func_80A74AAC(this);
    }
}

void func_80A7489C(EnIk* this) {
    f32 frames = SkelAnime_GetFrameCount(&D_0600DD50.genericHeader);

    this->actor.flags |= 5;
    this->unk_2F8 = 4;
    this->actor.speedXZ = 0.0f;
    SkelAnime_ChangeAnim(&this->skelAnime, &D_0600DD50, 0.0f, 0.0f, frames, 0, 4.0f);
    EnIk_SetupAction(this, func_80A7492C);
}

void func_80A7492C(EnIk* this, GlobalContext* globalCtx) {
    s32 phi_a0 = (this->unk_2FB == 0) ? 0xAAA : 0x3FFC;
    s16 yawDiff = this->actor.yawTowardsLink - this->actor.shape.rot.y;

    if ((ABS(yawDiff) <= phi_a0) && (this->actor.xzDistFromLink < 100.0f) &&
        (ABS(this->actor.yDistFromLink) < 150.0f)) {
        if ((globalCtx->gameplayFrames & 1)) {
            func_80A74E2C(this);
        } else {
            func_80A751C8(this);
        }
    } else if ((ABS(yawDiff) <= 0x4000) && (ABS(this->actor.yDistFromLink) < 150.0f)) {
        func_80A74AAC(this);
    } else {
        func_80A74AAC(this);
    }
    func_80A745E4(this, globalCtx);
    SkelAnime_FrameUpdateMatrix(&this->skelAnime);
}

void func_80A74AAC(EnIk* this) {
    this->unk_2F8 = 5;
    if (this->unk_2FB == 0) {
        SkelAnime_ChangeAnim(&this->skelAnime, &D_0600ED24, 1.0f, 0.0f,
                             SkelAnime_GetFrameCount(&D_0600ED24.genericHeader), 0, -4.0f);
        this->actor.speedXZ = 0.9f;
    } else {
        SkelAnime_ChangeAnim(&this->skelAnime, &D_06006734, 1.0f, 0.0f,
                             SkelAnime_GetFrameCount(&D_06006734.genericHeader), 0, -4.0f);
        Audio_PlayActorSound2(&this->actor, NA_SE_EN_IRONNACK_DASH);
        this->actor.speedXZ = 2.5f;
    }
    this->actor.posRot.rot.y = this->actor.shape.rot.y;
    EnIk_SetupAction(this, func_80A74BA4);
}

void func_80A74BA4(EnIk* this, GlobalContext* globalCtx) {
    s16 temp_t0;
    s16 temp_a1;
    s16 yawDiff;
    s16 sp30;
    s16 sp2E;
    s16 phi_a3;

    if (this->unk_2FB == 0) {
        temp_t0 = 0xAAA;
        phi_a3 = 0x320;
        sp30 = 0;
        sp2E = 0x10;
    } else {
        temp_t0 = 0x3FFC;
        phi_a3 = 0x4B0;
        sp30 = 2;
        sp2E = 9;
    }
    temp_a1 = this->actor.wallPolyRot - this->actor.shape.rot.y;
    if ((this->actor.bgCheckFlags & 8) && (ABS(temp_a1) >= 0x4000)) {
        temp_a1 =
            (this->actor.yawTowardsLink > 0) ? this->actor.wallPolyRot - 0x4000 : this->actor.wallPolyRot + 0x4000;
        Math_SmoothScaleMaxMinS(&this->actor.posRot.rot.y, temp_a1, 1, phi_a3, 0);
    } else {
        Math_SmoothScaleMaxMinS(&this->actor.posRot.rot.y, this->actor.yawTowardsLink, 1, phi_a3, 0);
    }
    this->actor.shape.rot.y = this->actor.posRot.rot.y;
    yawDiff = this->actor.yawTowardsLink - this->actor.shape.rot.y;
    if ((ABS(yawDiff) <= temp_t0) && (this->actor.xzDistFromLink < 100.0f)) {
        if (ABS(this->actor.yDistFromLink) < 150.0f) {
            if ((globalCtx->gameplayFrames & 1)) {
                func_80A74E2C(this);
            } else {
                func_80A751C8(this);
            }
        }
    }
    if (func_80A74674(globalCtx, &this->actor) != NULL) {
        func_80A751C8(this);
        this->unk_2FC = 1;
    } else {
        temp_t0 = this->actor.yawTowardsLink - this->actor.shape.rot.y;
        if (ABS(temp_t0) > 0x4000) {
            this->unk_300--;
            if (this->unk_300 == 0) {
                func_80A754A0(this);
            }
        } else {
            this->unk_300 = 0x28;
        }
    }
    func_80A745E4(this, globalCtx);
    SkelAnime_FrameUpdateMatrix(&this->skelAnime);
    if ((sp30 == (s16)this->skelAnime.animCurrentFrame) || (sp2E == (s16)this->skelAnime.animCurrentFrame)) {
        Audio_PlayActorSound2(&this->actor, NA_SE_EN_IRONNACK_WALK);
    }
}

void func_80A74E2C(EnIk* this) {
    f32 frames = SkelAnime_GetFrameCount(&D_06001C28.genericHeader);

    this->unk_2FF = 1;
    this->unk_2F8 = 6;
    this->actor.speedXZ = 0.0f;
    SkelAnime_ChangeAnim(&this->skelAnime, &D_06001C28, 1.5f, 0.0f, frames, 2, -4.0f);
    EnIk_SetupAction(this, func_80A74EBC);
}

void func_80A74EBC(EnIk* this, GlobalContext* globalCtx) {
    Vec3f sp2C;

    if (this->skelAnime.animCurrentFrame == 15.0f) {
        Audio_PlayActorSound2(&this->actor, NA_SE_EN_IRONNACK_SWING_AXE);
    } else if (this->skelAnime.animCurrentFrame == 21.0f) {
        sp2C.x = this->actor.posRot.pos.x + Math_Sins(this->actor.shape.rot.y + 0x6A4) * 70.0f;
        sp2C.z = this->actor.posRot.pos.z + Math_Coss(this->actor.shape.rot.y + 0x6A4) * 70.0f;
        sp2C.y = this->actor.posRot.pos.y;
        Audio_PlayActorSound2(&this->actor, NA_SE_EN_IRONNACK_HIT_GND);
        func_8005AA1C(&globalCtx->mainCamera, 2, 0x19, 5);
        func_800AA000(this->actor.xzDistFromLink, 0xFF, 0x14, 0x96);
        func_80062CD4(globalCtx, &sp2C);
    }

    if ((17.0f < this->skelAnime.animCurrentFrame) && (this->skelAnime.animCurrentFrame < 23.0f)) {
        this->unk_2FE = 1;
    } else {
        if ((this->unk_2FB != 0) && (this->skelAnime.animCurrentFrame < 10.0f)) {
            Math_SmoothScaleMaxMinS(&this->actor.posRot.rot.y, this->actor.yawTowardsLink, 1, 0x5DC, 0);
            this->actor.shape.rot.y = this->actor.posRot.rot.y;
        }
        this->unk_2FE = 0;
    }

    if (SkelAnime_FrameUpdateMatrix(&this->skelAnime)) {
        func_80A7506C(this);
    }
}

void func_80A7506C(EnIk* this) {
    f32 frames = SkelAnime_GetFrameCount(&D_060029FC.genericHeader);

    this->unk_2FE = 0;
    this->unk_2F9 = (s8)frames;
    this->unk_2F8 = 7;
    this->unk_2FF = this->unk_2FE;
    SkelAnime_ChangeAnim(&this->skelAnime, &D_060029FC, 1.0f, 0.0f, frames, 0, -4.0f);
    Audio_PlayActorSound2(&this->actor, NA_SE_EN_IRONNACK_PULLOUT);
    EnIk_SetupAction(this, func_80A7510C);
}

void func_80A7510C(EnIk* this, GlobalContext* globalCtx) {
    f32 frames;

    if (SkelAnime_FrameUpdateMatrix(&this->skelAnime) || (--this->unk_2F9 == 0)) {
        if (this->unk_2F8 == 8) {
            func_80A7489C(this);
        } else {
            frames = SkelAnime_GetFrameCount(&D_06002538.genericHeader);
            this->unk_2F8 = 8;
            SkelAnime_ChangeAnim(&this->skelAnime, &D_06002538, 1.5f, 0.0f, frames, 3, -4.0f);
        }
    }
}

void func_80A751C8(EnIk* this) {
    f32 frames = SkelAnime_GetFrameCount(&D_060033C4.genericHeader);

    this->unk_2FF = 2;
    this->unk_300 = 0;
    this->unk_2F8 = 6;
    this->actor.speedXZ = 0.0f;
    SkelAnime_ChangeAnim(&this->skelAnime, &D_060033C4, 0.0f, 0.0f, frames, 3, -6.0f);
    this->unk_2FC = 0;
    EnIk_SetupAction(this, func_80A75260);
}

void func_80A75260(EnIk* this, GlobalContext* globalCtx) {
    f32 temp_f0;

    this->unk_300 += 0x1C2;
    temp_f0 = Math_Sins(this->unk_300);
    this->skelAnime.animPlaybackSpeed = ABS(temp_f0);

    if (this->skelAnime.animCurrentFrame > 11.0f) {
        this->unk_2FF = 3;
    }
    if (((1.0f < this->skelAnime.animCurrentFrame) && (this->skelAnime.animCurrentFrame < 9.0f)) ||
        ((13.0f < this->skelAnime.animCurrentFrame) && (this->skelAnime.animCurrentFrame < 18.0f))) {
        if ((this->unk_2FC == 0) && (this->unk_2FB != 0) && (this->skelAnime.animCurrentFrame < 10.0f)) {
            Math_SmoothScaleMaxMinS(&this->actor.posRot.rot.y, this->actor.yawTowardsLink, 1, 0x5DC, 0);
            this->actor.shape.rot.y = this->actor.posRot.rot.y;
        }
        if (this->unk_2FE < 0) {
            Audio_PlayActorSound2(&this->actor, NA_SE_EN_IRONNACK_SWING_AXE);
        }
        this->unk_2FE = 1;
    } else {
        this->unk_2FE = 0;
    }
    if (SkelAnime_FrameUpdateMatrix(&this->skelAnime)) {
        func_80A753D0(this);
    }
}

void func_80A753D0(EnIk* this) {
    f32 frames = SkelAnime_GetFrameCount(&D_06003DBC.genericHeader);

    this->unk_2FF = this->unk_2FE = 0;
    this->unk_2F8 = 8;
    SkelAnime_ChangeAnim(&this->skelAnime, &D_06003DBC, 1.5f, 0.0f, frames, 3, -4.0f);
    EnIk_SetupAction(this, func_80A7545C);
}

void func_80A7545C(EnIk* this, GlobalContext* globalCtx) {
    if (SkelAnime_FrameUpdateMatrix(&this->skelAnime)) {
        func_80A7489C(this);
        func_80A745E4(this, globalCtx);
    }
}

void func_80A754A0(EnIk* this) {
    f32 frames = SkelAnime_GetFrameCount(&D_060033C4.genericHeader);

    this->unk_2F8 = 1;
    this->unk_2FF = 3;
    this->actor.speedXZ = 0.0f;
    SkelAnime_ChangeAnim(&this->skelAnime, &D_060033C4, 0.5f, 13.0f, frames, 3, -4.0f);
    EnIk_SetupAction(this, func_80A75530);
}

void func_80A75530(EnIk* this, GlobalContext* globalCtx) {
    func_80077AF8(&this->actor.posRot.rot.y, this->actor.yawTowardsLink, 0x7D0);
    this->actor.shape.rot.y = this->actor.posRot.rot.y;
    if ((13.0f < this->skelAnime.animCurrentFrame) && (this->skelAnime.animCurrentFrame < 18.0f)) {
        if (this->unk_2FE < 0) {
            Audio_PlayActorSound2(&this->actor, NA_SE_EN_IRONNACK_SWING_AXE);
        }
        this->unk_2FE = 1;
    } else {
        this->unk_2FE = 0;
    }
    if (SkelAnime_FrameUpdateMatrix(&this->skelAnime)) {
        func_80A753D0(this);
        func_80A745E4(this, globalCtx);
    }
}

void func_80A755F0(EnIk* this) {
    f32 frames = SkelAnime_GetFrameCount(&D_0600485C.genericHeader);

    this->unk_2FE = 0;
    this->unk_2F8 = 9;
    this->actor.speedXZ = 0.0f;
    SkelAnime_ChangeAnim(&this->skelAnime, &D_0600485C, 1.0f, 0.0f, frames, 3, -4.0f);
    EnIk_SetupAction(this, func_80A7567C);
}

void func_80A7567C(EnIk* this, GlobalContext* globalCtx) {
    CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &this->unk_3EC.base);
    if (SkelAnime_FrameUpdateMatrix(&this->skelAnime)) {
        if ((ABS((s16)(this->actor.yawTowardsLink - this->actor.shape.rot.y)) <= 0x4000) &&
            (this->actor.xzDistFromLink < 100.0f) && (ABS(this->actor.yDistFromLink) < 150.0f)) {
            if ((globalCtx->gameplayFrames & 1)) {
                func_80A74E2C(this);
            } else {
                func_80A751C8(this);
            }
        } else {
            func_80A7489C(this);
        }
    }
}

void func_80A75790(EnIk* this) {
    s16 yaw;
    s16 yawDiff;

    yaw = Math_Vec3f_Yaw(&this->actor.posRot.pos, &this->unk_320.base.ac->posRot.pos);
    this->unk_2F8 = 0;
    yawDiff = yaw - this->actor.shape.rot.y;
    if (ABS(yawDiff) <= 0x4000) {
        SkelAnime_ChangeAnim(&this->skelAnime, &D_06006194, 1.0f, 0.0f,
                             SkelAnime_GetFrameCount(&D_06006194.genericHeader), 2, -4.0f);
        this->actor.speedXZ = -6.0f;
    } else {
        SkelAnime_ChangeAnim(&this->skelAnime, &D_060045BC, 1.0f, 0.0f,
                             SkelAnime_GetFrameCount(&D_060045BC.genericHeader), 2, -4.0f);
        this->actor.speedXZ = 6.0f;
    }
    this->unk_2FE = 0;
    EnIk_SetupAction(this, func_80A758B0);
}

void func_80A758B0(EnIk* this, GlobalContext* globalCtx) {
    Math_SmoothScaleMaxMinF(&this->actor.speedXZ, 0.0f, 1.0f, 1.0f, 0.0f);
    if (func_8003305C(&this->actor, &this->unk_308, globalCtx, this->actor.params + 4)) {
        this->unk_308.unk_10 = 0;
    }
    if (SkelAnime_FrameUpdateMatrix(&this->skelAnime)) {
        if (ABS((s16)(this->actor.yawTowardsLink - this->actor.shape.rot.y)) <= 0x4000) {
            func_80A7489C(this);
            func_80A745E4(this, globalCtx);
        } else {
            func_80A754A0(this);
        }
    }
}

void func_80A7598C(EnIk* this) {
    f32 frames = SkelAnime_GetFrameCount(&D_06005944.genericHeader);

    this->unk_2FE = 0;
    this->unk_2F8 = 2;
    this->actor.speedXZ = 0.0f;
    SkelAnime_ChangeAnim(&this->skelAnime, &D_06005944, 1.0f, 0.0f, frames, 2, -4.0f);
    this->unk_2F9 = 0x18;
    Audio_PlayActorSound2(&this->actor, NA_SE_EN_IRONNACK_DEAD);
    Audio_PlayActorSound2(&this->actor, NA_SE_EN_NUTS_CUTBODY);
    EnIk_SetupAction(this, func_80A75A38);
}

void func_80A75A38(EnIk* this, GlobalContext* globalCtx) {
    s32 i;
    Vec3f pos;
    Vec3f sp7C;

    if (SkelAnime_FrameUpdateMatrix(&this->skelAnime)) {
        if ((this->actor.colChkInfo.health == 0) && (this->unk_2F9 != 0)) {
            sp7C = D_80A78464;
            this->unk_2F9--;

            for (i = 0xC - (this->unk_2F9 >> 1); i >= 0; i--) {
                pos.x = this->actor.posRot.pos.x + Math_Rand_CenteredFloat(120.0f);
                pos.z = this->actor.posRot.pos.z + Math_Rand_CenteredFloat(120.0f);
                pos.y = this->actor.posRot.pos.y + 20.0f + Math_Rand_CenteredFloat(50.0f);
                EffectSsDeadDb_Spawn(globalCtx, &pos, &sp7C, &sp7C, 100, 0, 255, 255, 255, 255, 0, 0, 255, 1, 9, true);
            }
            if (this->unk_2F9 == 0) {
                Item_DropCollectibleRandom(globalCtx, &this->actor, &this->actor.posRot.pos, 0xB0);
                if (this->switchFlags != 0xFF) {
                    Flags_SetSwitch(globalCtx, this->switchFlags);
                }
                Actor_Kill(&this->actor);
            }
        }
    } else if (this->skelAnime.animCurrentFrame == 23.0f) {
        Audio_PlayActorSound2(&this->actor, NA_SE_EN_IRONNACK_WALK);
    }
}

#ifdef NON_EQUIVALENT
void func_80A75C38(EnIk* this, GlobalContext* globalCtx) {
    Vec3f sp38;
    f32 temp_f0;
    s32 temp_v0_3;
    u8 temp_t7;
    u8 prevHealth;

    if ((this->unk_2F8 != 3) && (this->unk_2F8 != 2)) {
        if (this->unk_3EC.base.acFlags & 0x80) {
            temp_f0 = SkelAnime_GetFrameCount(&D_0600485C.genericHeader) - 2.0f;
            if (this->skelAnime.animCurrentFrame < temp_f0) {
                this->skelAnime.animCurrentFrame = temp_f0;
            }
            this->unk_3EC.base.acFlags &= ~0x80;
            this->unk_320.base.acFlags &= ~0x2;
            return;
        }
        if (this->unk_320.base.acFlags & 2) {
            sp38 = this->actor.posRot.pos;
            sp38.y += 50.0f;
            func_80035650(&this->actor, &this->unk_320.body, 1);
            temp_t7 = this->actor.colChkInfo.damageEffect;
            temp_v0_3 = temp_t7 & 0xFF;
            this->unk_320.base.acFlags &= ~0x2;
            this->unk_2FD = temp_t7;

            if (((temp_v0_3 == 0) || (temp_v0_3 == 0xD)) || ((this->unk_2FB == 0) && (temp_v0_3 == 0xE))) {
                if (temp_v0_3 != 0) {
                    func_80062D60(globalCtx, &sp38);
                }
                return;
            }
            func_8003426C(&this->actor, 0x4000, 0xFF, 0, 0xC);
            prevHealth = this->actor.colChkInfo.health;
            Actor_ApplyDamage(&this->actor);
            if (this->actor.params != 0) {
                if ((prevHealth >= 11) && (this->actor.colChkInfo.health < 11)) {
                    this->unk_2FB = 1;
                    func_80032E24(&this->unk_308, 3, globalCtx);
                }
            block_23:
                if (this->actor.colChkInfo.health == 0) {
                    func_80A7598C(this);
                    func_80032C7C(globalCtx, &this->actor);
                    return;
                }
                Math_SmoothScaleMaxMinS(&this->actor.posRot.rot.y, this->actor.yawTowardsLink, 1, 0x7D0, 0);
                if ((this->actor.params == 0) && (Math_Rand_ZeroOne() < 0.5f)) {
                    if (ABS((s16)(this->actor.yawTowardsLink - this->actor.shape.rot.y)) > 0x4000) {
                        func_80A754A0(this);
                    }
                }
                if ((this->actor.params != 0) && (this->unk_2FB != 0)) {
                    if ((prevHealth >= 11) && (this->actor.colChkInfo.health < 11)) {
                        Audio_PlayActorSound2(&this->actor, NA_SE_EN_IRONNACK_ARMOR_OFF_DEMO);
                    } else {
                        Audio_PlayActorSound2(&this->actor, NA_SE_EN_IRONNACK_DAMAGE);
                        Audio_PlayActorSound2(&this->actor, NA_SE_EN_NUTS_CUTBODY);
                    }
                    func_80A75790(this);
                    return;
                }
                Audio_PlayActorSound2(&this->actor, NA_SE_EN_IRONNACK_ARMOR_HIT);
                Audio_PlayActorSound2(&this->actor, NA_SE_EN_IRONNACK_DAMAGE);
                func_80062CD4(globalCtx, &sp38);
            } else if (this->actor.colChkInfo.health < 11) {
                Actor_ChangeType(globalCtx, &globalCtx->actorCtx, &this->actor, ACTORTYPE_BOSS);
                Audio_PlaySoundAtPosition(globalCtx, &this->actor.posRot.pos, 20, NA_SE_EN_LAST_DAMAGE);
                if (this->switchFlags != 0xFF) {
                    Flags_SetSwitch(globalCtx, this->switchFlags);
                    return;
                }
            } else {
                if (prevHealth == 50) {
                    Actor_ChangeType(globalCtx, &globalCtx->actorCtx, &this->actor, 5);
                }
                goto block_23;
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Ik/func_80A75C38.s")
#endif

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Ik/func_80A75FA0.s")

Gfx* func_80A761B0(GraphicsContext* gfxCtx, u8 primR, u8 primG, u8 primB, u8 envR, u8 envG, u8 envB) {
    Gfx* displayList;
    Gfx* displayListHead;

    displayList = Graph_Alloc(gfxCtx, 4 * sizeof(Gfx));
    displayListHead = displayList;

    gDPPipeSync(displayListHead++);
    gDPSetPrimColor(displayListHead++, 0, 0, primR, primG, primB, 255);
    gDPSetEnvColor(displayListHead++, envR, envG, envB, 255);
    gSPEndDisplayList(displayListHead++);

    return displayList;
}

s32 EnIk_OverrideLimbDraw3(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, Actor* actor) {
    EnIk* this = (EnIk*)actor;

    if (limbIndex == 0xC) {
        if (this->actor.params != 0) {
            *dList = D_06018E78;
        }
    } else if (limbIndex == 0xD) {
        if (this->actor.params != 0) {
            *dList = D_06019100;
        }
    } else if ((limbIndex == 0x1A) || (limbIndex == 0x1B)) {
        if ((this->unk_2FA & 1)) {
            *dList = NULL;
        }
    } else if ((limbIndex == 0x1C) || (limbIndex == 0x1D)) {
        if (!(this->unk_2FA & 1)) {
            *dList = NULL;
        }
    }
    return 0;
}

void EnIk_PostLimbDraw3(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, Actor* actor);
#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Ik/EnIk_PostLimbDraw3.s")

void func_80A76798(Actor* thisx, GlobalContext* globalCtx) {
    EnIk* this = THIS;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_ik_inFight.c", 1309);

    func_80093D18(globalCtx->state.gfxCtx);
    func_80093D84(globalCtx->state.gfxCtx);

    if (this->actor.params == 0) {
        gSPSegment(oGfxCtx->polyOpa.p++, 0x08, func_80A761B0(globalCtx->state.gfxCtx, 245, 225, 155, 30, 30, 0));
        gSPSegment(oGfxCtx->polyOpa.p++, 0x09, func_80A761B0(globalCtx->state.gfxCtx, 255, 40, 0, 40, 0, 0));
        gSPSegment(oGfxCtx->polyOpa.p++, 0x0A, func_80A761B0(globalCtx->state.gfxCtx, 255, 255, 255, 20, 40, 30));
    } else if (this->actor.params == 1) {
        gSPSegment(oGfxCtx->polyOpa.p++, 0x08, func_80A761B0(globalCtx->state.gfxCtx, 245, 255, 205, 30, 35, 0));
        gSPSegment(oGfxCtx->polyOpa.p++, 0x09, func_80A761B0(globalCtx->state.gfxCtx, 185, 135, 25, 20, 20, 0));
        gSPSegment(oGfxCtx->polyOpa.p++, 0x0A, func_80A761B0(globalCtx->state.gfxCtx, 255, 255, 255, 30, 40, 20));
    } else if (this->actor.params == 2) {
        gSPSegment(oGfxCtx->polyOpa.p++, 0x08, func_80A761B0(globalCtx->state.gfxCtx, 55, 65, 55, 0, 0, 0));
        gSPSegment(oGfxCtx->polyOpa.p++, 0x09, func_80A761B0(globalCtx->state.gfxCtx, 205, 165, 75, 25, 20, 0));
        gSPSegment(oGfxCtx->polyOpa.p++, 0x0A, func_80A761B0(globalCtx->state.gfxCtx, 205, 165, 75, 25, 20, 0));
    } else {
        gSPSegment(oGfxCtx->polyOpa.p++, 0x08, func_80A761B0(globalCtx->state.gfxCtx, 255, 255, 255, 180, 180, 180));
        gSPSegment(oGfxCtx->polyOpa.p++, 0x09, func_80A761B0(globalCtx->state.gfxCtx, 225, 205, 115, 25, 20, 0));
        gSPSegment(oGfxCtx->polyOpa.p++, 0x0A, func_80A761B0(globalCtx->state.gfxCtx, 225, 205, 115, 25, 20, 0));
    }
    SkelAnime_DrawSV(globalCtx, this->skelAnime.skeleton, this->skelAnime.limbDrawTbl, this->skelAnime.dListCount,
                     EnIk_OverrideLimbDraw3, EnIk_PostLimbDraw3, &this->actor);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_ik_inFight.c", 1351);
}

void EnIk_StartMusic(void) {
    func_800F5ACC(0x38);
}

void func_80A76C14(EnIk* this) {
    if (func_800A56C8(&this->skelAnime, 1.0f)) {
        Audio_PlaySoundGeneral(NA_SE_EN_IRONNACK_WAKEUP, &this->actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                               &D_801333E8);
    } else if (func_800A56C8(&this->skelAnime, 33.0f)) {
        Audio_PlaySoundGeneral(NA_SE_EN_IRONNACK_WALK, &this->actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                               &D_801333E8);
    } else if (func_800A56C8(&this->skelAnime, 68.0f) || func_800A56C8(&this->skelAnime, 80.0f)) {
        Audio_PlaySoundGeneral(NA_SE_EN_IRONNACK_ARMOR_DEMO, &this->actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                               &D_801333E8);
    } else if (func_800A56C8(&this->skelAnime, 107.0f)) {
        Audio_PlaySoundGeneral(NA_SE_EN_IRONNACK_FINGER_DEMO, &this->actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                               &D_801333E8);
    } else if (func_800A56C8(&this->skelAnime, 156.0f)) {
        Audio_PlaySoundGeneral(NA_SE_EN_IRONNACK_ARMOR_DEMO, &this->actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                               &D_801333E8);
    } else if (func_800A56C8(&this->skelAnime, 188.0f)) {
        Audio_PlaySoundGeneral(NA_SE_EN_IRONNACK_WAVE_DEMO, &this->actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                               &D_801333E8);
    }
}

void func_80A76DDC(EnIk* this, GlobalContext* globalCtx, Vec3f* pos) {
    Audio_PlaySoundGeneral(NA_SE_EN_TWINROBA_TRANSFORM, &this->actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                           &D_801333E8);
}

void func_80A76E2C(EnIk* this, GlobalContext* globalCtx, Vec3f* pos) {
    s32 pad;
    Vec3f effectVelocity;
    Vec3f effectAccel;
    s32 i;
    Color_RGBA8 primColor;
    Color_RGBA8 envColor;
    s32 temp_v0;
    Vec3f effectPos;

    if (this->unk_4D4 == 0) {
        effectVelocity = D_80A784F4;
        effectAccel = D_80A78500;

        for (i = ARRAY_COUNT(D_80A78514) - 1; i >= 0; i--) {
            primColor = D_80A7850C;
            envColor = D_80A78510;
            Matrix_MultVec3f(&D_80A78514[i], &effectPos);
            temp_v0 = (Math_Rand_ZeroOne() * 20.0f) - 10.0f;
            primColor.r += temp_v0;
            primColor.g += temp_v0;
            primColor.b += temp_v0;
            envColor.r += temp_v0;
            envColor.g += temp_v0;
            envColor.b += temp_v0;
            func_8002829C(globalCtx, &effectPos, &effectVelocity, &effectAccel, &primColor, &envColor,
                          (Math_Rand_ZeroOne() * 60.0f) + 300.0f, 0);
        }

        this->unk_4D4 = 1;
        func_80A76DDC(this, globalCtx, pos);
    }
}

void func_80A77034(EnIk* this, GlobalContext* globalCtx) {
    func_8002E4B4(globalCtx, &this->actor, 75.0f, 30.0f, 30.0f, 5);
}

s32 func_80A7707C(EnIk* this) {
    return SkelAnime_FrameUpdateMatrix(&this->skelAnime);
}

CsCmdActorAction* EnIk_GetNpcAction(GlobalContext* globalCtx, s32 actionIdx) {
    if (globalCtx->csCtx.state != 0) {
        return globalCtx->csCtx.npcActions[actionIdx];
    } else {
        return NULL;
    }
}

void func_80A770C0(EnIk* this, GlobalContext* globalCtx, s32 actionIdx) {
    CsCmdActorAction* npcAction = EnIk_GetNpcAction(globalCtx, actionIdx);

    if (npcAction != NULL) {
        this->actor.posRot.pos.x = npcAction->startPos.x;
        this->actor.posRot.pos.y = npcAction->startPos.y;
        this->actor.posRot.pos.z = npcAction->startPos.z;
        this->actor.posRot.rot.y = this->actor.shape.rot.y = npcAction->rot.y;
    }
}

f32 EnIk_AnimCurrentFrame(EnIk* this) {
    return this->skelAnime.animCurrentFrame;
}

void func_80A77148(EnIk* this) {
    this->action = 0;
    this->drawMode = 0;
    this->actor.shape.unk_14 = 0;
}

void func_80A77158(EnIk* this, GlobalContext* globalCtx) {
    SkelAnime_ChangeAnim(&this->skelAnime, &D_0600C114, 1.0f, 0.0f, SkelAnime_GetFrameCount(&D_0600C114.genericHeader),
                         2, 0.0f);
    func_80A770C0(this, globalCtx, 4);
    this->action = 1;
    this->drawMode = 1;
    this->actor.shape.unk_14 = 0xFF;
}

void func_80A771E4(EnIk* this) {
    SkelAnime_ChangeAnim(&this->skelAnime, &D_0600C114, 1.0f, 0.0f, SkelAnime_GetFrameCount(&D_0600C114.genericHeader),
                         2, 0.0f);
    this->action = 2;
    this->drawMode = 1;
    this->unk_4D4 = 0;
    this->actor.shape.unk_14 = 0xFF;
}

void func_80A77264(EnIk* this, GlobalContext* globalCtx, s32 arg2) {
    if ((arg2 != 0) && (EnIk_GetNpcAction(globalCtx, 4) != NULL)) {
        func_80A78160(this, globalCtx);
    }
}

void func_80A772A4(EnIk* this) {
    Audio_PlaySoundGeneral(NA_SE_EN_IRONNACK_STAGGER_DEMO, &this->actor.projectedPos, 4, &D_801333E0, &D_801333E0,
                           &D_801333E8);
}

void func_80A772EC(EnIk* this, GlobalContext* globalCtx) {
    static Vec3f D_80A78FA0;
    s32 pad[2];
    f32 wDest;

    SkinMatrix_Vec3fMtxFMultXYZW(&globalCtx->mf_11D60, &this->actor.posRot.pos, &D_80A78FA0, &wDest);
    Audio_PlaySoundGeneral(NA_SE_EN_IRONNACK_DEAD, &D_80A78FA0, 4, &D_801333E0, &D_801333E0, &D_801333E8);
}

void func_80A7735C(EnIk* this, GlobalContext* globalCtx) {
    s32 pad[3];
    f32 frames = SkelAnime_GetFrameCount(&D_060203D8.genericHeader);

    SkelAnime_InitSV(globalCtx, &this->skelAnime, &D_060205C0, NULL, this->limbDrawTable, this->transitionDrawTable,
                     30);
    SkelAnime_ChangeAnim(&this->skelAnime, &D_060203D8, 1.0f, 0.0f, frames, 2, 0.0f);
    this->action = 3;
    this->drawMode = 2;
    func_80A770C0(this, globalCtx, 4);
    func_80A772EC(this, globalCtx);
    this->actor.shape.unk_14 = 0xFF;
}

void func_80A77434(EnIk* this, GlobalContext* globalCtx) {
    this->action = 4;
    this->drawMode = 2;
    func_80A772A4(this);
    this->actor.shape.unk_14 = 0xFF;
}

void func_80A77474(EnIk* this, GlobalContext* globalCtx) {
    this->action = 5;
    this->drawMode = 0;
    this->actor.shape.unk_14 = 0;
}

void func_80A7748C(EnIk* this, GlobalContext* globalCtx) {
    func_80A77034(this, globalCtx);
    func_80A779DC(this, globalCtx);
}

void func_80A774BC(EnIk* this, GlobalContext* globalCtx) {
    func_80A7707C(this);
    func_80A77034(this, globalCtx);
    func_80A779DC(this, globalCtx);
}

void func_80A774F8(EnIk* this, GlobalContext* globalCtx) {
    if (EnIk_GetNpcAction(globalCtx, 4) == NULL) {
        Actor_Kill(&this->actor);
    }
}

s32 EnIk_OverrideLimbDraw2(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, Actor* actor) {
    EnIk* this = (EnIk*)actor;

    if ((limbIndex == 0xD) || (limbIndex == 0x1A) || (limbIndex == 0x1B)) {
        if (EnIk_AnimCurrentFrame(this) >= 30.0f) {
            *dList = NULL;
        }
    }

    return 0;
}

void EnIk_PostLimbDraw2(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, Actor* actor);
#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Ik/EnIk_PostLimbDraw2.s")

void func_80A77844(EnIk* this, GlobalContext* globalCtx) {
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    SkelAnime* skelAnime = &this->skelAnime;
    s32 pad[2];

    OPEN_DISPS(gfxCtx, "../z_en_ik_inAwake.c", 322);

    func_8002EBCC(&this->actor, globalCtx, 0);
    func_80093D18(gfxCtx);
    func_80093D84(gfxCtx);
    gSPSegment(oGfxCtx->polyOpa.p++, 0x08, func_80A761B0(gfxCtx, 245, 225, 155, 30, 30, 0));
    gSPSegment(oGfxCtx->polyOpa.p++, 0x09, func_80A761B0(gfxCtx, 255, 40, 0, 40, 0, 0));
    gSPSegment(oGfxCtx->polyOpa.p++, 0x0A, func_80A761B0(gfxCtx, 255, 255, 255, 20, 40, 30));
    SkelAnime_DrawSV(globalCtx, skelAnime->skeleton, skelAnime->limbDrawTbl, skelAnime->dListCount,
                     EnIk_OverrideLimbDraw2, EnIk_PostLimbDraw2, &this->actor);

    CLOSE_DISPS(gfxCtx, "../z_en_ik_inAwake.c", 345);
}

void func_80A779DC(EnIk* this, GlobalContext* globalCtx) {
    CsCmdActorAction* npcAction = EnIk_GetNpcAction(globalCtx, 4);
    u32 action;
    u32 currentNpcAction;

    if (npcAction != NULL) {
        action = npcAction->action;
        currentNpcAction = this->npcAction;
        if (action != currentNpcAction) {
            switch (action) {
                case 1:
                    func_80A77148(this);
                    break;
                case 2:
                    func_80A77158(this, globalCtx);
                    break;
                case 3:
                    func_80A771E4(this);
                    break;
                case 4:
                    func_80A78160(this, globalCtx);
                    break;
                case 5:
                    func_80A7735C(this, globalCtx);
                    break;
                case 6:
                    func_80A77434(this, globalCtx);
                    break;
                case 7:
                    func_80A77474(this, globalCtx);
                    break;
                default:
                    osSyncPrintf("En_Ik_inConfrontion_Check_DemoMode:そんな動作は無い!!!!!!!!\n");
            }

            this->npcAction = action;
        }
    }
}

void func_80A77AEC(EnIk* this, GlobalContext* globalCtx) {
    func_80A779DC(this, globalCtx);
}

void func_80A77B0C(EnIk* this, GlobalContext* globalCtx) {
    func_80A77034(this, globalCtx);
    func_80A779DC(this, globalCtx);
}

void func_80A77B3C(EnIk* this, GlobalContext* globalCtx) {
    s32 sp24;

    sp24 = func_80A7707C(this);
    func_80A76C14(this);
    func_80A77034(this, globalCtx);
    func_80A779DC(this, globalCtx);
    func_80A77264(this, globalCtx, sp24);
}

void EnIk_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnIk* this = THIS;

    if (this->action < 0 || this->action >= ARRAY_COUNT(sActionFuncs) || sActionFuncs[this->action] == NULL) {
        osSyncPrintf(VT_FGCOL(RED) "メインモードがおかしい!!!!!!!!!!!!!!!!!!!!!!!!!\n" VT_RST);
        return;
    }

    sActionFuncs[this->action](this, globalCtx);
}

s32 EnIk_OverrideLimbDraw1(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, Actor* actor) {
    EnIk* this = (EnIk*)actor;
    f32 animCurrentFrame;

    switch (limbIndex) {
        case 0x11:
            animCurrentFrame = this->skelAnime.animCurrentFrame;
            if (animCurrentFrame < 120.0f) {
                *dList = NULL;
            } else {
                func_80A76E2C(this, globalCtx, pos);
            }
            break;
        case 0x1D:
        case 0x1E:
            *dList = NULL;
            break;
    }

    return 0;
}

void EnIk_PostLimbDraw1(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, Actor* actor);
#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Ik/EnIk_PostLimbDraw1.s")

void func_80A77ED0(EnIk* this, GlobalContext* globalCtx) {
}

void func_80A77EDC(EnIk* this, GlobalContext* globalCtx) {
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    SkelAnime* skelAnime = &this->skelAnime;
    s32 pad[2];

    OPEN_DISPS(gfxCtx, "../z_en_ik_inConfrontion.c", 630);

    func_8002EBCC(&this->actor, globalCtx, 0);
    func_80093D18(gfxCtx);
    func_80093D84(gfxCtx);
    gSPSegment(oGfxCtx->polyOpa.p++, 0x08, func_80A761B0(gfxCtx, 245, 225, 155, 30, 30, 0));
    gSPSegment(oGfxCtx->polyOpa.p++, 0x09, func_80A761B0(gfxCtx, 255, 40, 0, 40, 0, 0));
    gSPSegment(oGfxCtx->polyOpa.p++, 0x0A, func_80A761B0(gfxCtx, 255, 255, 255, 20, 40, 30));
    SkelAnime_DrawSV(globalCtx, skelAnime->skeleton, skelAnime->limbDrawTbl, skelAnime->dListCount,
                     EnIk_OverrideLimbDraw1, EnIk_PostLimbDraw1, &this->actor);

    CLOSE_DISPS(gfxCtx, "../z_en_ik_inConfrontion.c", 653);
}

void EnIk_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnIk* this = THIS;

    if (this->drawMode < 0 || this->drawMode >= ARRAY_COUNT(sDrawFuncs) || sDrawFuncs[this->drawMode] == NULL) {
        osSyncPrintf(VT_FGCOL(RED) "描画モードがおかしい!!!!!!!!!!!!!!!!!!!!!!!!!\n" VT_RST);
        return;
    }

    sDrawFuncs[this->drawMode](this, globalCtx);
}

void func_80A780D0(EnIk* this, GlobalContext* globalCtx) {
    if (this->actor.params == 0) {
        if (!(gSaveContext.eventChkInf[3] & 0x800)) {
            this->actor.update = EnIk_Update;
            this->actor.draw = EnIk_Draw;
            Actor_SetScale(&this->actor, 0.01f);
        } else {
            func_80A78160(this, globalCtx);
            EnIk_StartMusic();
        }
    }
    osSyncPrintf("En_Ik_inConfrontion_Init : %d !!!!!!!!!!!!!!!!\n", this->actor.params);
}

void func_80A78160(EnIk* this, GlobalContext* globalCtx) {
    this->actor.update = func_80A75FA0;
    this->actor.draw = func_80A76798;
    this->actor.flags |= 5;
    gSaveContext.eventChkInf[3] |= 0x800;
    Actor_SetScale(&this->actor, 0.012f);
    func_80A7489C(this);
}

void func_80A781CC(Actor* thisx, GlobalContext* globalCtx) {
    EnIk* this = THIS;

    if (!Gameplay_InCsMode(globalCtx)) {
        this->actor.update = EnIk_Update;
        this->actor.draw = EnIk_Draw;
        Cutscene_SetSegment(globalCtx, &D_02003F80);
        gSaveContext.cutsceneTrigger = 1;
        Actor_SetScale(&this->actor, 0.01f);
        gSaveContext.eventChkInf[3] |= 0x1000;
        func_80A7735C(this, globalCtx);
    }
}

void EnIk_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnIk* this = THIS;
    s32 flag = this->actor.params & 0xFF00;

    if (((this->actor.params & 0xFF) == 0 && (gSaveContext.eventChkInf[3] & 0x1000)) ||
        (flag != 0 && Flags_GetSwitch(globalCtx, flag >> 8))) {
        Actor_Kill(&this->actor);
    } else {
        ActorShape_Init(&this->actor.shape, 0.0f, ActorShadow_DrawFunc_Circle, 30.0f);
        SkelAnime_InitSV(globalCtx, &this->skelAnime, &D_0601E178, &D_0600C114, this->limbDrawTable,
                         this->transitionDrawTable, 30);
        func_80A74398(&this->actor, globalCtx);
        func_80A780D0(this, globalCtx);
    }
}
