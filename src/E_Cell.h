#ifndef E_CELL_H__
#define E_CELL_H__
#include "../include/raylib.h"
#include "../include/raymath.h"
#include "A_Common.h"

typedef struct E_Cell {
    int ID;
    float width;
    float height;
    Vector2 pos;
    Color color;
    Texture2D tex;
    bool isInside;
    bool cellToTower;
} E_Cell;

// tower和鼠标的检测
bool E_Cell_IsMouseInside(E_Cell* cell, Vector2 mouseWorldPos) {
    cell->isInside = IsRectInsideMousePosCenter(cell->pos, cell->width, cell->height, mouseWorldPos);
    // return cell;
    if (cell->isInside) {
        return true;
    } else {
        return false;
    }
}

// 画格子（塔）
void E_Cell_Draw(E_Cell* cell) {

    Rectangle source = {0.0f, 0.0f, (float)cell->tex.width, (float)cell->tex.height};
    // 开始画的位置
    int rotation = 0;
    
    Rectangle dest = {cell->pos.x, cell->pos.y, cell->width, cell->height};
    Vector2 pivot = {cell->width / 2, cell->height / 2};
    DrawTexturePro(cell->tex, source, dest, pivot, rotation, WHITE);
}

// 没用到目前
void C_Cell_DrawEleIsclickColor(E_Cell* cell, bool isElementClick) {
    Color color;
    if (!isElementClick) {
        color = BLUE;
    } else {
        color = GRAY;
    }
    DrawRectangle(cell->pos.x, cell->pos.y, cell->width, cell->height, color);
}

#endif