#ifndef C_TOWER_H__
#define C_TOWER_H__

#include "../include/raylib.h"
#include "../include/raymath.h"
#include "E_Mst.h"
#include "E_Cell.h"
#include "E_Bullet.h"
#include "A_Common.h"
#include "A_FindUtil.h"
#include "A_Ctx.h"

void C_Tower_FindNearestMstShoot(Ctx* ctx, float dt) {
    for (int i = 0; i < ctx->cellCount; i++) {
        E_Cell* cell = ctx->cellArr[i];

        cell->isInside = C_Cell_IsMouseInside(cell, ctx->input.mouseWorldPos);

        // 后面一个条件要改 改成点击panel里的某个元素 C_UserInterFace.h
        if (cell->isInside && ctx->input.isMouseDown) {
            // 要改 改成tower的攻击范围

            printf("%d", cell->isInside);
            
            // 生成blt 去攻击mst
            cell->cellToTower = true;

            
        }
    }
}

#endif