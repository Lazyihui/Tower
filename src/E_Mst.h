#ifndef MONSTERENTITY_H__
#define MONSTERENTITY_H__
#include "../include/raylib.h"
#include "../include/raymath.h"

typedef struct MonsterEntity {
    Vector2 pos;
    Vector2 moveAxis;
    Color color;
    float radius;
    float speed;
    bool isLive;
} MonsterEntity;

void MonsterEntity_Input(MonsterEntity* mst) {
    mst->moveAxis.y = -1;
}

void MonsterEntity_Move(MonsterEntity* mst, Vector2 moveAxis, float dt) {
    Vector2* posptr = &mst->pos;
    Vector2 offset = Vector2Normalize(moveAxis);
    offset = Vector2Scale(offset, mst->speed * dt);
    *posptr = Vector2Add(*posptr, offset);
}

void Draw_MonsterEntity(MonsterEntity* mst) {
    DrawCircle(mst->pos.x, mst->pos.y, mst->radius, mst->color);
}

#endif