#ifndef CONTEXT_H__
#define CONTEXT_H__
#include "../include/raylib.h"
#include "CameraEntity.h"

typedef struct Context {
    CameraEntity camera;
    Vector2 targetPos;

    int windowWidth;
    int windowHeight;
    int gameStatus;

    Vector2 buttonRect;
    Vector2 buttonRectsize;
} Context;

void ContextInit(Context* ctx) {

    CameraEntity_Init(&ctx->camera);

    ctx->windowWidth = 800;
    ctx->windowHeight = 400;
    ctx->targetPos.x = 0;
    ctx->targetPos.y = 0;

    ctx->buttonRect.x = -50;
    ctx->buttonRect.y = -10;
    ctx->buttonRectsize.x = 150;
    ctx->buttonRectsize.y = 10;

    ctx->gameStatus = 0;
}
#endif