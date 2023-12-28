#ifndef C_USERINTERFACE_H__
#define C_USERINTERFACE_H__

#include "A_Ctx.h"

void TowerControllerPanel_IsClick(Ctx* ctx);
void TowerControllerEle_IsClick(Ctx* ctx);

void C_UserInterface_Tick(Ctx* ctx, float dt) {
    E_Input* input = &ctx->input;
    // Tower Click
    UI_panel* panel = &ctx->panel;
    if (panel->isOpen) {
        int typeID = UI_Panel_Click(panel, input->mouseWorldPos, input->isMouseDown);
    }
    TowerControllerPanel_IsClick(ctx);
    TowerControllerEle_IsClick(ctx);
}

void TowerControllerPanel_IsClick(Ctx* ctx) {
    E_Input* input = &ctx->input;
    UI_panel* panel = &ctx->panel;

    for (int i = 0; i < ctx->cellCount; i++) {

        E_Cell* cell = ctx->cellArr[i];

        cell->isInside = E_Cell_IsMouseInside(cell, input->mouseWorldPos);

        if (cell->isInside && input->isMouseDown) {
            // 等于panel->isOpen = true; and panel->isOpen=false; 并起来
            panel->isOpen = !panel->isOpen;

            ctx->cellClickID = cell->ID;

            if (panel->isOpen) {
                for (int i = 0; i < 3; i++) {
                    int typeID = ctx->typeTower[i];
                    UI_Panel_AddElement(panel, Vector2_New(cell->pos.x - gridToXY(1), cell->pos.y), typeID);
                }
            } else {
                UI_Panel_Close(panel);
            }
        }
    }
}




//改塔
void TowerControllerEle_IsClick(Ctx* ctx) {
    E_Input* input = &ctx->input;
    UI_panel* panel = &ctx->panel;
    E_Cell** cellArr = ctx->cellArr;
    if (panel->isOpen) {

        for (int i = 0; i < ctx->panel.eleCount; i++) {

            UI_PanelEle* ele = &ctx->panel.elements[i];

            ele->isClick = UI_PanelEle_IsMouseInside(ele, input->mouseWorldPos);

            if (ele->isClick && input->isMouseDown) {

                // 找到是那一个塔
                int index = FindIndex_TowerByID(ctx, ctx->cellClickID);
                //要改成图片
                cellArr[index]->tex = ele->tex;

                UI_Panel_Close(panel);
                break;
            }
        }
    }
}

#endif