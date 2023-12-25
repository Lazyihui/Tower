#ifndef IMG_H__
#define IMG_H__

#include <stdio.h>
#include "../include/raylib.h"
#include "../include/raymath.h"
#include "A_Ctx.h"
#include "E_Cell.h"
void Draw2D_Cell(Ctx* ctx) {

    Texture2D cellimg = LoadTexture("img/cell.png");

    Rectangle source = {0.0f, 0.0f, (float)cellimg.width, (float)cellimg.height};

    Vector2 pivot = {(float)cellimg.width, cellimg.height};

    int rotation = 0;

    for (int i = 0; i < ctx->cellCount; i++) {
        E_Cell* cell = ctx->cellArr[i];
        Rectangle dest = {cell->pos.x, cell->pos.y, cellimg.width, cellimg.height};
        
        DrawTexturePro(cellimg,source,dest,pivot,rotation,WHITE);
    }



}

#endif