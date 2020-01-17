
#include <Windows.h>

#include "arc4.h"


int
arc4_ctxlen()
{
        return sizeof(struct arc4_ctx);
}

void
arc4_setkey(void *ctxp, const unsigned char *key, unsigned int keylen)
{
        struct arc4_ctx *ctx = (struct arc4_ctx *)ctxp;
        unsigned int i, t, u, ki, si;
        unsigned int *state;

        state = ctx->state;
        ctx->x = 0;
        ctx->y = 0;
        for (i = 0; i < 256; i++)
               state[i] = i;
        ki = si = 0;
        for (i = 0; i < 256; i++) {
                t = state[i];
                si = (si + key[ki] + t) & 0xff;
                u = state[si];
                state[si] = t;
                state[i] = u;
                if (++ki >= keylen)
                        ki = 0;
        }
}

void
arc4_encrypt(void *ctxp, unsigned char *dst, const unsigned char *src, int len)
{
        struct arc4_ctx *ctx = (struct arc4_ctx *)ctxp;
        unsigned int x, y, sx, sy;
        unsigned int *state;
        const unsigned char *endsrc;

        state = ctx->state;
        x = ctx->x;
        y = ctx->y;
        for (endsrc = src + len; src != endsrc; src++, dst++) {
                x = (x + 1) & 0xff;
                sx = state[x];
                y = (sx + y) & 0xff;
                state[x] = sy = state[y];
                state[y] = sx;
                *dst = *src ^ state[(sx + sy) & 0xff];
        }
        ctx->x = x;
        ctx->y = y;
}

void
arc4_decrypt(void *ctxp, unsigned char *dst, const unsigned char *src, int len)
{
        arc4_encrypt(ctxp, dst, src, len);
}