#include "../tests_includes/s21_tests.h"

START_TEST(empty) {
    char str1[] = "";
    char str2[] = "";

    ck_assert_pstr_eq(s21_strpbrk(str1, str2),
                      strpbrk(str1, str2));
} END_TEST

START_TEST(floppy_) {
    char str1[] = "floppy";
    char str2[] = "";

    ck_assert_pstr_eq(s21_strpbrk(str1, str2),
                      strpbrk(str1, str2));
} END_TEST

START_TEST(_floppy) {
    char str1[] = "";
    char str2[] = "floppy";

    ck_assert_pstr_eq(s21_strpbrk(str1, str2),
                      strpbrk(str1, str2));
} END_TEST

START_TEST(poki_doki_o) {
    char str1[] = "poki doki";
    char str2[] = "o";

    ck_assert_pstr_eq(s21_strpbrk(str1, str2),
                      strpbrk(str1, str2));
} END_TEST

START_TEST(poki_doki_i) {
    char str1[] = "poki doki";
    char str2[] = "i";

    ck_assert_pstr_eq(s21_strpbrk(str1, str2),
                      strpbrk(str1, str2));
} END_TEST

START_TEST(poki_doki_p) {
    char str1[] = "poki doki";
    char str2[] = "p";

    ck_assert_pstr_eq(s21_strpbrk(str1, str2),
                      strpbrk(str1, str2));
} END_TEST

START_TEST(find_big_P) {
    char str1[] = "ppppppppppppP";
    char str2[] = "P";

    ck_assert_pstr_eq(s21_strpbrk(str1, str2),
                      strpbrk(str1, str2));
} END_TEST

START_TEST(find_zero) {
    char str1[] = "ppppppppppppP";
    char str2[] = "\0";

    ck_assert_pstr_eq(s21_strpbrk(str1, str2),
                      strpbrk(str1, str2));
} END_TEST


Suite *suite_strpbrk(void) {
    Suite *s = suite_create("suite_strpbrk");
    TCase *tc = tcase_create("strpbrk_tc");

    tcase_add_test(tc, empty);
    tcase_add_test(tc, floppy_);
    tcase_add_test(tc, _floppy);
    tcase_add_test(tc, poki_doki_o);
    tcase_add_test(tc, poki_doki_i);
    tcase_add_test(tc, poki_doki_p);
    tcase_add_test(tc, find_big_P);
    tcase_add_test(tc, find_zero);

    suite_add_tcase(s, tc);
    return s;
}
