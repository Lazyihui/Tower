#include <stdio.h>
#include "../include/raylib.h"
#include "../include/raymath.h"
#include "A_Ctx.h"
#include "A_Common.h"
#include "E_Mst.h"
#include "C_Monster.h"
#include "E_Cell.h"
#include "C_Cell.h"
#include "E_Input.h"
#include "TowerManifestPanel.h"
#include "E_UIManifest.h"
#include "B_Login.h"
#include "B_Game.h"

// offset+target
int main() {

    InitWindow(800, 400, "Tower");

    Ctx ctx = {0};

    // ==== Init ====
    ContextInit(&ctx);
    B_Game_Init(&ctx);

    while (!WindowShouldClose()) {

        float dt = GetFrameTime();
        BeginDrawing();

        // 世界 在中心
        BeginMode2D(ctx.camera.camera);
        ClearBackground(RAYWHITE);

        // input
        E_Input* input = &ctx.input;
        Input_Process(input, ctx.camera.camera.offset);

        // CameraEntity_Follow();
        // ==== logic ====
        if (ctx.gameStatus == GAME_STATUS_LOGIN) {
            B_Login_Tick(&ctx, dt);
        } else if (ctx.gameStatus == GAME_STATUS_GAME) {
            B_Game_Tick(&ctx, dt);
        }

        // ==== Draw World ====
        if (ctx.gameStatus == GAME_STATUS_LOGIN) {

        } else if (ctx.gameStatus == GAME_STATUS_GAME) {
            B_Game_DrawWorld(&ctx);
            B_Game_DrawWorldUI(&ctx);
        }

        EndMode2D();

        // ==== Draw UI ====
        // UI屏幕 00 在左上角 draw
        if (ctx.gameStatus == GAME_STATUS_LOGIN) {
            B_Login_DrawUI(&ctx);
        } else if (ctx.gameStatus == GAME_STATUS_GAME) {
            B_Game_DrawScreenUI(&ctx);
        }

        EndDrawing();
    }
    CloseWindow();
    ContextFree(&ctx);
    return 0;
}