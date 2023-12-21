#ifndef E_BULLET_H__
#define E_BULLET_H__

#include "../include/raylib.h"
#include "../include/raymath.h"

typedef struct E_Bullet {
    Color color;
    Vector2 pos;
    Vector2 moveAxis;
    float radius;
    float speed;
    bool isActive;
} E_Bullet;

// 向敌人移动
void E_Bullet_InputByTarget(E_Bullet* blt, Vector2 tarGetPos) {

    blt->moveAxis = Vector2Subtract(tarGetPos, blt->pos);
}

void E_Bullet_Move(E_Bullet* blt, Vector2 moveAxis, float dt) {
    Vector2 offest = Vector2Normalize(moveAxis);
    offest = Vector2Scale(offest, blt->speed * dt);
    blt->pos = Vector2Add(blt->pos, offest);
}
void E_Bullet_Close(E_Bullet* blt) {
    blt->isActive = false;
}

void E_Bullet_Draw(E_Bullet* blt) {
    DrawCircle(blt->pos.x, blt->pos.y, blt->radius, blt->color);
}

#endif