#ifndef FACTORY_H__
#define FACTORY_H__
#include <stdlib.h>
#include "InputEntity.h"
#include "MonsterEntity.h"
#include "CellEntity.h"

InputEntity* Factory_CreatInput() {
    // 堆: 开辟
    InputEntity* input = (InputEntity*)malloc(sizeof(InputEntity));
    input->isMouseDown = false;
    input->mousePos = Vector2Zero();
    return input;
}

MonsterEntity* Factory_CreateMonster(Color color, Vector2 moveDir, Vector2 pos, float radius, float speed) {
    MonsterEntity* mst = (MonsterEntity*)malloc(sizeof(MonsterEntity));
    mst->isLive = true;
    mst->color = color;
    mst->moveAxis = moveDir;
    mst->pos = pos;
    mst->radius = radius;
    mst->speed = speed;
    return mst;
}

CellEntity* Factory_CreateCell(Color color, Vector2 pos, Vector2 size) {
    CellEntity* tower = (CellEntity*)malloc(sizeof(CellEntity));
    tower->isInside = false;
    tower->color = color;
    tower->height = size.y;
    tower->width = size.x;
    tower->pos.x = pos.x;
    tower->pos.y = pos.y;
    return tower;
}

// GUIButton* Factory_CreateButton(Rectangle rect, Color color) {
//     GUIButtonTower* btn = (GUIButtonTower*)malloc(sizeof(GUIButtonTower));
//     btn->rect.x = rect.x;
//     btn->rect.y = rect.y;
//     btn->rect.width = rect.width;
//     btn->rect.height = rect.height;
//     btn->isInside = false;
//     btn->bgColor = color;
// }

#endif