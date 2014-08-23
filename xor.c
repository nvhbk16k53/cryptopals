#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "utils.h"

char *xor(char *hex1, char *hex2);

int main(int argc, char **argv)
{
	char *res;

	if (argc != 3) {
		fprintf(stderr, "usage: %s <hex string 1> <hex string 2>", argv[0]);
		exit(1);
	}

	res = xor(argv[1], argv[2]);
	if (res == NULL) {
		printf("To buffer string not equal\n");
		exit(1);
	}
	printf("%s\n", res);

	exit(0);
}

char *xor(char *hex1, char *hex2)
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

	return res;
}
