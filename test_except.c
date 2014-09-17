#include "assert.h"
#include "except.h"

struct Except_T exception = {"Exception"}, e = {"exception"};

void test_raise()
{
	TRY
		RAISE(exception);
	EXCEPT(exception)
		assert(1);
	ELSE
		assert(0);
	END_TRY;
}

void test_else()
{
	TRY
		RAISE(exception);
	EXCEPT(e)
		assert(0);
	ELSE
		assert(1);
	END_TRY;
}

void test_multi_exception()
{
	TRY
		RAISE(exception);
	EXCEPT(e)
		assert(0);
	EXCEPT(exception)
		assert(1);
	ELSE
		assert(0);
	END_TRY;
}

void test_assert()
{
	TRY
		assert(0);
	EXCEPT(Assert_Failed)
		assert(1);
	ELSE
		assert(0);
	END_TRY;
}

int main(int argc, char **argv)
{
	test_raise();
	test_else();
	test_multi_exception();
	test_assert();

	return 0;
}
