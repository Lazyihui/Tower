#ifndef TOWERCONTROLLER_H__
#define TOWERCONTROLLER_H__
#include "Context.h"
#include "CellEntity.h"
#include "Common.h"
#include "Factory.h"
#include "InputEntity.h"
#include "GUIButton.h"

void TowerController_Init(Context* ctx) {

    for (int i = 0; i < 6; i++) {
        CellEntity* tower = Factory_CreateCell(BLUE, Vector2_New(-90, 160 - i * cellsize), Vector2_New(20, 20));
        // 一定要找一个东西把数据存下来
        ctx->towers[ctx->towerCount] = tower;
        ctx->towerCount++;
    }

}

bool TowerController_IsMouseInside(CellEntity* tower, Vector2 mousePos) {
    tower->isInside = IsRectInsideMouse(tower->pos, tower->width, tower->height, mousePos);
    return tower;
}


void TowerController_TowerModelSpawn(CellEntity* towers , Vector2 mousePos,Context *ctx){

    for(int i=0;i<ctx->towerCount;i++){
        
        CellEntity *tower = ctx->towers[i];
        bool isInside = TowerController_IsMouseInside(tower,mousePos);
        if(isInside){
        }
    }
}



#endif