#include <stdio.h>
#include "../include/raylib.h"
#include "../include/raymath.h"
#include "Context.h"
#include "Common.h"
#include "UIController.h"
#include "MonsterEntity.h"
#include "MonsterController.h"
#include "TowerEntity.h"
#include "TowerController.h"

void Draw_AllWorld(Context* ctx) {
    // 路
    DrawRectangle(-50, -200, 100, 400, BROWN);
    // tower
    for (int i = 0; i < ctx->towerCount; i++) {
        TowerEntity* UITower = &ctx->towers[i];

        Draw_UItower(UITower);
    }
}

// offset+target

int main() {
    InitWindow(800, 400, "Tower");
    Context ctx = {0};
    ContextInit(&ctx);

    while (!WindowShouldClose()) {

        float dt = GetFrameTime();
        BeginDrawing();
        // 世界 在中心
        BeginMode2D(ctx.camera.camera);
        ClearBackground(RAYWHITE);
        
        // CameraEntity_Follow();

        if (ctx.gameStatus == 0) {

        } else if (ctx.gameStatus == 1) {
            Draw_AllWorld(&ctx);
            MonsterEntitySpawn_Tick(&ctx, dt);
        }

        EndMode2D();
        // UI屏幕 00 在左上角
        if (ctx.gameStatus == 0) {
            UIController_Tick(&ctx);

        } else if (ctx.gameStatus == 1) {
            UIController_WorldTick(&ctx, dt);
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}