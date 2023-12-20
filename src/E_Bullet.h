#ifndef E_BULLET_H__
#define E_BULLET_H__

#include "../include/raylib.h"
#include "../include/raymath.h"

typedef struct E_Bullet
{
    Color color ;
    Vector2 pos;
    Vector2 moveAxix;
    float radius;
    float speed ;
    bool isInsideMst;    
}E_Bullet;


// 向敌人移动
void E_Bullet_InputByTarget(E_Bullet *blt,Vector2 tarGetPos){

    blt->moveAxix=Vector2Subtract(tarGetPos,blt->pos);
}

void E_Bullet_Move(E_Bullet *blt ,float dt){
    
}


void E_Bullet_Draw(E_Bullet *blt){
    DrawCircle(blt->pos.x,blt->pos.y,blt->radius,blt->color);
}
#endif