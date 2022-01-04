#include "hello.h"
#include "catch2/catch.hpp"

#include <stdio.h>

TEST_CASE( "Check hello return value", "[hello]" ) {
	int hello_ret = hello();
	REQUIRE( hello_ret >= 0 );
	REQUIRE( hello_ret != EOF );
}