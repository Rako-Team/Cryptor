#ifndef _CRYPTO_ARC4_H_
#define _CRYPTO_ARC4_H_

struct arc4_ctx {
         unsigned int    x;
         unsigned int    y;
         unsigned int    state[256];
         /* was unsigned char, changed to int for performance -- onoe */
 };

int arc4_ctxlen();
void arc4_setkey(void *ctxp, const unsigned char *key, unsigned int keylen);
void arc4_encrypt(void *ctxp, unsigned char *dst, const unsigned char *src, int len);
void arc4_decrypt(void *ctxp, unsigned char *dst, const unsigned char *src, int len);

#endif /* _CRYPTO_ARC4_H_ */
