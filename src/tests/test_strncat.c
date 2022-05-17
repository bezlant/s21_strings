#include "../tests_includes/s21_tests.h"

START_TEST(all_empty) {
    char src[] = "";
    char res[] = "";
    char expected[] = "";
    s21_size_t n_byte = 0;

    s21_strncat(res, src, n_byte);
    strncat(expected, src, n_byte);

    ck_assert_mem_ge(res, expected, n_byte);
} END_TEST

START_TEST(zero_byte) {
    char src[] = "abosal";
    char res[10] = "";
    char expected[10] = "";
    s21_size_t n_byte = 0;

    s21_strncat(res, src, n_byte);
    strncat(expected, src, n_byte);

    ck_assert_mem_ge(res, expected, n_byte);
} END_TEST

START_TEST(empty_src) {
    char src[] = "";
    char res[10] = "cd";
    char expected[10] = "cd";
    s21_size_t n_byte = 0;

    s21_strncat(res, src, n_byte);
    strncat(expected, src, n_byte);

    ck_assert_mem_ge(res, expected, n_byte);
} END_TEST


START_TEST(cd_abosa) {
    char src[] = "abosal";
    char res[10] = "cd";
    char expected[10] = "cd";
    s21_size_t n_byte = 5;

    s21_strncat(res, src, n_byte);
    strncat(expected, src, n_byte);

    ck_assert_mem_ge(res, expected, n_byte);
} END_TEST

START_TEST(string) {
    char src[] = "abosal";
    char res[25] = "koleka";
    char expected[25] = "koleka";
    s21_size_t n_byte = 6;

    s21_strncat(res, src, n_byte);
    strncat(expected, src, n_byte);

    ck_assert_mem_ge(res, expected, n_byte);
} END_TEST

START_TEST(BIGFLOPPA) {
    char src[] = "BIGFLOPPA";
    char res[25] = "BIGFLOPPA";
    char expected[25] = "BIGFLOPPA";
    s21_size_t n_byte = 5;

    s21_strncat(res, src, n_byte);
    strncat(expected, src, n_byte);

    ck_assert_mem_ge(res, expected, n_byte);
} END_TEST

START_TEST(BIGFLOPPA2) {
    char src[] = "BIGFLOPPA";
    char res[25] = "BIGFLOPPA";
    char expected[25] = "BIGFLOPPA";
    s21_size_t n_byte = 0;

    s21_strncat(res, src, n_byte);
    strncat(expected, src, n_byte);

    ck_assert_mem_ge(res, expected, n_byte);
} END_TEST

START_TEST(BIGFLOPPA3) {
    char src[] = "BIGFLOPPA";
    char res[25] = "BIGFLOPPA";
    char expected[25] = "BIGFLOPPA";
    s21_size_t n_byte = 1;

    s21_strncat(res, src, n_byte);
    strncat(expected, src, n_byte);

    ck_assert_mem_ge(res, expected, n_byte);
} END_TEST

START_TEST(BIGFLOPPA4) {
    char src[] = "BIGFLOPPA";
    char res[25] = "BIGFLOPPA";
    char expected[25] = "BIGFLOPPA";
    s21_size_t n_byte = 10;

    s21_strncat(res, src, n_byte);
    strncat(expected, src, n_byte);

    ck_assert_mem_ge(res, expected, n_byte);
} END_TEST

START_TEST(zero_char) {
    char src[] = "\0";
    char res[25] = "BIGFLOPPA";
    char expected[25] = "BIGFLOPPA";
    s21_size_t n_byte = 1;

    s21_strncat(res, src, n_byte);
    strncat(expected, src, n_byte);

    ck_assert_mem_ge(res, expected, n_byte);
} END_TEST


Suite *suite_strncat(void) {
    Suite *s = suite_create("suite_strncat");
    TCase *tc = tcase_create("strncat_tc");

    tcase_add_test(tc, all_empty);
    tcase_add_test(tc, zero_byte);
    tcase_add_test(tc, empty_src);
    tcase_add_test(tc, cd_abosa);
    tcase_add_test(tc, string);
    tcase_add_test(tc, BIGFLOPPA);
    tcase_add_test(tc, BIGFLOPPA2);
    tcase_add_test(tc, BIGFLOPPA3);
    tcase_add_test(tc, BIGFLOPPA4);
    tcase_add_test(tc, zero_char);

    suite_add_tcase(s, tc);
    return s;
}
