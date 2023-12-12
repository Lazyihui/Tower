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

bool IsCirlceInsideMouse(Vector2 dipos, float diradius, Vector2 mouse) {
    int a = diradius * diradius;
    int b = (mouse.x - dipos.x) * (mouse.x - dipos.x) + (mouse.y - dipos.y) * (mouse.y - dipos.y);
    if (b >= a) {
        return false;
    } else {
        return true;
    }
}

bool IsRectInsideMouse(Vector2 rectPos, int width, int height, Vector2 mousePos) {
    if (mousePos.x > rectPos.x && mousePos.x < rectPos.x + width && mousePos.y > rectPos.y &&
        mousePos.y < rectPos.y + height) {
        return true;
    } else {
        return false;
    }
}

#endif