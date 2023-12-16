#ifndef CONTEXT_H__
#define CONTEXT_H__
#include "../include/raylib.h"
#include "CameraEntity.h"
#include "MonsterEntity.h"
#include "TowerEntity.h"

typedef struct Context {
    CameraEntity camera;
    Vector2 targetPos;

    int windowWidth;
    int windowHeight;
    int gameStatus;

    Vector2 buttonRect;
    Vector2 buttonRectsize;

    float time;
    float gold;
    float goldInterval;
    float goldTimer;
    float hp;

    MonsterEntity mstarr[100];
    int mstCount;
    float mstSpawnTimer;
    float mstSpawnInterval;

    TowerEntity towers[10];
    int towerCount;
    Vector2 TwStartPos;
    int interval;
} Context;

void ContextInit(Context* ctx) {

    CameraEntity_Init(&ctx->camera);

    ctx->windowWidth = 800;
    ctx->windowHeight = 400;
    ctx->targetPos.x = 0;
    ctx->targetPos.y = 0;

    ctx->buttonRect.x = 300;
    ctx->buttonRect.y = 170;
    ctx->buttonRectsize.x = 300;
    ctx->buttonRectsize.y = 20;

    ctx->gameStatus = 0;
    ctx->time = 0;
    ctx->gold = 0;
    ctx->goldTimer = 2;
    ctx->goldInterval = 2;
    ctx->hp = 100;

    // monster
    ctx->mstCount = 1;
    ctx->mstSpawnTimer = 2;
    ctx->mstSpawnInterval = 2;

    ctx->towerCount = 0;
    ctx->TwStartPos.x = -90;
    ctx->TwStartPos.y = 160;
    // for (int i = 0; i < 10; i++) {

    //     TowerEntity* tower = &ctx->towers[i];

    //     printf("start %f\r\n", tower->interval);

    //     tower->color = BLUE;
    //     tower->width = 20;
    //     tower->height = 20;
    //     tower->pos.x = -90 + tower->interval;
    //     tower->pos.y = 160;
    //     tower->interval += 30;
    //     printf("%f\r\n", tower->interval);
    // }
    ctx->towers->color = BLUE;
    ctx->towers->height = 20;
    ctx->towers->width = 20;
    ctx->towers->interval = 10;
    ctx->towers->pos.x = 0;
    ctx->towers->pos.y = 0;
    ctx->towers->interval=50;

    for (int i = 0; i < 6; i++) {
        TowerEntity tw = (TowerEntity){0};
        //问题
        // tw.pos.y = ctx->TwStartPos.y - i * (ctx->towers->interval+ctx->towers->height);
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