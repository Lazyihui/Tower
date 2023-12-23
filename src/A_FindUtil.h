#ifndef A_FINDUTIL_H__
#define A_FINDUTIL_H__

#include "../include/raylib.h"
#include "../include/raymath.h"
#include "A_Ctx.h"
#include "E_Mst.h"
#include "E_Bullet.h"


//找最值
//tower找到最近的mst 
E_Mst* FindNearestMst(Ctx* ctx, Vector2 pos, float range) {

    E_Mst* mstRes = NULL;
    float nearest = 100000000;
    range *= range;

    for (int i = 0; i < ctx->mstCount; i++) {
        E_Mst* mst = ctx->mstarr[i];
        float tmp = Vector2DistanceSqr(pos, mst->pos);
        if (tmp <= range && tmp < nearest) {

            mstRes = mst;
            nearest = tmp;
        }
    }

    return mstRes;
}


#endif