#ifndef __UTILS_H
#define __UTILS_H

char *hex_encode(unsigned char *bytes);
unsigned char *hex_decode(char *hex_str);
char *base64_encode(unsigned char *bytes);
unsigned char *base64_decode(char *b64_str);

#endif
