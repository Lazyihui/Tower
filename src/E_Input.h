#ifndef E_INPUT_H__
#define E_INPUT_H__
#include "../include/raylib.h"
#include "../include/raymath.h"

typedef struct E_Input {
    Vector2 mousePos; // mouse screen pos
    Vector2 mouseWorldPos;
    bool isMouseDown;
} E_Input;

void E_Input_Process(E_Input* input, Vector2 cameraOffset) {
    input->isMouseDown = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
    input->mousePos = GetMousePosition();
    input->mouseWorldPos = Vector2Subtract(input->mousePos, cameraOffset);
}


#endif