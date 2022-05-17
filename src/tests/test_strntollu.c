#include "../tests_includes/s21_tests.h"

START_TEST(strntollu_test1) {
    char src[] = "-11";
    ck_assert_int_eq(s21_strntollu(src, NULL, 19, 2), -20);
}
END_TEST

Suite *suite_strntollu(void) {
    Suite *s = suite_create("suite_strntollu");
    TCase *tc = tcase_create("strntollu_tc");

    tcase_add_test(tc, strntollu_test1);

    suite_add_tcase(s, tc);
    return s;
}
