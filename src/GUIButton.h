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



// 鼠标是否在按钮里
bool GUIButton_IsMouseInside(GUIButton* btn, Vector2 mousePos) {
    btn->isInside = IsRectInsideMouseRec(btn->rect, mousePos);
    return btn->isInside;
}

//按钮是否被点击
bool GUIButton_IsMouseClick(GUIButton *btn, Vector2 mousePos, bool isMouseDown) {
    
    if (GUIButton_IsMouseInside(btn, mousePos) && isMouseDown) {
        return true;
    } else {
        return false;
    }
}

#endif