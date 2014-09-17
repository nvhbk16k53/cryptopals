#include <string.h>
#include "assert.h"
#include "atom.h"

void test_atom_new()
{
	const char *str, *str2;

	str = Atom_new("test atom", strlen("test atom"));
	assert(strcmp(str, "test atom") == 0);

	str2 = Atom_new("test atom", strlen("test atom"));
	assert(str == str2);
}

void test_atom_int()
{
	const char *str1, *str2;

	str1 = Atom_int(1990);
	assert(strcmp(str1, "1990") == 0);

	str2 = Atom_int(1990);
	assert(str1 == str2);
}

void test_atom_string()
{
	const char *str1, *str2;

	str1 = Atom_string("test atom string");
	assert(strcmp(str1, "test atom string") == 0);

	str2 = Atom_string("test atom string");
	assert(str1 == str2);
}

void test_atom_length()
{
	int len;
	const char *ptr;

	ptr = Atom_string("test atom length");
	len = Atom_length(ptr);
	assert(len == strlen(ptr));

	TRY
		len = Atom_length("nonexist atom length");
	EXCEPT(Assert_Failed)
		assert(1);
	ELSE
		assert(0);
	END_TRY;
}

void test_atom_contain()
{
	const char *ptr;

	assert(Atom_contain("nonexist atom", strlen("nonexist atom")) == 0);
	ptr = Atom_string("test atom contain");
	assert(Atom_contain("test atom contain", strlen(ptr)));
}

int main(int argc, char **argv)
{
	test_atom_new();
	test_atom_int();
	test_atom_string();
	test_atom_length();
	test_atom_contain();

	return 0;
}
