#include "histogram.h"
#include <cassert>
void
test_positive() {
double min_ = 5;
double max_ = 5;
find_minmax({}, min_, max_);
assert(min_ = 5);
assert(max_ = 5);
double min_1 = 0;
double max_1 = 0;
find_minmax({1,2,3}, min_1, max_1);
assert(min_1 = 1);
assert(max_1 = 3);
double min_2 = 0;
double max_2 = 0;
find_minmax({1},min_2,max_2);
assert(min_2 = 1);
assert(max_2 = 1);

}
int
main() {
test_positive();
}
