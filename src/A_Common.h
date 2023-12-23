#ifndef COMMMON_H__
#define COMMMON_H__
#include <stdio.h>
#include "../include/raylib.h"
#include "../include/raymath.h"

enum GAME_STATUS {
    GAME_STATUS_LOGIN, GAME_STATUS_GAME, GAME_STATUS_OVER
};
const int cellsize = 70;

Vector2 Vector2_New(float x, float y) {
    Vector2 a;
    a.x = x;
    a.y = y;
    return a;
}

bool IsRectInsideMouse(Vector2 rectPos, int width, int height, Vector2 mousePos) {
    if (mousePos.x >= rectPos.x && mousePos.x <= rectPos.x + width && mousePos.y >= rectPos.y &&
        mousePos.y <= rectPos.y + height) {
        return true;
    } else {

        return false;
    }
}

// 矩形和鼠标的交叉检测
bool IsRectInsideMouseRec(Rectangle rect, Vector2 mousePos) {
    if (mousePos.x >= rect.x && mousePos.x <= rect.x + rect.width && mousePos.y >= rect.y &&
        mousePos.y <= rect.y + rect.height) {
        return true;
    } else {
        return false;
    }
}

//圆和圆的交叉检测
bool IsCirlceInsideCircle(float hookr, float rockr, Vector2 hooky, Vector2 rocky) {
    Vector2 diff = Vector2Subtract(hooky, rocky);
    float lengthsqr = Vector2LengthSqr(diff);
    if (lengthsqr >= (hookr + rockr) * (hookr + rockr)) {
        return false;
    } else {
        return true;
    }
}

void Text_Int(int b, int x, int y, int size, Color color) {
    const char* a = TextFormat("%d", b);
    DrawText(a, x, y, size, color);
}


const char* Vector2Text(Vector2 pos) {
    return TextFormat("x=%f y=%f\r\n", pos.x, pos.y);
}

const char* ColorText(Color color) {
    return TextFormat("r=%d g=%d b=%d a=%d\r\n", color.r, color.g, color.b, color.a);
}

#endif