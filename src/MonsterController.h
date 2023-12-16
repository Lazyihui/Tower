#ifndef MONSTERCONTROLLER_H__
#define MONSTERCONTROLLER_H__
#include "Context.h"
#include "MonsterEntity.h"
#include "Common.h"

void MonsterEntitySpawn_Tick(Context* ctx, float dt) {
    // 注意
    ctx->mstSpawnTimer -= dt;
    if (ctx->mstSpawnTimer <= 0) {
        // 次数
        for (int i = 0; i < 1; i++) {
            MonsterEntity* mst = Factory_CreateMonster(RED, Vector2_New(0, -1), Vector2_New(0, 210), 5, 50);
            ctx->mstarr[ctx->mstCount] = mst;
            ctx->mstCount += 1;
        }
        ctx->mstSpawnTimer = ctx->mstSpawnInterval;
    }
    for (int i = 0; i < ctx->mstCount; i++) {
        MonsterEntity* mst = ctx->mstarr[i];
        if (mst->isLive) {
            MonsterEntity_Move(mst, mst->moveAxis, dt);
        }
    }
}

#endif