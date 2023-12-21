#ifndef MONSTERCONTROLLER_H__
#define MONSTERCONTROLLER_H__
#include "A_Ctx.h"
#include "E_Mst.h"
#include "A_Common.h"

void C_mst_Tick(Ctx* ctx, float dt) {
    // 注意
    ctx->mstSpawnTimer -= dt;

    if (ctx->mstSpawnTimer <= 0) {
        // 次数
        for (int i = 0; i < 1; i++) {
            E_Mst* mst = Factory_CreateMonster(RED, Vector2_New(0, -1), Vector2_New(0, 210), 5, 50,5);
            ctx->mstarr[ctx->mstCount] = mst;
            ctx->mstCount += 1;
        }
        ctx->mstSpawnTimer = ctx->mstSpawnInterval;
    }
    
    for (int i = 0; i < ctx->mstCount; i++) {
        E_Mst* mst = ctx->mstarr[i];
        if (mst->isLive) {
            E_Mst_Move(mst, mst->moveAxis, dt);
        }
    }
}

#endif