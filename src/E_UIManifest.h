#ifndef UIMANIDEST_H__
#define UIMANIDEST_H__

#include "GUI_Button.h"
#include "E_Cell.h"
#include "../include/raylib.h"
#include "../include/raymath.h"

// 元素
typedef struct UIManifest {
    int typeID;
    int index;
    float speed;
    float hurt;
    bool isClick;
    GUIButton btn;
} UIManifest;

// 换一种写法
//  void UIManifest_CreatTower(UIManifest *UITower,){

// }
// element
UIManifest UIManifest_CraeteTower(int index, int typeID, Vector2 pos, Vector2 size) {
    UIManifest ele = (UIManifest){0};
    ele.index = index;
    ele.typeID = typeID;
    Color color;
    switch (typeID) {
    case 1:
        color = RED;
        ele.speed = 10;
        ele.hurt = 1;
        break;
    case 2:
        color = PINK;
        ele.hurt = 2;
        ele.speed = 20;
        break;
    case 3:
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
bool UIManifest_ElementClick(UIManifest* ele, Vector2 mousePos, bool isMouseDown) {

    return GUIButton_IsMouseClick(&ele->btn, mousePos, isMouseDown);
}

bool UIManifestEle_IsMouseInside(UIManifest* ele, Vector2 mouseWorldPos) {

    ele->isClick = IsRectInsideMouse(Vector2_New(ele->btn.rect.x, ele->btn.rect.y), ele->btn.rect.width,
                                     ele->btn.rect.height, mouseWorldPos);
    return ele->isClick;
}

void UIManifest_Draw(UIManifest* ele) {
    DrawRectangle(ele->btn.rect.x, ele->btn.rect.y, ele->btn.rect.width, ele->btn.rect.height, ele->btn.bgColor);
}

// panel
typedef struct UIManifestPanel {
    Vector2 startPos;
    float gapY;
    int eleSize;
    UIManifest elements[3];
    int eleCount;
    bool isOpen;
    bool isInside;
} UIManifestPanel;

void UIManifestPanel_AddElement(UIManifestPanel* panel, Vector2 worldPos, int typeID) {
    panel->startPos = worldPos;
    int count = panel->eleCount;
    Vector2 pos = Vector2Add(worldPos, Vector2_New(0, panel->gapY * count + panel->eleSize * count));
    UIManifest ele = UIManifest_CraeteTower(count, typeID, pos, Vector2_New(panel->eleSize, panel->eleSize));
    panel->elements[count] = ele;
    panel->eleCount++;
}

int UIManifestPanel_Click(UIManifestPanel* panel, Vector2 mouseWorldPos, bool isMouseDown) {

    for (int i = 0; i < panel->eleCount; i++) {
        UIManifest* ele = &panel->elements[i];
        // 点到
        if (UIManifest_ElementClick(ele, mouseWorldPos, isMouseDown)) {
            printf("%d", ele->typeID);
            return ele->typeID; // 返回点击的是哪一个
        }
    }
    return -1;
}

// 所以都关闭
void UIManifest_Close(UIManifestPanel* panel) {
    panel->eleCount = 0;
    panel->isOpen = false;
}

// 画
void UIManifestPanel_Draw(UIManifestPanel* panel,bool isMouseDown) {

    if (!panel->isOpen) {
        return;
    }

     

    for (int i = 0; i < panel->eleCount; i++) {
        UIManifest* ele = &panel->elements[i];
        UIManifest_Draw(ele);
    }
}

#endif