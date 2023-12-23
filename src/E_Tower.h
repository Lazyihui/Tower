#ifndef E_TOWER_H__
#define E_TOWER_H__

#include "../include/raylib.h"
#include "../include/raymath.h"

typedef struct E_Tower
{
    int id;
    int typeID;
    Vector2 pos;
    Color color;
    float width;
    float height;    
    int hurt;

}E_Tower;



void  E_Tower_Draw(E_Tower *tower){
    DrawRectangle(tower->pos.x,tower->pos.y,tower->width,tower->height,tower->color);
}

#endif