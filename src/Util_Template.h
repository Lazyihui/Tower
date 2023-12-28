#ifndef UTIL_TEMPLATE_H__
#define UTIL_TEMPLATE_H__

#include "E_Tower.h"
#include "E_Mst.h"
#include "A_Ctx.h"

TM_Tower* TM_Tower_Find(Ctx* ctx, int typeID) {
    TM_Tower* tm = NULL;
    for (int i = 0; i < ctx->tower_templateCount; i++) {
        TM_Tower* cur = &ctx->tower_template[i];
        if (cur->typeID == typeID) {
            tm = cur;
            break;
        }
    }
    if (tm == NULL) {
        const char* txt = TextFormat("nofoundtower TM %d", typeID);
        perror(txt);
    }
}

TM_Mst* TM_Mst_Find(Ctx* ctx, int typeID) {
    TM_Mst* tm = NULL;
    for (int i = 0; i < ctx->mst_templateCount; i++) {
        TM_Mst* cur = &ctx->mst_template[i];
        if (cur->typeID == typeID) {
            tm = cur;
            break;
        }
    }
    if (tm == NULL) {
        const char* txt = TextFormat("nofound TM %d", typeID);
        perror(txt);
    }
    return tm;
}

#endif