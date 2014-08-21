#ifndef __UTILS_H
#define __UTILS_H

/* Hex Encoder
 * 
 * Return a hex digit character from a hex value */
char hex_encode(unsigned char byte);

/* Hex Decoder
 *
 * Return a hex value from a hex digit character */
char hex_decode(char c);

/* Base64 Encoder
 *
 * Return a encoded base64 character from a 6-bit value */
char base64_encode(unsigned char byte);

/* Base64 Decoder
 *
 * Return a decoded value from a base64 character */
char base64_decode(char c);

#endif
