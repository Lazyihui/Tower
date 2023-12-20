#ifndef TOWERCONTROLLER_H__
#define TOWERCONTROLLER_H__
#include "A_Ctx.h"
#include "E_Cell.h"
#include "A_Common.h"
#include "A_Factory.h"
#include "E_Input.h"
#include "GUI_Button.h"
#include "E_UIManifest.h"

// tower的初始化
void C_Cell_Init(Ctx* ctx) {
    // 盒子初始化
    for (int i = 0; i < 6; i++) {
        C_Cell* cell =
            Factory_CreateCell(BLUE, Vector2_New(-90, 160 - i * cellsize), Vector2_New(20, 20), ctx->cellIDRecord);
        // 一定要找一个东西把数据存下来
        ctx->cellArr[ctx->cellCount] = cell;
        ctx->cellCount++;
        ctx->cellIDRecord++;
    }
}


void C_Cell_DrawWorld(Ctx* ctx) {
    for (int i = 0; i < ctx->cellCount; i++) {
        C_Cell* UITower = ctx->cellArr[i];
        Draw_TowerCell(UITower);
    }
}


#endif