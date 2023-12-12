#include <stdio.h>
#include "../include/raylib.h"
#include "../include/raymath.h"
#include "Context.h"
#include "CameraController.h"
#include "Common.h"
// int main() {
//     Context ctx = {0};
//     ContextInti(&ctx);
//     InitWindow(ctx.windowWidth, ctx.windowHeight, "Tower");
//     ctx.camera.zoom = 2;

//     while (!WindowShouldClose()) {
//         float dt = GetFrameTime();
//         BeginDrawing();
//         ClearBackground(BLACK);
//         DrawCircle(0, 0, 50, BLUE);

//         // Camera2D_Follow(ctx.targetPos, ctx.camera, 400, 200);
//         ctx.camera.offset.x = 400;
//         ctx.camera.offset.y = 200;
//         ctx.camera.target = ctx.targetPos;
//         DrawCircleV(ctx.targetPos, 100, RED);

//         BeginMode2D(ctx.camera);

//         EndMode2D();
//         EndDrawing();
//     }
//     CloseWindow();
//     return 0;
// }

int main() {
    InitWindow(800, 400, "Tower");
    Context ctx = {0};
    ContextInit(&ctx);
    while (!WindowShouldClose()) {

        float dt = GetFrameTime();
        BeginDrawing();
        BeginMode2D(ctx.camera.camera);
        ClearBackground(WHITE);
        // CameraEntity_Follow();

        DrawRectangle(ctx.buttonRect.x, ctx.buttonRect.y, ctx.buttonRectsize.x, ctx.buttonRectsize.y, BLACK);
        DrawText("please press to start game", ctx.buttonRect.x - 1, ctx.buttonRect.y, 10, WHITE);
        Vector2 mousePos = GetMousePosition();
        bool isInisde = IsRectInsideMouse(ctx.buttonRect, ctx.buttonRectsize.x, ctx.buttonRectsize.y, mousePos);
        if (IsMouseButtonPressed(0) && isInisde) {
            ctx.gameStatus = 1;
        }



        EndMode2D();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}