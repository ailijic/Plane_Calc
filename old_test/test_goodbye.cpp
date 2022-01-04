#include "goodbye.hpp"
#include "catch2/catch.hpp"

#include <stdio.h>

TEST_CASE( "Check goodbye return value", "[goodbye]" ) {
	int goodbye_ret = goodbye();
	REQUIRE( goodbye_ret >= 0 );
	REQUIRE( goodbye_ret != EOF );
}