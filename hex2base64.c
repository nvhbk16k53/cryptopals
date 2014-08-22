#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "utils.h"

char *hex2base64(char *hex);

int main(int argc, char **argv)
{
	if (argc != 2) {
		fprintf(stderr, "usage: %s <hex string>\n", argv[0]);
		exit(1);
	}

	printf("%s\n", hex2base64(argv[1]));

	exit(0);
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
