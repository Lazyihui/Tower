#ifndef FACTORY_H__
#define FACTORY_H__
#include <stdlib.h>
#include "E_Input.h"
#include "E_Mst.h"
#include "E_Cell.h"
#include "E_Bullet.h"

E_Bullet* Factory_CreatBullet(Color color, Vector2 moveAxis, Vector2 pos, float radius, float speed) {
    E_Bullet* blt = (E_Bullet*)malloc(sizeof(E_Bullet));
    blt->color = color;
    blt->isActive = false;
    blt->moveAxis = moveAxis;
    blt->pos = pos;
    blt->radius = radius;
    blt->speed = speed;
    return blt;
}

E_Input* Factory_CreatInput() {
    // 堆: 开辟
    E_Input* input = (E_Input*)malloc(sizeof(E_Input));
    input->isMouseDown = false;
    input->mousePos = Vector2Zero();
    return input;
}



E_Mst* Factory_CreateMonster(Color color, Vector2 moveDir, Vector2 pos, float radius, float speed, int hp) {
    E_Mst* mst = (E_Mst*)malloc(sizeof(E_Mst));
    mst->isLive = true;
    mst->color = color;
    mst->moveAxis = moveDir;
    mst->pos = pos;
    mst->radius = radius;
    mst->speed = speed;
    mst->hp = hp;
    return mst;
}


//比较完整
E_Cell* Factory_CreateCell(Color color, Vector2 pos, Vector2 size, int cellIDRecord) {
    E_Cell* tower = (E_Cell*)malloc(sizeof(E_Cell));

    // tower->ID = towerID[count];
    tower->ID = cellIDRecord;
    tower->cellToTower=false;
    tower->isInside = false;
    tower->color = color;
    tower->height = size.y;
    tower->width = size.x;
    tower->pos.x = pos.x;
    tower->pos.y = pos.y;
    return tower;
}

#endif