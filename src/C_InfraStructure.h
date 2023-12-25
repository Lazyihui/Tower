#ifndef C_INFRASTRUCTURE_H__
#define C_INFRASTRUCTURE_H__

#include <stdio.h>
#include "../include/raylib.h"
#include "../include/raymath.h"
#include "Util_Template.h"
#include "E_Mst.h"
#include "E_Tower.h"
#include "A_Ctx.h"

// infrastructure 基础建设

void C_InfraStructure_MstInit(Ctx* ctx) {

    ctx->mst_templateLen = 100;
    ctx->mst_template = (TM_Mst*)malloc(sizeof(TM_Mst) * ctx->mst_templateLen);
    // ==== Template ====
    TM_Mst* template = ctx->mst_template;
    TM_Mst mst_small;
    mst_small.typeID = 1;
    mst_small.speed = 20;
    mst_small.radius = 10;
    mst_small.color = WHITE;
    mst_small.hp = 1;
    template[0] = mst_small;

    TM_Mst mst_mid;
    mst_mid.typeID = 2;
    mst_mid.speed = 30;
    mst_mid.radius = 20;
    mst_mid.color = GRAY;
    mst_mid.hp = 2;
    template[1] = mst_mid;
    ctx->mst_templateCount = 2;
    ctx->mst_spawnPos = Vector2_New(0, 210);
    // ==================
}

void C_InfraStructure_TowerInit(Ctx* ctx) {
    ctx->tower_templateCount = 3;
    ctx->tower_template = (TM_Tower*)malloc(sizeof(TM_Mst) * ctx->tower_templateCount);

    TM_Tower* template = ctx->tower_template;
    TM_Tower first;
    first.color = RED;
    first.hurt = 1;
    first.typeID = 1;
    template[0] = first;


    TM_Tower second ;
    second.color=PINK;
    second.hurt=2;
    second.typeID=2;
    template[1]=second;

    TM_Tower third;
    third.color=PURPLE;
    third.hurt=3;
    third.typeID=3;
    template[2]=third;
}

#endif