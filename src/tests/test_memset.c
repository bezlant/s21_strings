#include "../tests_includes/s21_tests.h"

START_TEST(aboba_test) {
    char res[] = "aboba";
    char expected[] = "aboba";
    char replace = 'g';
    s21_size_t n_byte = 5;

    s21_memset(res, replace, n_byte);
    memset(expected, replace, n_byte);

    ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(zero_byte) {
    char res[] = "aboba";
    char expected[] = "aboba";
    char replace = 'g';
    s21_size_t n_byte = 0;

    s21_memset(res, replace, n_byte);
    memset(expected, replace, n_byte);

    ck_assert_str_eq(res, expected);
}
END_TEST
START_TEST(empty) {
    char res[] = "";
    char expected[] = "";
    char replace = '\0';
    s21_size_t n_byte = 0;

    s21_memset(res, replace, n_byte);
    memset(expected, replace, n_byte);

    ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(replace_on_register_sim) {
    char res[] = "aboba";
    char expected[] = "aboba";
    char replace = 'A';
    s21_size_t n_byte = 3;

    s21_memset(res, replace, n_byte);
    memset(expected, replace, n_byte);

    ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(replace_on_register_num) {
    char res[] = "a1obA";
    char expected[] = "a1obA";
    char replace = '1';
    s21_size_t n_byte = 5;

    s21_memset(res, replace, n_byte);
    memset(expected, replace, n_byte);

    ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(long_string) {
    char res[] = "a1oas[pifjaosidfj oapisjdfpoi asjdfoij ouh12oi3 uh12i3 hiajhIOUAHSDiouAHSdu1).bA";
    char expected[] = "a1oas[pifjaosidfj oapisjdfpoi asjdfoij ouh12oi3 uh12i3 hiajhIOUAHSDiouAHSdu1).bA";
    char replace = '1';
    s21_size_t n_byte = 5;

    s21_memset(res, replace, n_byte);
    memset(expected, replace, n_byte);

    ck_assert_str_eq(res, expected);
}
END_TEST

Suite *suite_memset(void) {
    Suite *s = suite_create("suite_memset");
    TCase *tc = tcase_create("memset_tc");

    tcase_add_test(tc, aboba_test);
    tcase_add_test(tc, zero_byte);
    tcase_add_test(tc, empty);
    tcase_add_test(tc, replace_on_register_sim);
    tcase_add_test(tc, replace_on_register_num);
    tcase_add_test(tc, long_string);

    suite_add_tcase(s, tc);
    return s;
}
