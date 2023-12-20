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
void TowerController_Init(Ctx* ctx) {

    for (int i = 0; i < 6; i++) {

        C_Cell* cell =
            Factory_CreateCell(BLUE, Vector2_New(-90, 160 - i * cellsize), Vector2_New(20, 20), ctx->cellIDRecord);

        // 一定要找一个东西把数据存下来

        ctx->cellArr[ctx->cellCount] = cell;
        ctx->cellCount++;
        ctx->cellIDRecord++;
    }
}

void TowerControllerPanel_IsClick(Ctx* ctx) {
    E_Input* input = &ctx->input;
    UI_panel* panel = &ctx->panel;

    for (int i = 0; i < ctx->cellCount; i++) {

        C_Cell* cell = ctx->cellArr[i];

        cell->isInside = CellEntity_IsMouseInside(cell, input->mouseWorldPos);

        if (cell->isInside && input->isMouseDown) {
            // 等于panel->isOpen = true; and panel->isOpen=false; 并起来
            panel->isOpen = !panel->isOpen;

            ctx->cellClickID = cell->ID;

            if (panel->isOpen) {
                for (int i = 0; i < 3; i++) {
                    int typeID = ctx->typeTower[i];
                    UIManifestPanel_AddElement(panel, Vector2_New(cell->pos.x - 20, cell->pos.y), typeID);
                }
            } else {
                UIManifest_Close(panel);
            }
        }
    }
}

void TowerControllerEle_IsClick(Ctx* ctx) {
    E_Input* input = &ctx->input;
    UI_panel* panel = &ctx->panel;
    C_Cell** cellArr = ctx->cellArr;
    if (panel->isOpen) {

        for (int i = 0; i < ctx->panel.eleCount; i++) {

            UI_PanelEle* ele = &ctx->panel.elements[i];

            ele->isClick = UIManifestEle_IsMouseInside(ele, input->mouseWorldPos);
            if (ele->isClick && input->isMouseDown) {

                int index = FindIndex_TowerByID(ctx, ctx->cellClickID);
                
                cellArr[index]->color = ele->btn.bgColor;

                UIManifest_Close(panel);
                break;
            }
        }
        // if (ele->isClick && input->isMouseDown) {

        //     ctx->cellArr[ctx->cellIDRecord]->color = ele->btn.bgColor;

        // }
    }
}

#endif