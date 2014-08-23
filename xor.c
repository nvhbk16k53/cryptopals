#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int main(int argc, char **argv)
{
	char *res;

	if (argc != 3) {
		fprintf(stderr, "usage: %s <hex string 1> <hex string 2>", argv[0]);
		exit(1);
	}

	res = XOR(argv[1], argv[2]);
	if (res == NULL) {
		printf("To buffer string not equal\n");
		exit(1);
	}
	printf("%s\n", res);

	exit(0);
}
