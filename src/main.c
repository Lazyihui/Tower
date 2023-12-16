#include <stdio.h>
#include "../include/raylib.h"
#include "../include/raymath.h"
#include "Context.h"
#include "Common.h"
#include "UIController.h"
#include "MonsterEntity.h"
#include "MonsterController.h"
#include "CellEntity.h"
#include "TowerController.h"
#include "InputEntity.h"

void Draw_AllWorld(Context* ctx) {
    // 路
    DrawRectangle(-50, -200, 100, 400, BROWN);
    // tower
    for (int i = 0; i < ctx->towerCount; i++) {
        CellEntity* UITower = ctx->towers[i];
        Draw_UItower(UITower);
    }
    // monster
    for (int i = 0; i < ctx->mstCount; i++) {
        MonsterEntity* mst = ctx->mstarr[i];
        if (mst->isLive) {

            Draw_MonsterEntity(mst);
        }
    }
}

// offset+target
int main() {
    InitWindow(800, 400, "Tower");

    Context ctx = {0};
    ContextInit(&ctx);

    TowerController_Init(&ctx);

    while (!WindowShouldClose()) {

        float dt = GetFrameTime();
        BeginDrawing();
        // 世界 在中心
        BeginMode2D(ctx.camera.camera);
        ClearBackground(RAYWHITE);
        // input
        InputEntity* input = &ctx.input;
        Input_Process(input);

        // CameraEntity_Follow();
        // logic
        if (ctx.gameStatus == 0) {
            bool isInside = GUIButton_IsMouseInside(&ctx.btnStartGame, input->mousePos);

            if (isInside && input->isMouseDown) {
                ctx.gameStatus = 1;
            }
        } else if (ctx.gameStatus == 1) {

            MonsterEntitySpawn_Tick(&ctx, dt);
        }

        // Draw
        if (ctx.gameStatus == 0) {

        } else if (ctx.gameStatus == 1) {

            Draw_AllWorld(&ctx);
        }

        EndMode2D();

        // UI屏幕 00 在左上角 draw
        if (ctx.gameStatus == 0) {
            UIController_LoginDraw(&ctx);

        } else if (ctx.gameStatus == 1) {

            UIController_WorldDraw(&ctx, dt);
        }

        EndDrawing();
    }
    CloseWindow();
    return 0;
}