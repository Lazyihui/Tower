#ifndef UICONTROLLER_H__
#define UICONTROLLER_H__
#include "../include/raylib.h"
#include "../include/raymath.h"
#include "Context.h"
#include "TowerEntity.h"

void UIController_Tick(Context* ctx) {
    DrawRectangle(ctx->buttonRect.x, ctx->buttonRect.y, ctx->buttonRectsize.x, ctx->buttonRectsize.y, BLACK);
    DrawText("please press to start game", ctx->buttonRect.x + 1, ctx->buttonRect.y, 20, WHITE);
    Vector2 mousePos = GetMousePosition();
    bool isInisde = IsRectInsideMouse(ctx->buttonRect, ctx->buttonRectsize.x, ctx->buttonRectsize.y, mousePos);
    if (IsMouseButtonPressed(0) && isInisde) {
        ctx->gameStatus = 1;
    }
}
void UIController_WorldTick(Context* ctx, float dt) {
    // 时间
    ctx->time += dt;
    DrawText("time", 20, 15, 20, BLACK);
    Text_Int(ctx->time, 63, 15, 20, ORANGE);
    // 金钱
    DrawText("gold", 20, 35, 20, BLACK);
    Text_Int(ctx->gold, 63, 35, 20, ORANGE);
    // 金钱
    ctx->goldTimer -= dt;
    if (ctx->goldTimer <= 0) {
        ctx->gold += 1;
        ctx->goldTimer = ctx->goldInterval;
    }
    // 血量
    DrawRectangle(20, 60, 100, 15, RED);
    DrawRectangle(20, 60, ctx->hp, 15, GREEN);

    if (IsKeyPressed(KEY_SPACE)) {
        ctx->hp -= 10;
    }
}



#endif