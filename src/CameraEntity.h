#ifndef CAMERAENTITY_H__
#define CAMERAENTITY_H__
#include "../include/raylib.h"
#include "Common.h"


typedef struct CameraEntity {
    Camera2D camera;

} CameraEntity;

void CameraEntity_SetOffset(CameraEntity* cam, Vector2 offSet);

void CameraEntity_Init(CameraEntity* cam) {
    *cam =(CameraEntity) {0};
    cam->camera.zoom = 1;
    CameraEntity_SetOffset(cam, Vector2_New(400, 200));
}

// 跟随
void CameraEntity_Follow(CameraEntity* camera, Vector2 targetPos) {
    camera->camera.target = targetPos;
}

void CameraEntity_SetOffset(CameraEntity* cam, Vector2 offSet) {
    cam->camera.offset = offSet;
}



#endif