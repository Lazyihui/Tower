#ifndef B_LOGIN_H__
#define B_LOGIN_H__

#include "A_Ctx.h"

void B_Login_Init() {
}

void B_Login_Tick(Ctx* ctx, float dt) {

    E_Input *input = &ctx->input;
    bool isInside = GUIButton_IsMouseInside(&ctx->btnStartGame, input->mousePos);
    if (isInside && input->isMouseDown) {
        ctx->gameStatus = GAME_STATUS_GAME;
    }

    
}

void B_Login_DrawWorld(Ctx* ctx) {
}

void B_Login_DrawUI(Ctx* ctx) {
    GUIButton_Draw(&ctx->btnStartGame);
}

#endif