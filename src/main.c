#include <stdio.h>
#include "../include/raylib.h"
#include "../include/raymath.h"
#include "A_Ctx.h"
#include "A_FindUtil.h"
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
#include "C_InfraStructure.h"
// offset+target
int main() {

    Ctx* ctx = (Ctx*)calloc(1, sizeof(Ctx));
    // ==== Pre Init ====
    Ctx_PreInit(ctx);

    // ==== Init ====
    InitWindow(ctx->windowWidth, ctx->windowHeight, "Tower");

    //照片要在while之前初始化 照片要先有然后再画 并且要在InitWindow 之后生成
    Ctx_Init(ctx);

    B_Game_Init(ctx);
    C_InfraStructure_MstInit(ctx);
    C_InfraStructure_TowerInit(ctx);

    while (!WindowShouldClose()) {

        float dt = GetFrameTime();
        BeginDrawing();

        // 世界 在中心
        BeginMode2D(ctx->camera.camera);
        ClearBackground(RAYWHITE);

        // input
        E_Input* input = &ctx->input;
        E_Input_Process(input, ctx->camera.camera.offset);

        // CameraEntity_Follow();
        // ==== logic ====
        if (ctx->gameStatus == GAME_STATUS_LOGIN) {
            B_Login_Tick(ctx, dt);
        } else if (ctx->gameStatus == GAME_STATUS_GAME) {

            // E_Mst* m = FindNearestMst(ctx, Vector2Zero(), 50);

            // if (m != NULL) {
            //     printf("%f", m->pos.y);
            // }

            B_Game_Tick(ctx, dt);
        }

        // ==== Draw World ====
        if (ctx->gameStatus == GAME_STATUS_LOGIN) {

        } else if (ctx->gameStatus == GAME_STATUS_GAME) {
            B_Game_DrawWorld(ctx);
            B_Game_DrawWorldUI(ctx);
        }

        EndMode2D();

        // ==== Draw UI ====
        // UI屏幕 00 在左上角 draw
        if (ctx->gameStatus == GAME_STATUS_LOGIN) {
            B_Login_DrawUI(ctx);
        } else if (ctx->gameStatus == GAME_STATUS_GAME) {
            B_Game_DrawScreenUI(ctx);
        }

        EndDrawing();
    }
    CloseWindow();
    ContextFree(ctx);
    return 0;
}