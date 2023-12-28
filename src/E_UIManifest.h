#ifndef UIMANIDEST_H__
#define UIMANIDEST_H__

#include "GUI_Button.h"
#include "E_Cell.h"
#include "../include/raylib.h"
#include "../include/raymath.h"

// 元素
typedef struct UI_PanelEle {
    int typeID;
    int index;
    float speed;
    float hurt;
    bool isClick;
    Texture2D tex;
    GUIButton btn;
} UI_PanelEle;

// 换一种写法
//  void UIManifest_CreatTower(UI_PanelEle *UITower,){

// }
// element
UI_PanelEle UI_PanelEle_CraeteTowerType(int index, int typeID, Vector2 pos, Vector2 size,Texture2D red,Texture2D pink,Texture2D purple) {
    
    UI_PanelEle ele = (UI_PanelEle){0};
    ele.index = index;
    ele.typeID = typeID;
    Color color;
    Texture2D tex;
    switch (typeID) {
    case 1:
        tex = red;

        color = RED;
        ele.speed = 10;
        ele.hurt = 1;
        break;
    case 2:
        tex = pink;

        color = PINK;
        ele.hurt = 2;
        ele.speed = 20;
        break;
    case 3:
        tex = purple;

        color = PURPLE;
        ele.hurt = 3;
        ele.speed = 20;
        break;

    default:
        color = BLACK;
        printf("ERR");
        break;
    }

    GUIButton* btn = &ele.btn;
    btn->bgColor = color;
    btn->rect.x = pos.x;
    btn->rect.y = pos.y;
    btn->rect.width = size.x;
    btn->rect.height = size.y;

    return ele;
}

// 点到会消失
bool UI_PanelEle_Click(UI_PanelEle* ele, Vector2 mousePos, bool isMouseDown) {
    return GUIButton_IsMouseClick(&ele->btn, mousePos, isMouseDown);
}

bool UI_PanelEle_IsMouseInside(UI_PanelEle* ele, Vector2 mouseWorldPos) {

    ele->isClick = IsRectInsideMouse(Vector2_New(ele->btn.rect.x, ele->btn.rect.y), ele->btn.rect.width,
                                     ele->btn.rect.height, mouseWorldPos);
    return ele->isClick;
}

void UI_panelEle_Draw(UI_PanelEle* ele) {

    Rectangle source = {0.0f, 0.0f, (float)ele->tex.width, (float)ele->tex.height};
    // 开始画的位置
    int rotation = 0;

    Rectangle dest = {ele->btn.rect.x, ele->btn.rect.y, ele->btn.rect.width, ele->btn.rect.height};
    Vector2 pivot = {ele->btn.rect.width / 2, ele->btn.rect.height / 2};
    DrawTexturePro(ele->tex, source, dest, pivot, rotation, WHITE);
}

// panel
typedef struct UI_panel {
    Vector2 startPos;
    float gapY;
    int eleSize;
    UI_PanelEle elements[3];
    int eleCount;
    bool isOpen;
    bool isInside;
} UI_panel;

void UI_Panel_AddElement(UI_panel* panel, Vector2 worldPos, int typeID,Texture2D red,Texture2D pink,Texture2D purple) {
    panel->startPos = worldPos;
    int count = panel->eleCount;
    Vector2 pos = Vector2Add(worldPos, Vector2_New(0, panel->gapY * count + panel->eleSize * count));
    UI_PanelEle ele = UI_PanelEle_CraeteTowerType(count, typeID, pos, Vector2_New(panel->eleSize, panel->eleSize),red, pink, purple);
    panel->elements[count] = ele;
    panel->eleCount++;
}

int UI_Panel_Click(UI_panel* panel, Vector2 mouseWorldPos, bool isMouseDown) {

    for (int i = 0; i < panel->eleCount; i++) {
        UI_PanelEle* ele = &panel->elements[i];
        // 点到
        if (UI_PanelEle_Click(ele, mouseWorldPos, isMouseDown)) {
            return ele->typeID; // 返回点击的是哪一个
        }
    }
    return -1;
}

// 所以都关闭
void UI_Panel_Close(UI_panel* panel) {
    panel->eleCount = 0;
    panel->isOpen = false;
}

// 画
void UI_Panel_Draw(UI_panel* panel, bool isMouseDown) {

    if (!panel->isOpen) {
        return;
    }

    for (int i = 0; i < panel->eleCount; i++) {
        UI_PanelEle* ele = &panel->elements[i];
        UI_panelEle_Draw(ele);
    }
}

#endif