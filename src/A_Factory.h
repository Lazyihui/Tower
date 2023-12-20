#ifndef FACTORY_H__
#define FACTORY_H__
#include <stdlib.h>
#include "E_Input.h"
#include "E_Mst.h"
#include "E_Cell.h"

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

CellEntity* Factory_CreateCell(Color color, Vector2 pos, Vector2 size, int towerIDRecord) {
    CellEntity* tower = (CellEntity*)malloc(sizeof(CellEntity));

    // tower->ID = towerID[count];
    tower->ID = towerIDRecord;

    tower->isInside = false;
    tower->color = color;
    tower->height = size.y;
    tower->width = size.x;
    tower->pos.x = pos.x;
    tower->pos.y = pos.y;
    return tower;
}

#endif