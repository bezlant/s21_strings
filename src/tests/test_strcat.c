#include "../tests_includes/s21_tests.h"

START_TEST(Hello_aboba) {
    char src[] = " aboba!!!";
    char res[5 + 10] = "Hello";
    char expected[5 + 10] = "Hello";

    s21_strcat(res, src);
    strcat(expected, src);

    ck_assert_str_eq(res, expected);
} END_TEST

START_TEST(zero_first) {
    char src[] = " aboba!!!";
    char res[0 + 10] = "";
    char expected[0 + 10] = "";

    s21_strcat(res, src);
    strcat(expected, src);

    ck_assert_str_eq(res, expected);
} END_TEST

START_TEST(zero_last) {
    char src[] = "";
    char res[] = "Hello";
    char expected[] = "Hello";

    s21_strcat(res, src);
    strcat(expected, src);

    ck_assert_str_eq(res, expected);
} END_TEST

START_TEST(any_letters_with_register) {
    char src[] = "asdfj  asdf aisdfjaiushdfASD SAD asDSad ASDAsdwqqeAS";
    char res[5 + 53] = "Hello";
    char expected[5 + 53] = "Hello";

    s21_strcat(res, src);
    strcat(expected, src);

    ck_assert_str_eq(res, expected);
} END_TEST

START_TEST(any_letters_with_register_and_num) {
    char src[] = "asd0fj  asd1f aisdfjw6234A1241SD SA5 asDSad 89SDAsdw7qqeAS";
    char res[5 + 59] = "Hello";
    char expected[5 + 59] = "Hello";

    s21_strcat(res, src);
    strcat(expected, src);

    ck_assert_str_eq(res, expected);
} END_TEST

START_TEST(any_letters_with_register_and_num_and_sim) {
    char src[] = "asd0fj  asd1f aisdfjw6234A1241SD SA5 asDSad 89SDAsdw7qqeAS)(?!.,";
    char res[5 + 65] = "Hello";
    char expected[5 + 65] = "Hello";

    s21_strcat(res, src);
    strcat(expected, src);

    ck_assert_str_eq(res, expected);
} END_TEST

Suite *suite_strcat(void) {
    Suite *s = suite_create("suite_strcat");
    TCase *tc = tcase_create("strcat_tc");

    tcase_add_test(tc, Hello_aboba);
    tcase_add_test(tc, zero_first);
    tcase_add_test(tc, zero_last);
    tcase_add_test(tc, any_letters_with_register);
    tcase_add_test(tc, any_letters_with_register_and_num);
    tcase_add_test(tc, any_letters_with_register_and_num_and_sim);

    suite_add_tcase(s, tc);
    return s;
}
