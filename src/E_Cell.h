#ifndef E_CELL_H__
#define E_CELL_H__

#include "A_Common.h"
#include "../include/raylib.h"
#include "../include/raymath.h"

typedef struct E_Cell {
    int ID;
    float width;
    float height;
    Vector2 pos;
    Color color;
    bool isInside;
} E_Cell;

// tower和鼠标的检测
bool C_Cell_IsMouseInside(E_Cell* cell, Vector2 mousePos) {
    cell->isInside = IsRectInsideMouse(cell->pos, cell->width, cell->height, mousePos);
    // return cell;
    if (cell->isInside) {
        return true;
    } else {
        return false;
    }
}

// 画格子（塔）
void C_Cell_Draw(E_Cell* cell) {
    DrawRectangle(cell->pos.x, cell->pos.y, cell->width, cell->width, cell->color);
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