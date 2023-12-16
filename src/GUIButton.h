#ifndef GUIBUTTON_H__
#define GUIBUTTON_H__
#include "../include/raylib.h"
#include "../include/raymath.h"
#include "Common.h"

typedef struct GUIButton {
    Rectangle rect;
    Color bgHoverColor;
    Color bgColor;
    bool isInside;

    const char* text;
    Color textColor;
} GUIButton;

void GUIButton_Draw(GUIButton* btn) {

    if (btn->isInside) {
        DrawRectangleRec(btn->rect, btn->bgHoverColor);
    } else {
        DrawRectangleRec(btn->rect, btn->bgColor);
    }
    DrawText(btn->text, btn->rect.x + 1, btn->rect.y, 20, btn->textColor);
}

bool GUIButton_IsMouseInside(GUIButton* btn, Vector2 mousePos) {

    btn->isInside = IsRectInsideMouseRec(btn->rect, mousePos);
    return btn->isInside;
    
    // if (isInside) {
    //     btn->isInside = true;
    //     return true;
    // } else {
    //     btn->isInside = false;
    //     return false;
    // }
}

#endif