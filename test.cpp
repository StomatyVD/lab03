#include "histogram.h"
#include <cassert>
void
test_positive() {
double a = 5;
double b = 5;
find_minmax({}, a, b);
assert(a = 5);
assert(b = 5);
}
int
main() {
test_positive();
}
