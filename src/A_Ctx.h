#ifndef CONTEXT_H__
#define CONTEXT_H__
#include <stdlib.h>
#include "../include/raylib.h"
#include "E_Camera.h"
#include "E_Mst.h"
#include "E_Cell.h"
#include "E_Tower.h"
#include "E_Input.h"
#include "E_Bullet.h"
#include "GUI_Button.h"
#include "E_UIManifest.h"

typedef struct Ctx {
    E_Camera camera;
    Vector2 targetPos;

    int windowWidth;
    int windowHeight;
    int gameStatus;

    // button
    GUIButton btnStartGame;
    float time;
    float gold;
    float goldInterval;
    float goldTimer;
    float hp;

    E_Mst* mstarr[100];
    int mstCount;
    float mstSpawnTimer;
    float mstSpawnInterval;
    Vector2 mst_spawnPos;

    E_Cell* cellArr[10];
    Vector2 cellStartPos;
    // int towerID[10];
    int cellIDRecord;
    int cellClickID;
    int cellCount;
    int interval;

    E_Input input;

    UI_panel panel;
    int typeTower[3];

    E_Bullet* bltarr[10000];
    int bltCount;
    float bltSpawnTimer;
    float bltSpawnInterval;

    // mst template
    TM_Mst* mst_template;
    int mst_templateLen;
    int mst_templateCount;

    TM_Tower* tower_template;
    int tower_templateCount;

} Ctx;

void ContextInit(Ctx* ctx) {

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

    ctx->cellCount = 0;
    ctx->cellStartPos.x = -90;
    ctx->cellStartPos.y = 160;

    // 把数组是第几个记下来
    ctx->cellIDRecord = 0;
    ctx->cellClickID = -1;
    // for (int i = 0; i < 6; i++) {
    //     ctx->towerID[i] = i;
    // }

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
    UI_panel* panel = &ctx->panel;
    panel->eleCount = 0;
    panel->gapY = 5;
    panel->eleSize = 15;
    panel->isOpen = false;

    ctx->bltCount = 0;
    ctx->bltSpawnTimer = 2;
    ctx->bltSpawnInterval = 2;
}

// 找到数组里的某个ID  之前不会写
int FindIndex_TowerByID(Ctx* ctx, int ID) {

    for (int i = 0; i < ctx->cellCount; i++) {
        E_Cell* tower = ctx->cellArr[i];
        if (tower->ID == ID) {
            return i;
        }
    }
    return -1;
}

void ContextFree(Ctx* ctx) {

    free(ctx->mst_template);

    for (int i = 0; i < ctx->cellCount; i++) {
        free(ctx->cellArr[i]);
    }

    for (int i = 0; i < ctx->mstCount; i++) {
        free(ctx->mstarr[i]);
    }

    for (int i = 0; i < ctx->bltCount; i++) {
        free(ctx->bltarr[i]);
    }

    free(ctx);
}

#endif