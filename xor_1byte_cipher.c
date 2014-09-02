#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "utils.h"

char find_key(char *ct);
char *decrypt(char k, char *ct);
char *cipher_only_attack(char *hex);

int main(int argc, char **argv)
{
	if (argc != 2) {
		fprintf(stderr, "usage: %s <hex cipher string>\n", argv[0]);
		exit(1);
	}

	printf("message: %s\n", cipher_only_attack(argv[1]));

	exit(0);
}

char find_key(char *ct)
{
	int i, freq[128] = {0}, max = 0;
	char k;

	for (i = 0; i < strlen(ct); i++)
		freq[ct[i]]++;

	for (i = 0; i < 128; i++)
		if (freq[i] > max) {
			max = freq[i];
			k = i;
		}

	return k ^ ' ';
}

char *decrypt(char k, char *ct)
{
	int len, i;
	char *pt;

	len = strlen(ct);
	pt = malloc(len + 1);

	for (i = 0; i < len; i++)
		pt[i] = k ^ ct[i];
	pt[i] = '\0';

	return pt;
}

char *cipher_only_attack(char *hex)
{
	int i, len;
	char *ct, k;

	len = strlen(hex);
	ct = malloc(len / 2 + 1);
	for (i = 0; i < len; i += 2)
		ct[i / 2] = hex_decode(hex[i]) << 4 | hex_decode(hex[i + 1]);
	ct[i / 2] = '\0';

	printf("%d\n", (int)strlen(ct));
	k = find_key(ct);
	return decrypt(k, ct);
}
