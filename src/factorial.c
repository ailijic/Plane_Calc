#include "factorial.h"

int fact(int n) {
	if (n == 0) {
		return 1;
	}
  return (n <= 1) ? n : fact(n - 1) * n;
}