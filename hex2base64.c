#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int main(int argc, char **argv)
{
	if (argc != 2) {
		fprintf(stderr, "usage: %s <hex string>\n", argv[0]);
		exit(1);
	}

	printf("%s\n", hex2base64(argv[1]));

	exit(0);
}
