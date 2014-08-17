#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "utils.h"

char _hex(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else
		return -1;
}

char *hex_encode(unsigned char *bytes)
{
}

unsigned char *hex_decode(char *hex_str)
{
	int i, j, len;
	unsigned char *res;

	len = strlen(hex_str);
	res = (unsigned char )malloc((len + 1) / 2);

	for (i = 0, j = 0; i < len; i++) {
		char tmp;
		tmp = _hex(hex_str[i]);
		if (tmp < 0)
			return NULL;
		if (i % 2 == 1) {
			res[j] = (res[j] << 4) | tmp;
			j++;
		} else {
			res[j] = tmp;
		}
	}

	return res;
}

char *base64_encode(unsigned char *bytes)
{
	int i, j;
	char *res;
}

unsigned char *base64_decode(char *b64_str)
{
}
