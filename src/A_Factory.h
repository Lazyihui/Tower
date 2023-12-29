#ifndef FACTORY_H__
#define FACTORY_H__
#include <stdlib.h>
#include "E_Input.h"
#include "E_Mst.h"
#include "E_Cell.h"
#include "E_Bullet.h"
#include "A_Ctx.h"
#include "Util_Template.h"


E_Bullet* Factory_CreatBullet(Color color, Vector2 moveAxis, Vector2 pos, float radius, float speed) {
    E_Bullet* blt = (E_Bullet*)malloc(sizeof(E_Bullet));
    blt->color = color;
    blt->isInside = false;
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

// 这是一种mst的写法
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

// 这是多种mst的写法
//  typeID 就是哪一种
E_Mst* Factory_CreateMonsterByTM(Ctx* ctx, int typeID, Vector2 pos) {
//空指针
    TM_Mst* tm = TM_Mst_Find(ctx, typeID);
    if (tm == NULL) {
        printf(" Factory_CreateMonsterByTM err type=%d",typeID);
        return NULL;
    }
    E_Mst* mst = (E_Mst*)malloc(sizeof(E_Mst));
    mst->isLive = true;
    mst->moveAxis = Vector2_New(0, -1);
    mst->typeID = tm->typeID;
    mst->color = tm->color;
    mst->hp = tm->hp;
    mst->radius = tm->radius;
    mst->speed = tm->speed;

    mst->pos = pos;
    mst->id = 0;

    return mst;
}

// 比较完整
E_Cell* Factory_CreateCell(Ctx* ctx, Color color, Vector2 pos, Vector2 size, int cellIDRecord) {
    E_Cell* cell = (E_Cell*)malloc(sizeof(E_Cell));

    // cell->ID = cellID[count];
    cell->tex = ctx->celltex;
    cell->ID = cellIDRecord;
    cell->cellToTower = false;
    cell->isInside = false;
    cell->color = color;
    cell->height = size.y;
    cell->width = size.x;
    cell->pos.x = pos.x;
    cell->pos.y = pos.y;
    return cell;
}

#endif