#ifndef TOWERCONTROLLER_H__
#define TOWERCONTROLLER_H__
#include "Context.h"
#include "TowerEntity.h"

// void UITowerController_Screen(Context* ctx, float dt) {
//     for (int i = 0; i < 5; i++) {
//         TowerEntity* tower = &ctx->towers[ctx -> towerCount];
//         ctx->towerCount += 1;

//         tower->color = BLUE;
//         tower->height = 20;
//         tower->width = 20;
//         tower->pos.x = -90 + tower->interval;
//         tower->pos.y = 180;
//         tower->interval += 30;
//     }
//     for (int i = 0; i < ctx->towerCount; i++) {
//         Draw_UItower(&ctx->towers[ctx->towerCount]);
//     }
// }

void UITowerController_Tick(Context* ctx) {
    for (int i = 0; i < 6; i++) {
        TowerEntity tw = (TowerEntity){0};
        // 问题
        //  tw.pos.y = ctx->TwStartPos.y - i * (ctx->towers->interval+ctx->towers->height);
        tw.pos.y = ctx->TwStartPos.y - i * 70;
        tw.pos.x = ctx->TwStartPos.x;
        tw.color = ctx->towers->color;
        tw.height = ctx->towers->height;
        tw.width = ctx->towers->width;

        ctx->towers[ctx->towerCount] = tw;
        ctx->towerCount++;

        printf("y=%f\r\n", tw.pos.y);
        printf("count =%d", ctx->towerCount);
    }
}

#endif