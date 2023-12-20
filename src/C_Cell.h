#ifndef TOWERCONTROLLER_H__
#define TOWERCONTROLLER_H__
#include "A_Ctx.h"
#include "E_Cell.h"
#include "A_Common.h"
#include "A_Factory.h"
#include "E_Input.h"
#include "GUI_Button.h"
#include "E_UIManifest.h"

// tower的初始化
void TowerController_Init(Context* ctx) {

    for (int i = 0; i < 6; i++) {

        CellEntity* tower =
            Factory_CreateCell(BLUE, Vector2_New(-90, 160 - i * cellsize), Vector2_New(20, 20), ctx->towerIDRecord);

        // 一定要找一个东西把数据存下来

        ctx->towers[ctx->towerCount] = tower;
        ctx->towerCount++;
        ctx->towerIDRecord++;
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

            ctx->towerClickID = tower->ID;

            if (panel->isOpen) {
                for (int i = 0; i < 3; i++) {
                    int typeID = ctx->typeTower[i];
                    UIManifestPanel_AddElement(panel, Vector2_New(tower->pos.x - 20, tower->pos.y), typeID);
                }
            } else {
                UIManifest_Close(panel);
            }
        }
    }
}

void TowerControllerEle_IsClick(Context* ctx) {
    InputEntity* input = &ctx->input;
    UIManifestPanel* panel = &ctx->panel;
    CellEntity** towers = ctx->towers;
    if (panel->isOpen) {

        for (int i = 0; i < ctx->panel.eleCount; i++) {

            UIManifest* ele = &ctx->panel.elements[i];

            ele->isClick = UIManifestEle_IsMouseInside(ele, input->mouseWorldPos);
            if (ele->isClick && input->isMouseDown) {

                int index = FindIndex_TowerByID(ctx, ctx->towerClickID);
                
                towers[index]->color = ele->btn.bgColor;

                UIManifest_Close(panel);
                break;
            }
        }
        // if (ele->isClick && input->isMouseDown) {

        //     ctx->towers[ctx->towerIDRecord]->color = ele->btn.bgColor;

        // }
    }
}

#endif