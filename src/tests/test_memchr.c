#include "../tests_includes/s21_tests.h"

START_TEST(empty_str) {
    s21_size_t n_byte = 0;
    char str[10] = "";
    int find_byte = '\0';

    ck_assert_ptr_eq(s21_memchr(str, find_byte, n_byte),
                     memchr(str, find_byte, n_byte));
} END_TEST

START_TEST(find_zero_in_string) {
    s21_size_t n_byte = 7;
    char str[10] = "string";
    int find_byte = '\0';

    ck_assert_ptr_eq(s21_memchr(str, find_byte, n_byte),
                     memchr(str, find_byte, n_byte));
} END_TEST

START_TEST(find_simbol_in_string_in_start) {
    s21_size_t n_byte = 6;
    char str[10] = "Atring";
    int find_byte = 'A';

    ck_assert_ptr_eq(s21_memchr(str, find_byte, n_byte),
                     memchr(str, find_byte, n_byte));
} END_TEST

START_TEST(find_simbol_in_string_in_end) {
    s21_size_t n_byte = 7;
    char str[10] = "StringA";
    int find_byte = 'A';

    ck_assert_ptr_eq(s21_memchr(str, find_byte, n_byte),
                     memchr(str, find_byte, n_byte));
} END_TEST

START_TEST(find_num_in_string_in_mid) {
    s21_size_t n_byte = 15;
    char str[16] = "Str55333222ingA";
    int find_byte = '3';

    ck_assert_ptr_eq(s21_memchr(str, find_byte, n_byte),
                     memchr(str, find_byte, n_byte));
} END_TEST

START_TEST(find_num_in_array_num) {
    int array[] = {1, 2, 3, 666, 5, 99, 100};
    s21_size_t n_byte = sizeof(int) * 7;
    int find_byte = 666;

    ck_assert_ptr_eq(s21_memchr(array, find_byte, n_byte),
                     memchr(array, find_byte, n_byte));
} END_TEST


START_TEST(find_float_in_array) {
    float array[] = {1, 2, 3, 666, 5, 99, 100};
    s21_size_t n_byte = sizeof(float) * 7;
    int find_byte = 666;

    ck_assert_ptr_eq(s21_memchr(array, find_byte, n_byte),
                     memchr(array, find_byte, n_byte));
} END_TEST

START_TEST(easy_test_string) {
    s21_size_t n_byte = 5;
    char str[10] = "aboba";
    int find_byte = 'c';

    ck_assert_ptr_eq(s21_memchr(str, find_byte, n_byte),
                     memchr(str, find_byte, n_byte));
} END_TEST

Suite *suite_memchr(void) {
    Suite *s = suite_create("suite_memchr");
    TCase *tc = tcase_create("memchr_tc");

    tcase_add_test(tc, empty_str);
    tcase_add_test(tc, find_zero_in_string);
    tcase_add_test(tc, find_simbol_in_string_in_start);
    tcase_add_test(tc, find_simbol_in_string_in_end);
    tcase_add_test(tc, find_num_in_string_in_mid);
    tcase_add_test(tc, find_num_in_array_num);
    tcase_add_test(tc, find_float_in_array);
    tcase_add_test(tc, easy_test_string);

    suite_add_tcase(s, tc);
    return s;
}
