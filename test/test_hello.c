#include <stdio.h>
#include <string.h>
#include "../src/hello.h"

static int tests_run = 0;
static int tests_failed = 0;

static void assert_str_eq(const char* expected, const char* actual, const char* name) {
    tests_run++;
    if (strcmp(expected, actual) != 0) {
        tests_failed++;
        fprintf(stderr, "[FAIL] %s: expected=\"%s\" actual=\"%s\"\n", name, expected, actual);
    } else {
        fprintf(stdout, "[PASS] %s\n", name);
    }
}

int main(void) {
    assert_str_eq("Hello, World!", hello_message(), "hello_message returns greeting");

    if (tests_failed) {
        fprintf(stderr, "\n%d/%d tests failed.\n", tests_failed, tests_run);
        return 1;
    }
    fprintf(stdout, "\nAll %d tests passed.\n", tests_run);
    return 0;
}
