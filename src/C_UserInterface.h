#ifndef C_USERINTERFACE_H__
#define C_USERINTERFACE_H__

#include "A_Ctx.h"

void TowerControllerPanel_IsClick(Ctx* ctx);
void TowerControllerEle_IsClick(Ctx* ctx);

void C_UserInterface_Tick(Ctx* ctx, float dt) {
    E_Input *input = &ctx->input;
    // Tower Click
    UI_panel* panel = &ctx->panel;
    if (panel->isOpen) {
        int typeID = UIManifestPanel_Click(panel, input->mouseWorldPos, input->isMouseDown);
    }
    TowerControllerPanel_IsClick(ctx);
    TowerControllerEle_IsClick(ctx);
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