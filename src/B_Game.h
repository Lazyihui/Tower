#ifndef B_GAME_H__
#define B_GAME_H__

#include "A_Ctx.h"
#include "C_Monster.h"
#include "C_Cell.h"
#include "C_UserInterface.h"
#include "C_Cell.h"
#include "C_Blt.h"
#include "C_Tower.h"


void B_Game_Init(Ctx* ctx) {
    C_Cell_Init(ctx);
}

void B_Game_Tick(Ctx* ctx, float dt) {

    E_Input* input = &ctx->input;
    // 时间
    ctx->time += dt;
    // 金钱
    ctx->goldTimer -= dt;
    if (ctx->goldTimer <= 0) {
        ctx->gold += 1;
        ctx->goldTimer = ctx->goldInterval;
    }

    // Monster Spawn
    C_mst_Tick(ctx, dt);

    // User Interface
    C_UserInterface_Tick(ctx, dt);

    // shoot
    C_Tower_FindNearestMstShoot(ctx, dt);
    C_Cell_Tick(ctx,dt);
    C_Blt_Tick(ctx, dt);
}

void B_Game_DrawWorld(Ctx* ctx) {

    // 路
    DrawRectangle(std_cell*-5, std_cell*-20, std_cell*10, std_cell*40, BROWN);

    // towerCell
    C_Cell_DrawWorld(ctx);

    // monster
    for (int i = 0; i < ctx->mstCount; i++) {
        E_Mst* mst = ctx->mstarr[i];
        if (mst->isLive) {
            E_Mst_Draw(mst);
        }
    }
    // bullet
    C_Blts_Draw(ctx);
    
}

void B_Game_DrawWorldUI(Ctx* ctx) {
    // 建造菜单
    UI_panel* panel = &ctx->panel;
    UI_Panel_Draw(panel, ctx->input.isMouseDown);
}

void B_Game_DrawScreenUI(Ctx* ctx) {

    // 时间
    DrawText("time", 20, 15, 20, BLACK);
    Text_Int(ctx->time, 63, 15, 20, ORANGE);

    // 金钱
    DrawText("gold", 20, 35, 20, BLACK);
    Text_Int(ctx->gold, 63, 35, 20, ORANGE);

    // 血量
    DrawRectangle(20, 60, 100, 15, RED);
    DrawRectangle(20, 60, ctx->hp, 15, GREEN);

    // 要改的
    if (IsKeyPressed(KEY_SPACE)) {
        ctx->hp -= 10;
    }
}

#endif