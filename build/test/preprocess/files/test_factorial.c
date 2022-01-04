#include "/var/lib/gems/2.7.0/gems/ceedling-0.31.1/vendor/unity/src/unity.c"
#include "src/factorial.h"


void test_factorial(void) {

 int res;

 res = fact(0);

 do {if ((res == 1)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(7)));}} while(0);

}
