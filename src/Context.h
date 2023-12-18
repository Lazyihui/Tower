#ifndef CONTEXT_H__
#define CONTEXT_H__
#include "../include/raylib.h"
#include "Factory.h"
#include "CameraEntity.h"
#include "MonsterEntity.h"
#include "CellEntity.h"
#include "InputEntity.h"
#include "GUIButton.h"
#include "UIManifest.h"

typedef struct Context {
    CameraEntity camera;
    Vector2 targetPos;

    int windowWidth;
    int windowHeight;
    int gameStatus;

    // button
    GUIButton btnStartGame;
    GUIButton* btnTower[3];
    float time;
    float gold;
    float goldInterval;
    float goldTimer;
    float hp;

    MonsterEntity* mstarr[100];
    int mstCount;
    float mstSpawnTimer;
    float mstSpawnInterval;

    CellEntity* towers[10];
    int towerCount;
    Vector2 TwStartPos;
    int interval;

    InputEntity input;

    UIManifestPanel panel;
    int typeTower[3];

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
    ctx->mstCount = 0;
    ctx->mstSpawnTimer = 2;
    ctx->mstSpawnInterval = 2;

    ctx->towerCount = 0;
    ctx->TwStartPos.x = -90;
    ctx->TwStartPos.y = 160;

    GUIButton* btn = &ctx->btnStartGame;
    btn->bgColor = BLACK;
    btn->bgHoverColor = GRAY;
    btn->rect.x = 300;
    btn->rect.y = 170;
    btn->rect.width = 120;
    btn->rect.height = 20;
    btn->text = "start game";
    btn->textColor = WHITE;
    btn->isInside = false;

    for (int i = 0; i < 3; i++) {
        ctx->typeTower[i] = i + 1;
    }
    UIManifestPanel* panel = &ctx->panel;
    panel->eleCount = 0;
    panel->gapY = 5;
    panel->eleSize = 15;
    panel->isOpen = false;
}

// void ContextFree(Context *ctx) {
//     free();
//     free(ctx);
// }
#endif