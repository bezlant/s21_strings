#include "tests_includes/s21_tests.h"

int main(void) {
    run_tests();

    return 0;
}

void run_testcase(Suite *testcase) {
    setlocale(LC_ALL, "");
    static int counter_testcase = 1;

    if (counter_testcase > 1)
        putchar('\n');
    printf("%s%d%s", "CURRENT TEST: ", counter_testcase, "\n");
    counter_testcase++;

    SRunner *sr = srunner_create(testcase);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    srunner_free(sr);
}

void run_tests(void) {
    Suite *list_cases[] = {
        suite_memchr(),   suite_memcmp(),   suite_memcpy(),
        suite_memmove(),  suite_memset(),   suite_strcat(),
        suite_strncat(),  suite_strchr(),   suite_strcmp(),
        suite_strncmp(),  suite_strcpy(),   suite_strncpy(),
        suite_strcspn(),  suite_strerror(), suite_strlen(),
        suite_strpbrk(),  suite_strrchr(),  suite_strspn(),
        suite_strstr(),   suite_insert(),   suite_to_lower(),
        suite_to_upper(), suite_trim(),     suite_strtok(),
        suite_sprintf(),  suite_atoi(),     suite_strntollu(),
        suite_strtold(),  suite_sscanf(),   NULL};

    for (Suite **current_testcase = list_cases; *current_testcase != NULL;
         current_testcase++) {
        run_testcase(*current_testcase);
    }
}
