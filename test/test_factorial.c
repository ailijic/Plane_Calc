#include "factorial.h"
#include "unity.c"

void test_factorial(void) {
	int res;
	res = fact(0);
	TEST_ASSERT(res == 1);
}