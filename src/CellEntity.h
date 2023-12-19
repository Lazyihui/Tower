#ifndef TOWERENETITY_H__
#define TOWERENETITY_H__
#include "../include/raylib.h"
#include "../include/raymath.h"
#include "Common.h"

typedef struct CellEntity {
    int ID;
    float width;
    float height;
    Vector2 pos;
    Color color;
    bool isInside;
} CellEntity;

// tower和鼠标的检测
bool CellEntity_IsMouseInside(CellEntity* tower, Vector2 mousePos) {
    tower->isInside = IsRectInsideMouse(tower->pos, tower->width, tower->height, mousePos);
    // return tower;
    if (tower->isInside) {
        return true;
    } else {
        return false;
    }
}



// 画格子（塔）
void Draw_TowerCell(CellEntity* tower) {
    DrawRectangle(tower->pos.x, tower->pos.y, tower->width, tower->width, tower->color);
}

void Draw_Tower(CellEntity* tower, bool isElementClick) {
    Color color;
    if (!isElementClick) {
        color = BLUE;
    } else {
        color = GRAY;
    }
    DrawRectangle(tower->pos.x, tower->pos.y, tower->width, tower->height, color);
}

#endif