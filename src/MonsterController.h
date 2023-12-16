#ifndef MONSTERCONTROLLER_H__
#define MONSTERCONTROLLER_H__
#include "Context.h"
#include "MonsterEntity.h"

void MonsterEntitySpawn_Tick(Context* ctx, float dt) {
    //注意
    ctx->mstSpawnTimer -= dt;
    if (ctx->mstSpawnTimer <= 0) {
        //次数
        for (int i = 0; i < 1; i++) {
            MonsterEntity* mst = &ctx->mstarr[ctx->mstCount];
            mst->isLive = true;
            mst->color = RED;
            mst->moveAxis.x = 0;
            mst->moveAxis.y = -1;
            mst->pos.x = 0;
            mst->pos.y = 210;
            mst->radius = 5;
            mst->speed = 50;
            ctx->mstCount += 1;
        }
        ctx->mstSpawnTimer = ctx->mstSpawnInterval;
    }
    for (int i = 0; i < ctx->mstCount; i++) {
        MonsterEntity* mst = &ctx->mstarr[i];
        if (mst->isLive) {
            MonsterEntity_Move(mst, mst->moveAxis, dt);
            Draw_MonsterEntity(mst);
        }
    }
}

#endif