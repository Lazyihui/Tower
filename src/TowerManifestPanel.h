#ifndef TOWERMANIFEST_H__
#define TOWERMANIFEST_H__

#include "GUI_Button.h"
#include "../include/raylib.h"

// typedef struct GUIButton {
//     Rectangle rect;
//     Color bgHoverColor;
//     Color bgColor;
//     bool isInside;

//     const char* text;
//     Color textColor;
// } GUIButton;
/////UI要创建一块东西先确定一块面板 然后再创建面板里面的东西 由小到大 任何行为写面板里面的东西在看面板
// ==== Element 子元素 ====
typedef struct PanelTowerManifestElement {
    int index;
    int typeID;
    GUIButton btn;
} PanelTowerManifestElement;

// ceate 初始化
PanelTowerManifestElement TowerManifestElement_Create(int index, int typeID, Vector2 pos, Vector2 size) {
    PanelTowerManifestElement ele = (PanelTowerManifestElement){0};
    ele.index = index;
    ele.typeID = typeID;
    Color color;
    switch (typeID) {
    case 1: color = RED; break;
    case 2: color = YELLOW; break;
    case 3: color = GREEN; break;
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

// 元素是否被点击
bool TowerManifestElement_IsClick(PanelTowerManifestElement* ele, Vector2 mousePos, bool isMouseDown) {
    return GUIButton_IsMouseClick(&ele->btn, mousePos, isMouseDown);
}

// 画一个元素
void TowerManifestElement_Draw(PanelTowerManifestElement* ele) {
    GUIButton_Draw(&ele->btn);
}

// ==== Panel 面板 ====
typedef struct PanelTowerManifest {
    Vector2 startPos;
    float gapY;
    int eleSize;
    PanelTowerManifestElement elements[3]; // 3
    int eleCount;                          // 0
    bool isOpen;
} PanelTowerManifest;

// 增加元素 然后是我一定会把for写在这里   以后记得可以写在外面！！
void TowerManifest_AddElement(PanelTowerManifest* panel, Vector2 worldPos, int typeID) {
    panel->startPos = worldPos;
    int count = panel->eleCount;
    Vector2 pos = Vector2Add(worldPos, Vector2_New(0, panel->gapY * count + panel->eleSize * count));
    PanelTowerManifestElement ele =
        TowerManifestElement_Create(count, typeID, pos, Vector2_New(panel->eleSize, panel->eleSize));
    panel->elements[count] = ele;
    panel->eleCount++;
}

// 在面板里是否点击  这样分开写更清楚还可以得到他的ID
int TowerManifest_Click(PanelTowerManifest* panel, Vector2 mousePos, bool isMouseDown) {
    for (int i = 0; i < panel->eleCount; i++) {
        PanelTowerManifestElement* ele = &panel->elements[i];
        if (TowerManifestElement_IsClick(ele, mousePos, isMouseDown)) {
            return ele->typeID;
        }
    }
    return -1;
}

// 写一个元素和面板不存在的函数
void TowerManifest_Close(PanelTowerManifest* panel) {
    panel->eleCount = 0;
    panel->isOpen = false;
}

// 画一个面板  和元素
void TowerManifest_Draw(PanelTowerManifest* panel) {
    if (!panel->isOpen) {
        return;
    }
    int width = panel->eleSize + 4;
    int height = panel->eleCount * panel->eleSize + panel->gapY * (panel->eleCount - 1) + 4;
    DrawRectangleLines(panel->startPos.x - 2, panel->startPos.y + 2, width, height, BLACK);

    // 画三个元素
    for (int i = 0; i < panel->eleCount; i += 1) {
        PanelTowerManifestElement* ele = &panel->elements[i];
        TowerManifestElement_Draw(ele);
    }
}
// 总结 好像就是把所有东西都写成函数
#endif