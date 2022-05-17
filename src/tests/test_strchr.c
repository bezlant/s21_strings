#include "../tests_includes/s21_tests.h"

START_TEST(abobasnutsa_find_a) {
    char src[] = "abobasnutsa";
    char find = 'a';

    ck_assert_pstr_eq(s21_strchr(src, find),
                     strchr(src, find));
} END_TEST

START_TEST(abobasnutAsa_find_A) {
    char src[] = "abobasnutAsa";
    char find = 'A';

    ck_assert_pstr_eq(s21_strchr(src, find),
                     strchr(src, find));
} END_TEST

START_TEST(abobasnutA1sa_find_1) {
    char src[] = "abobasnutA1sa";
    char find = '1';

    ck_assert_pstr_eq(s21_strchr(src, find),
                      strchr(src, find));
} END_TEST

START_TEST(abobasnutAsa_find_Z) {
    char src[] = "abobasnutAsa";
    char find = 'Z';

    ck_assert_pstr_eq(s21_strchr(src, find),
                      strchr(src, find));
} END_TEST

START_TEST(abobasnutAsa_find_3) {
    char src[] = "abobasnutAsa";
    char find = '3';

    ck_assert_pstr_eq(s21_strchr(src, find),
                      strchr(src, find));
} END_TEST

START_TEST(empty_src) {
    char src[] = "";
    char find = '3';

    ck_assert_pstr_eq(s21_strchr(src, find),
                      strchr(src, find));
} END_TEST

Suite *suite_strchr(void) {
    Suite *s = suite_create("suite_strchr");
    TCase *tc = tcase_create("strchr_tc");

    tcase_add_test(tc, abobasnutsa_find_a);
    tcase_add_test(tc, abobasnutAsa_find_A);
    tcase_add_test(tc, abobasnutA1sa_find_1);
    tcase_add_test(tc, abobasnutAsa_find_Z);
    tcase_add_test(tc, abobasnutAsa_find_3);
    tcase_add_test(tc, empty_src);

    suite_add_tcase(s, tc);
    return s;
}
