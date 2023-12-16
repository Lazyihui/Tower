#ifndef TOWERENETITY_H__
#define TOWERENETITY_H__
#include "../include/raylib.h"
#include "../include/raymath.h"

typedef struct CellEntity {
    float width;
    float height;
    Vector2 pos;
    Color color;
} CellEntity;



// 画格子（塔）
void Draw_UItower(CellEntity *tower) {
    DrawRectangle(tower->pos.x,tower->pos.y,tower->width,tower->width,tower->color);
}

#endif