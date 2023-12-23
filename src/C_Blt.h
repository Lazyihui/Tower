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
void E_Blt_CellIsClick(Ctx* ctx) {

    for (int i = 0; i < ctx->cellCount; i++) {

        E_Cell* cell = ctx->cellArr[i];
        cell->isInside = C_Cell_IsMouseInside(cell, ctx->input.mouseWorldPos);
        if (cell->isInside && ctx->input.isMouseDown) {
            for (int j = 0; j < ctx->bltCount; j++) {
                E_Bullet* blt = ctx->bltarr[j];
                // 有问题
                blt->pos = cell->pos;
            }
        }
    }
}

void C_Blt_Tick(Ctx* ctx, float dt) {
    for (int j = 0; j < ctx->bltCount; j++) {
        E_Bullet* blt = ctx->bltarr[j];
        if (blt->isActive) {

            E_Mst* mst = FindNearestMst(ctx, blt->pos, 150);

            if (mst != NULL) {

                E_Bullet_InputByTarget(blt, mst->pos);
                E_Bullet_Move(blt, blt->moveAxis, dt);
            }
        }
    }
}

// 这个放在哪里？
void E_Blts_Draw(Ctx* ctx) {

    for (int i = 0; i < ctx->bltCount; i++) {
        E_Bullet* blt = ctx->bltarr[i];
        if (!blt->isActive) {
            // 跳过
            continue;
        }
        E_Bullet_Draw(blt);
    }
}

#endif