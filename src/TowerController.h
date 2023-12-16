#ifndef TOWERCONTROLLER_H__
#define TOWERCONTROLLER_H__
#include "Context.h"
#include "CellEntity.h"
#include "Common.h"
#include "Factory.h"
#include "InputEntity.h"

void TowerController_Init(Context* ctx) {

    for (int i = 0; i < 6; i++) {
        CellEntity* tower = Factory_CreateCell(BLUE, Vector2_New(-90, 180 - i * cellsize), Vector2_New(20, 20));
        //一定要找一个东西把数据存下来
        ctx->towers[ctx->towerCount] = tower;
        ctx->towerCount++;
    }
}

void 


#endif