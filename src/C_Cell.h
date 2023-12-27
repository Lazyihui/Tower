#ifndef TOWERCONTROLLER_H__
#define TOWERCONTROLLER_H__
#include "A_Ctx.h"
#include "E_Cell.h"
#include "A_Common.h"
#include "A_Factory.h"
#include "E_Input.h"
#include "E_Bullet.h"
#include "GUI_Button.h"
#include "E_UIManifest.h"

// tower的初始化
void C_Cell_Init(Ctx* ctx) {
    // 盒子初始化
    for (int i = 0; i < 6; i++) {
        E_Cell* cell =
            Factory_CreateCell(ctx,BLUE, gridToPos(-7,18-i*7), Vector2_New(std_towerCell, std_towerCell), ctx->cellIDRecord);
        // 一定要找一个东西把数据存下来
        ctx->cellArr[ctx->cellCount] = cell;
        ctx->cellCount++;
        ctx->cellIDRecord++;
    }
}

void C_Cell_Tick(Ctx* ctx, float dt) {
    for (int i = 0; i < ctx->cellCount; i++) {
        E_Cell* cell = ctx->cellArr[i];
        // 生成 blt
        if (cell->cellToTower) {
            ctx->bltSpawnTimer -= dt;
            if (ctx->bltSpawnTimer <= 0) {
                // pos 有问题
                E_Bullet* blt = Factory_CreatBullet(PINK, Vector2_New(1,0), cell->pos, 5, 30);
                blt->isActive = true;
                ctx->bltarr[ctx->bltCount] = blt;
                ctx->bltCount++;
                ctx->bltSpawnTimer = ctx->bltSpawnInterval;

            }
        }
    }
}



//这个再理解一遍 E_Cell_Draw只要画一个东西的数据 然后用C_Cell_Draw画所有
void C_Cell_DrawWorld(Ctx* ctx) {
    for (int i = 0; i < ctx->cellCount; i++) {
        E_Cell* UITower = ctx->cellArr[i];
        E_Cell_Draw(UITower);
    }
}

#endif