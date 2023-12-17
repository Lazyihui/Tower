#ifndef TOWERCONTROLLER_H__
#define TOWERCONTROLLER_H__
#include "Context.h"
#include "CellEntity.h"
#include "Common.h"
#include "Factory.h"
#include "InputEntity.h"
#include "GUIButton.h"
#include "UIManifest.h"

void TowerController_Init(Context* ctx) {

    for (int i = 0; i < 6; i++) {
        CellEntity* tower = Factory_CreateCell(BLUE, Vector2_New(-90, 160 - i * cellsize), Vector2_New(20, 20));
        // 一定要找一个东西把数据存下来
        ctx->towers[ctx->towerCount] = tower;
        ctx->towerCount++;
    }
}

bool TowerController_IsMouseInside(CellEntity* tower, Vector2 mousePos) {
    tower->isInside = IsRectInsideMouse(tower->pos, tower->width, tower->height, mousePos);
    printf("a");
    return tower;
}

void TowerController_TowerModelSpawn( Vector2 mouseWoldPos, Context* ctx) {

    for (int i = 0; i < ctx->towerCount; i++) {
        CellEntity* tower = ctx->towers[i];
        UIManifestPanel* panel = &ctx->panel;
        bool isInside = TowerController_IsMouseInside(tower, mouseWoldPos);
        if (isInside) {
            // 等于panel->isOpen = true; and panel->isOpen=false; 并起来
            panel->isOpen = !panel->isOpen;
            if (panel->isOpen) {
                for (int i = 0; i < 3; i++) {
                    int typeID = ctx->typeTower[i];
                    UIManifestPanel_AddElement(panel, Vector2_New(-100, -100), typeID);
                }
            } else {
                UIManifest_Close(panel);
            }
        }
    }
}


#endif