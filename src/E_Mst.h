#ifndef MONSTERENTITY_H__
#define MONSTERENTITY_H__
#include "../include/raylib.h"
#include "../include/raymath.h"

typedef struct TM_Mst {
    int typeID;
    Color color;
    float radius;
    float speed;
    int hp;
} TM_Mst;

typedef struct E_Mst {
    int id;
    int typeID; // 1 Small, 2 Middle, 3 Big
    Color color;
    float radius;
    float speed;
    int hp;

    Vector2 pos;
    Vector2 moveAxis;
    bool isLive;

} E_Mst;

void E_Mst_Input(E_Mst* mst) {
    mst->moveAxis.y = -1;
}

void E_Mst_Move(E_Mst* mst, Vector2 moveAxis, float dt) {
    Vector2* posptr = &mst->pos;
    Vector2 offset = Vector2Normalize(moveAxis);
    offset = Vector2Scale(offset, mst->speed * dt);
    *posptr = Vector2Add(*posptr, offset);
}


void E_Mst_Draw(E_Mst* mst) {
    DrawCircle(mst->pos.x, mst->pos.y, mst->radius, mst->color);
}

#endif