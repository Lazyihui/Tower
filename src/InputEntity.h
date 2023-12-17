#ifndef INPUTENTITY_H__
#define INPUTENTITY_H__
#include "../include/raylib.h"
#include "../include/raymath.h"

typedef struct InputEntity {
    Vector2 mousePos; // mouse screen pos
    Vector2 mouseWorldPos;
    bool isMouseDown;
} InputEntity;

void Input_Process(InputEntity* input, Vector2 cameraOffset) {
    input->isMouseDown = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
    input->mousePos = GetMousePosition();
    input->mouseWorldPos = Vector2Subtract(input->mousePos, cameraOffset);
}

// void Input_Process(InputEntity *input,Vector2 planePos) {
//     input->moveAxis.x = IsKeyDown(KEY_D) - IsKeyDown(KEY_A);
//     input->moveAxis.y = IsKeyDown(KEY_S) - IsKeyDown(KEY_W);
//     input->mousepos = GetMousePosition();
//     input->isMouseDown = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
//     input->mouseFaceDir = Vector2Subtract(input->mousepos, planePos);
//     input->mouseFaceDir = Vector2Normalize(input->mouseFaceDir);
// }

#endif