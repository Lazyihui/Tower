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

#endif