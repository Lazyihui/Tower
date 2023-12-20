#ifndef E_CAMERA_H__
#define E_CAMERA_H__
#include "../include/raylib.h"
#include "A_Common.h"


typedef struct E_Camera {
    Camera2D camera;

} E_Camera;

void CameraEntity_SetOffset(E_Camera* cam, Vector2 offSet);

void CameraEntity_Init(E_Camera* cam) {
    *cam =(E_Camera) {0};
    cam->camera.zoom = 1;
    CameraEntity_SetOffset(cam, Vector2_New(400, 200));
}

// 跟随
void CameraEntity_Follow(E_Camera* camera, Vector2 targetPos) {
    camera->camera.target = targetPos;
}

void CameraEntity_SetOffset(E_Camera* cam, Vector2 offSet) {
    cam->camera.offset = offSet;
}



#endif