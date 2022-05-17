#include "../tests_includes/s21_tests.h"

START_TEST(empty) {
    char str1[] = "";
    char str2[] = "";
    s21_size_t n_byte = 0;

    int got = s21_strncmp(str1, str2, n_byte);
    int expected = strncmp(str1, str2, n_byte);

    if (got > 1) got = 1;
    if (expected > 1) expected = 1;

    if (got < -1) got = -1;
    if (expected < -1) expected = -1;

    ck_assert_int_eq(got, expected);
} END_TEST

START_TEST(floppa_) {
    char str1[] = "floppa";
    char str2[] = "";
    s21_size_t n_byte = 0;

    int got = s21_strncmp(str1, str2, n_byte);
    int expected = strncmp(str1, str2, n_byte);

    if (got > 1) got = 1;
    if (expected > 1) expected = 1;

    if (got < -1) got = -1;
    if (expected < -1) expected = -1;

    ck_assert_int_eq(got, expected);
} END_TEST

START_TEST(_floppa) {
    char str1[] = "";
    char str2[] = "floppa";
    s21_size_t n_byte = 0;

    int got = s21_strncmp(str1, str2, n_byte);
    int expected = strncmp(str1, str2, n_byte);

    if (got > 1) got = 1;
    if (expected > 1) expected = 1;

    if (got < -1) got = -1;
    if (expected < -1) expected = -1;

    ck_assert_int_eq(got, expected);
} END_TEST

START_TEST(floppa_floppa) {
    char str1[] = "floppa";
    char str2[] = "floppa";
    s21_size_t n_byte = 6;

    int got = s21_strncmp(str1, str2, n_byte);
    int expected = strncmp(str1, str2, n_byte);

    if (got > 1) got = 1;
    if (expected > 1) expected = 1;

    if (got < -1) got = -1;
    if (expected < -1) expected = -1;

    ck_assert_int_eq(got, expected);
} END_TEST

START_TEST(floppa_floppa_zero_byte) {
    char str1[] = "floppabazbazkotya";
    char str2[] = "floppabaz";
    s21_size_t n_byte = 10;

    int got = s21_strncmp(str1, str2, n_byte);
    int expected = strncmp(str1, str2, n_byte);

    if (got > 1) got = 1;
    if (expected > 1) expected = 1;

    if (got < -1) got = -1;
    if (expected < -1) expected = -1;

    ck_assert_int_eq(got, expected);
} END_TEST

START_TEST(floppa_floppa_one_byte) {
    char str1[] = "floppa";
    char str2[] = "floppa";
    s21_size_t n_byte = 1;

    int got = s21_strncmp(str1, str2, n_byte);
    int expected = strncmp(str1, str2, n_byte);

    if (got > 1) got = 1;
    if (expected > 1) expected = 1;

    if (got < -1) got = -1;
    if (expected < -1) expected = -1;

    ck_assert_int_eq(got, expected);
} END_TEST

Suite *suite_strncmp(void) {
    Suite *s = suite_create("suite_strncmp");
    TCase *tc = tcase_create("strncmp_tc");

    tcase_add_test(tc, empty);
    tcase_add_test(tc, floppa_);
    tcase_add_test(tc, _floppa);
    tcase_add_test(tc, floppa_floppa);
    tcase_add_test(tc, floppa_floppa_zero_byte);
    tcase_add_test(tc, floppa_floppa_one_byte);

    suite_add_tcase(s, tc);
    return s;
}
