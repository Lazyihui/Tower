#ifndef CONTEXT_H__
#define CONTEXT_H__
#include "../include/raylib.h"
#include "Factory.h"
#include "CameraEntity.h"
#include "MonsterEntity.h"
#include "CellEntity.h"
#include "InputEntity.h"
#include "GUIButton.h"

typedef struct Context {
    CameraEntity camera;
    Vector2 targetPos;

    int windowWidth;
    int windowHeight;
    int gameStatus;

    GUIButton btnStartGame;

    float time;
    float gold;
    float goldInterval;
    float goldTimer;
    float hp;

    MonsterEntity mstarr[100];
    int mstCount;
    float mstSpawnTimer;
    float mstSpawnInterval;

    CellEntity towers[10];
    int towerCount;
    Vector2 TwStartPos;
    int interval;

    InputEntity input;
} Context;

void ContextInit(Context* ctx) {

    CameraEntity_Init(&ctx->camera);

    ctx->windowWidth = 800;
    ctx->windowHeight = 400;
    ctx->targetPos.x = 0;
    ctx->targetPos.y = 0;

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

    GUIButton *btn=&ctx->btnStartGame;
    btn->bgColor=BLACK;
    btn->bgHoverColor=GRAY;
    btn->rect.x=300;
    btn->rect.y=170;
    btn->rect.width=300;
    btn->rect.height=20;
    btn->text="start game";
    btn->textColor=WHITE;
    btn->isInside=false;

    // ctx->input = Factory_CreatInput();
    
    // for (int i = 0; i < 10; i++) {

    //     CellEntity* tower = &ctx->towers[i];

    //     printf("start %f\r\n", tower->interval);

    //     tower->color = BLUE;
    //     tower->width = 20;
    //     tower->height = 20;
    //     tower->pos.x = -90 + tower->interval;
    //     tower->pos.y = 160;
    //     tower->interval += 30;
    //     printf("%f\r\n", tower->interval);
    // }
    // ctx->towers->color = BLUE;
    // ctx->towers->height = 20;
    // ctx->towers->width = 20;
    // ctx->towers->interval = 10;
    // ctx->towers->pos.x = 0;
    // ctx->towers->pos.y = 0;
    // ctx->towers->interval=50;

    // for (int i = 0; i < 6; i++) {
    //     CellEntity tw = (CellEntity){0};

    //     tw.pos.y = ctx->TwStartPos.y - i * 70;
    //     tw.pos.x = ctx->TwStartPos.x;
    //     tw.color = BLUE;
    //     tw.height = 20;
    //     tw.width = 20;
    //     ctx->towers[ctx->towerCount] = tw;
    //     ctx->towerCount++;

    //     printf("y=%f\r\n", tw.pos.y);
    //     printf("count =%d", ctx->towerCount);
    // }
}

#endif