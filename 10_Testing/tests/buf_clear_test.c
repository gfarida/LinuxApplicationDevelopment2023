#include "test.h"

int main(int argc, char **argv) {
    float *a = 0;
    int count_pass = 0;
    int count_fail = 0;

    buf_clear(a);
    TEST("clear empty", buf_size(a) == 0);
    TEST("clear no-op", a == 0);
}