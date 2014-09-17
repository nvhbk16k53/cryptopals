#include <stdlib.h>
#include <stdio.h>
#include "dict.h"
#include "assert.h"

#define DICT_FILE "dict.txt"

void test_dict()
{
	FILE *fp;
	char str[100];

	assert(Dict_load(DICT_FILE));

	fp = fopen(DICT_FILE, "r");
	assert(fp);

	while (fgets(str, sizeof(str), fp) != NULL)
		assert(Dict_validate_word(str));

	assert(Dict_validate_word("invalid_word") == 0);
}

int main(int argc, char **argv)
{
	test_dict();

	return 0;
}
