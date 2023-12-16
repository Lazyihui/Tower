#ifndef COMMMON_H__
#define COMMMON_H__
#include <stdio.h>
#include "../include/raylib.h"
#include "../include/raymath.h"

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

void Text_Int(int b, int x, int y, int size, Color color) {
    const char* a = TextFormat("%d", b);
    DrawText(a, x, y, size, color);
}


#endif