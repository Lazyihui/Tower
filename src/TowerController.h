#ifndef TOWERCONTROLLER_H__
#define TOWERCONTROLLER_H__
#include "Context.h"
#include "CellEntity.h"
#include "Common.h"
#include "Factory.h"
#include "InputEntity.h"
#include "GUIButton.h"
#include "UIManifest.h"

// tower的初始化
void TowerController_Init(Context* ctx) {

    for (int i = 0; i < 6; i++) {
        CellEntity* tower = Factory_CreateCell(BLUE, Vector2_New(-90, 160 - i * cellsize), Vector2_New(20, 20));
        // 一定要找一个东西把数据存下来
        ctx->towers[ctx->towerCount] = tower;
        ctx->towerCount++;
    }
}

void TowerControllerPanel_IsClick(Context* ctx) {
    InputEntity* input = &ctx->input;
    UIManifestPanel* panel = &ctx->panel;
    for (int i = 0; i < ctx->towerCount; i++) {
        CellEntity* tower = ctx->towers[i];
        tower->isInside = CellEntity_IsMouseInside(tower, input->mouseWorldPos);
        if (tower->isInside && input->isMouseDown) {
            // 等于panel->isOpen = true; and panel->isOpen=false; 并起来
            panel->isOpen = !panel->isOpen;
            if (panel->isOpen) {
                for (int i = 0; i < 3; i++) {
                    int typeID = ctx->typeTower[i];
                    UIManifestPanel_AddElement(panel,Vector2_New(tower->pos.x-20,tower->pos.y), typeID);
                }
            } else {
                UIManifest_Close(panel);
            }
        }
    }
}



#endif