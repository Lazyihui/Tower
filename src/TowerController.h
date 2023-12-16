#ifndef TOWERCONTROLLER_H__
#define TOWERCONTROLLER_H__
#include "Context.h"
#include "CellEntity.h"
#include "Common.h"
void TowerController_Init(Context* ctx) {

    for (int i = 0; i < 6; i++) {
        CellEntity* tower = &ctx->towers[i];
        tower->color = BLUE;
        tower->height = 20;
        tower->width = 20;
        tower->pos.x = -90 ;
        tower->pos.y = 180- i*cellsize;
        ctx->towerCount++;
    }
}

#endif