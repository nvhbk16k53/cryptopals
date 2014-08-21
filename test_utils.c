#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "utils.h"

void test_hex_encode(void);
void test_hex_decode(void);
void test_base64_encode(void);
void test_base64_decode(void);

int main(void)
{
	test_hex_encode();
	test_hex_decode();
	test_base64_encode();
	test_base64_decode();

	return 0;
}

void test_hex_encode(void)
{
	int i;

	for (i = 0; i < 10; i++)
		assert(hex_encode(i) == i + '0');

	for (i = 0; i < 6; i++)
		assert(hex_encode(i + 10) == i + 'A');
}

void test_hex_decode(void)
{
	int i;

	for (i = 0; i < 10; i++)
		assert(hex_decode(i + '0') == i);

	for (i = 0; i < 6; i++) {
		assert(hex_decode(i + 'A') == i + 10);
		assert(hex_decode(i + 'a') == i + 10);
	}
}

void test_base64_encode(void)
{
	int i;

	for (i = 0; i < 26; i++) {
		assert(base64_encode(i) == 'A' + i);
		assert(base64_encode(i + 26) == 'a' + i);
	}

	for (i = 0; i < 10; i++)
		assert(base64_encode(i + 52) == '0' + i);

	assert(base64_encode(62) == '+');
	assert(base64_encode(63) == '/');
}

void test_base64_decode(void)
{
	int i;

	for (i = 0; i < 26; i++) {
		assert(base64_decode(i + 'A') == i);
		assert(base64_decode(i + 'a') == i + 26);
	}

	for (i = 0; i < 10; i++)
		assert(base64_decode(i + '0') == i + 52);

	assert(base64_decode('+') == 62);
	assert(base64_decode('/') == 63);
}
