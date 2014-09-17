#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dict.h"
#include "atom.h"
#include "assert.h"

int Dict_load(const char *file)
{
	FILE *fp;
	char str[100];

	assert(file);
	fp = fopen(file, "r");
	if (fp == NULL)
		return 0;

	while(fgets(str, sizeof(str), fp) != NULL)
		Atom_string(str);

	return 1;
}

int Dict_validate_word(const char *word)
{
	if (word == NULL)
		return 0;

	return Atom_contain(word, strlen(word));
}
