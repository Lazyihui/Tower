#ifndef UTIL_TEMPLATE_H__
#define UTIL_TEMPLATE_H__

#include "E_Mst.h"
#include "A_Ctx.h"

TM_Mst* TM_Mst_Find(Ctx *ctx, int typeID) {
    TM_Mst* tm = NULL;
    for (int i = 0; i < ctx->mst_templateCount; i++) {
        TM_Mst* cur = &ctx->mst_template[i];
        printf("%D",cur->typeID);
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