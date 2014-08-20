#include <stdlib.h>
#include <assert.h>
#include <string.h>
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
		return -1;
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
		return -1;
}
