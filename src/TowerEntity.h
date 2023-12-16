#ifndef TOWERENETITY_H__
#define TOWERENETITY_H__
#include "../include/raylib.h"
#include "../include/raymath.h"

typedef struct TowerEntity {
    float width;
    float height;
    Vector2 pos;
    float interval;    
    Color color;
} TowerEntity;

// 画格子（塔）
void Draw_UItower(TowerEntity *tower) {
    DrawRectangle(tower->pos.x,tower->pos.y,tower->width,tower->width,tower->color);
}

#endif