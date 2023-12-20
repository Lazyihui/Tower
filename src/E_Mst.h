#ifndef MONSTERENTITY_H__
#define MONSTERENTITY_H__
#include "../include/raylib.h"
#include "../include/raymath.h"

typedef struct E_Mst {
    Vector2 pos;
    Vector2 moveAxis;
    Color color;
    float radius;
    float speed;
    bool isLive;
} E_Mst;

void MonsterEntity_Input(E_Mst* mst) {
    mst->moveAxis.y = -1;
}

void MonsterEntity_Move(E_Mst* mst, Vector2 moveAxis, float dt) {
    Vector2* posptr = &mst->pos;
    Vector2 offset = Vector2Normalize(moveAxis);
    offset = Vector2Scale(offset, mst->speed * dt);
    *posptr = Vector2Add(*posptr, offset);
}

void Draw_MonsterEntity(E_Mst* mst) {
    DrawCircle(mst->pos.x, mst->pos.y, mst->radius, mst->color);
}

#endif