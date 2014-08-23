#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>
#include "utils.h"

char hex_decode(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else
		assert(0);
}

char hex_encode(unsigned char byte)
{
	byte &= 0x0F;

	return (byte < 10) ? ('0' + byte) : ('A' + byte - 10);
}

char base64_encode(unsigned char byte)
{
	byte &= 0x3F;
	if (byte < 26)
		return byte + 'A';
	else if (byte < 52)
		return byte - 26 + 'a';
	else if (byte < 62)
		return byte - 52 + '0';
	else if (byte == 62)
		return '+';
	else
		return '/';
}

char base64_decode(char c)
{
	if (c >= 'A' && c <= 'Z')
		return c - 'A';
	else if (c >= 'a' && c <= 'z')
		return c - 'a' + 26;
	else if (c >= '0' && c <= '9')
		return c - '0' + 52;
	else if (c == '+')
		return 62;
	else if (c == '/')
		return 63;
	else
		assert(0);
}

char *XOR(char *hex1, char *hex2)
{
	int i, len;
	char *res;

	if ((len = strlen(hex1)) != strlen(hex2))
		return NULL;
	
	res = malloc(len + 1);

	for (i = 0; i < len; i++) {
		uint8_t tmp = 0;
		tmp = hex_decode(hex1[i]) ^ hex_decode(hex2[i]);
		res[i] = hex_encode(tmp);
	}
	res[i] = '\0';

	return res;
}

char *hex2base64(char *hex)
{
	int tmp_len, hex_len, b64_len, i, j;
	char *b64;
	uint8_t *tmp;

	hex_len = strlen(hex);
	tmp_len = (hex_len + 1) / 2;
	switch (tmp_len % 3) {
	case 1:
		tmp_len += 2;
		break;
	case 2:
		tmp_len += 1;
		break;
	}
	b64_len = tmp_len / 3 * 4;

	tmp = malloc(tmp_len);
	b64 = malloc(b64_len);

	/* Decode hex string */
	for (i = hex_len/2; i < tmp_len; i++)
		tmp[i] = 0;
	for (i = 0; i < hex_len / 2; i++)
		tmp[i] = hex_decode(hex[i * 2]) << 4 | hex_decode(hex[i * 2 + 1]);
	if (hex_len % 2 != 0)
		tmp[i] = hex_decode(hex[i * 2]) << 4;

	/* Encode base64 */
	for (i = 0, j = 0; i < tmp_len; i += 3) {
		b64[j] = base64_encode(tmp[i] >> 2);
		b64[j + 1] = base64_encode(tmp[i] << 4 | tmp[i + 1] >> 4);
		b64[j + 2] = base64_encode(tmp[i + 1] << 2 | tmp[i + 2] >> 6);
		b64[j + 3] = base64_encode(tmp[i + 2]);
		j += 4;
	}
	b64[j] = '\0';
	free(tmp);

	return b64;
}
