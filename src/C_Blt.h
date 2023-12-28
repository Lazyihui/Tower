#ifndef C_BLT_H__
#define C_BLT_H__
#include "../include/raylib.h"
#include "../include/raymath.h"
#include "A_Common.h"
#include "E_Mst.h"
#include "E_Cell.h"
#include "E_Bullet.h"
#include "A_Factory.h"
#include "A_Ctx.h"
#include "A_FindUtil.h"

// bool C_Blt_IsInsideMst(E_Bullet* blt, E_Mst* mst) {
//     blt->isActive = IsCirlceInsideCircle(blt->radius, mst->radius, blt->pos, mst->pos);
//     return blt->isActive;
// }

// blt 的位置
void C_Blt_CellIsClick(Ctx* ctx) {

    for (int i = 0; i < ctx->cellCount; i++) {

        E_Cell* cell = ctx->cellArr[i];
        cell->isInside = E_Cell_IsMouseInside(cell, ctx->input.mouseWorldPos);
        if (cell->isInside && ctx->input.isMouseDown) {
            for (int j = 0; j < ctx->bltCount; j++) {
                E_Bullet* blt = ctx->bltarr[j];
                // 有问题
                blt->pos = cell->pos;
            }
        }
    }
}

// 这个放在哪里？
void C_Blts_Draw(Ctx* ctx) {

    for (int i = 0; i < ctx->bltCount; i++) {
        E_Bullet* blt = ctx->bltarr[i];
        if (!blt->isActive) {
            // 跳过
            continue;
        }
        E_Bullet_Draw(blt);
    }
}

// 总的
void C_Blt_Tick(Ctx* ctx, float dt) {
    for (int i = 0; i < ctx->bltCount; i++) {
        E_Bullet* blt = ctx->bltarr[i];
        if (blt->isActive) {
            // blt 找到的range要不一样
            E_Mst* mst = FindNearestMst(ctx, blt->pos, 150);

            if (mst != NULL) {

                blt->isInside = IsCirlceInsideCircle(blt->radius, mst->radius, blt->pos, mst->pos);
                mst->isInside=blt->isInside;
                E_Bullet_InputByTarget(blt, mst->pos);
                E_Bullet_Move(blt, blt->moveAxis, dt);
            }
        }
    }
}
//blt消失
void C_Blt_Fade(Ctx* ctx) {
    for (int i = ctx->bltCount - 1; i >= 0; i--) {
        E_Bullet* blt = ctx->bltarr[i];
        if (blt->isInside) {
            ctx->bltarr[i] = ctx->bltarr[ctx->bltCount - 1];
            ctx->bltarr[ctx->bltCount - 1] = blt;
            ctx->bltCount -= 1;
        }
    }
}

#endif