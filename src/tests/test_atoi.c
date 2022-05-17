#include "../tests_includes/s21_tests.h"

START_TEST(atoi_test1) {
    char src[] = "  +123123123";
    ck_assert_int_eq(atoi(src),
                     s21_atoi(src));
} END_TEST

Suite *suite_atoi(void) {
    Suite *s = suite_create("suite_atoi");
    TCase *tc = tcase_create("atoi_tc");

    tcase_add_test(tc, atoi_test1);

    suite_add_tcase(s, tc);
    return s;
}
