#include "../tests_includes/s21_tests.h"

START_TEST(insert_test1) {
    char str[] = "Shlepa";
    char src[] = "I love my . He is very kind!";
    s21_size_t index = 10;
    char expected[] = "I love my Shlepa. He is very kind!";
    char *got = (char *)s21_insert(src, str, index);
    ck_assert_str_eq(got, expected);
    if (got)
        free(got);
}
END_TEST

START_TEST(insert_test2) {
    char str[] = "Hello, ";
    char src[] = "Aboba!";
    s21_size_t index = 0;
    char expected[] = "Hello, Aboba!";
    char *got = (char *)s21_insert(src, str, index);
    ck_assert_str_eq(got, expected);
    if (got)
        free(got);
}
END_TEST

START_TEST(insert_test3) {
    char str[] = "";
    char src[] = "";
    s21_size_t index = 100;
    char *expected = "";
    char *got = (char *)s21_insert(src, str, index);
    ck_assert_str_eq(got, expected);
    if (got)
        free(got);
}
END_TEST

START_TEST(insert_test4) {
    char *src = NULL;
    char *str = NULL;
    s21_size_t index = 100;
    char *expected = NULL;
    char *got = (char *)s21_insert(src, str, index);
    ck_assert_ptr_eq(got, expected);
    if (got)
        free(got);
}
END_TEST

START_TEST(insert_test5) {
    char str[] = "Monkey";
    char src[] = "Space  ";
    s21_size_t index = 6;
    char expected[] = "Space Monkey ";
    char *got = (char *)s21_insert(src, str, index);
    ck_assert_str_eq(got, expected);
    if (got)
        free(got);
}
END_TEST

START_TEST(insert_str_null) {
    char *str = NULL;
    char src[] = "Space  ";
    s21_size_t index = 6;
    char expected[] = "Space  ";
    char *got = (char *)s21_insert(src, str, index);
    ck_assert_str_eq(got, expected);
    if (got)
        free(got);
}
END_TEST

Suite *suite_insert(void) {
    Suite *s = suite_create("suite_insert");
    TCase *tc = tcase_create("insert_tc");

    tcase_add_test(tc, insert_test1);
    tcase_add_test(tc, insert_test2);
    tcase_add_test(tc, insert_test3);
    tcase_add_test(tc, insert_test4);
    tcase_add_test(tc, insert_test5);
    tcase_add_test(tc, insert_str_null);

    suite_add_tcase(s, tc);
    return s;
}
