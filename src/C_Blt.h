#ifndef C_BLT_H__
#define C_BLT_H__

#include "A_Ctx.h"
#include "E_Bullet.h"
#include "E_Mst.h"
#include "E_Cell.h"
#include "A_Factory.h"
#include "A_Common.h"
#include "../include/raylib.h"
#include "../include/raymath.h"

bool E_Bullet_IsInsideMst(E_Bullet* blt, E_Mst* mst);

void C_Blt_Logic(Ctx* ctx, float dt) {

    for (int j = 0; j < ctx->mstCount; j++) {
        E_Mst* mst = ctx->mstarr[j];

        for (int i = 0; i < ctx->bltCount; i++) {
            E_Bullet* blt = ctx->bltarr[i];
            if (blt->isActive) {
                // 有问题
                E_Bullet_InputByTarget(blt, mst->pos);

                E_Bullet_Move(blt, blt->moveAxis, dt);
                // blt mst 碰到消失
                blt->isActive = E_Bullet_IsInsideMst(blt, mst);
                if (blt->isActive) {
                    E_Bullet_Close(blt);
                    // 后面改
                    mst->hp -= 1;
                }
            }
        }
    }
}

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
void C_blt_Creat(Ctx* ctx, float dt) {

    if () {

        ctx->bltSpawnTimer -= dt;

        if (ctx->bltSpawnTimer <= 0) {
            for (int i = 0; i < 1; i++) {
                E_Bullet* blt = Factory_CreatBullet(PINK, blt->moveAxis, blt->pos, 5, 30);
                ctx->bltarr[ctx->bltCount] = blt;
                ctx->bltCount++;
            }
            ctx->bltSpawnTimer = ctx->bltSpawnInterval;
        }
    }
}

bool C_Blt_IsInsideMst(E_Bullet* blt, E_Mst* mst) {
    blt->isActive = IsCirlceInsideCircle(blt->radius, mst->radius, blt->pos, mst->pos);
    return blt->isActive;
}

// 这个放在哪里？
void E_Blts_Draw(Ctx* ctx) {

    for (int i = 0; i < ctx->bltCount; i++) {
        E_Bullet* blt = ctx->bltarr[i];
        if (!blt->isActive) {
            return;
        }
        E_Bullet_Draw(blt);
    }
}

void C_Blt_CreatBlt(Ctx* ctx) {
}

#endif