#ifndef _Z_EN_OKUTA_H_
#define _Z_EN_OKUTA_H_

#include "ultra64.h"
#include "global.h"

struct EnOkuta;

typedef void (*EnOkutaActionFunc)(struct EnOkuta*, GlobalContext*);

typedef struct EnOkuta {
    /* 0x0000 */ Actor actor;
    /* 0x014C */ SkelAnime skelAnime;
    /* 0x0190 */ EnOkutaActionFunc actionFunc;
    /* 0x0194 */
    union {
        s16 unk_194;
        s16 deathTimer;
        s16 freezeTimer;
        s16 flyTimer;
    };
    /* 0x0196 */ s16 unk_196;
    /* 0x0198 */ Vec3s limbDrawTable[38];
    /* 0x027C */ Vec3s transitionDrawTable[38];
    /* 0x0360 */ f32 unk_360;
    /* 0x0364 */ Vec3f unk_364;
    /* 0x0370 */ ColliderCylinder collider;
} EnOkuta; // size = 0x03BC

extern const ActorInit En_Okuta_InitVars;

#endif
