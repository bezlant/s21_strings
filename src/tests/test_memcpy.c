#include "../tests_includes/s21_tests.h"


START_TEST(hate_test) {
    char src[] = "i hate memcmp";
    s21_size_t kByte = 12;
    char res[kByte+8];
    char expected[kByte+8];

    s21_memcpy(res, src, kByte);
    memcpy(expected, src, kByte);

    ck_assert_mem_eq(res, expected, kByte);
} END_TEST


START_TEST(zero_test_string) {
    char src[] = "aboba";
    s21_size_t kByte = 0;
    char res[kByte+8];
    char expected[kByte+8];

    s21_memcpy(res, src, kByte);
    memcpy(expected, src, kByte);

    ck_assert_mem_eq(res, expected, kByte);
} END_TEST

START_TEST(any_empty) {
    char src[] = "";
    s21_size_t kByte = 0;
    char res[kByte+8];
    char expected[kByte+8];

    s21_memcpy(res, src, kByte);
    memcpy(expected, src, kByte);

    ck_assert_mem_eq(res, expected, kByte);
} END_TEST

START_TEST(zero_test_string_with_register) {
    char src[] = "I hate memcmp";
    s21_size_t kByte = 0;
    char res[kByte+8];
    char expected[kByte+8];

    s21_memcpy(res, src, kByte);
    memcpy(expected, src, kByte);

    ck_assert_mem_eq(res, expected, kByte);
} END_TEST


START_TEST(zero_test_num) {
    char src[] = "123";
    s21_size_t kByte = 1;
    char res[kByte+8];
    char expected[kByte+8];

    s21_memcpy(res, src, kByte);
    memcpy(expected, src, kByte);

    ck_assert_mem_eq(res, expected, kByte);
} END_TEST

START_TEST(one_byte_string) {
    char src[] = "aboba";
    s21_size_t kByte = 1;
    char res[kByte+8];
    char expected[kByte+8];

    s21_memcpy(res, src, kByte);
    memcpy(expected, src, kByte);

    ck_assert_mem_eq(res, expected, kByte);
} END_TEST

START_TEST(one_byte_string_with_register) {
    char src[] = "Zboba";
    s21_size_t kByte = 1;
    char res[kByte+8];
    char expected[kByte+8];

    s21_memcpy(res, src, kByte);
    memcpy(expected, src, kByte);

    ck_assert_mem_eq(res, expected, kByte);
} END_TEST


START_TEST(one_byte_num) {
    char src[] = "09";
    s21_size_t kByte = 1;
    char res[kByte+8];
    char expected[kByte+8];

    s21_memcpy(res, src, kByte);
    memcpy(expected, src, kByte);

    ck_assert_mem_eq(res, expected, kByte);
} END_TEST

START_TEST(basic_long_string) {
    char src[] = "abobasdafoijasdofjas asdopij";
    s21_size_t kByte = 28;
    char res[kByte+8];
    char expected[kByte+8];

    s21_memcpy(res, src, kByte);
    memcpy(expected, src, kByte);

    ck_assert_mem_eq(res, expected, kByte);
} END_TEST

START_TEST(long_string_with_register) {
    char src[] = "aposkd AOSIjFasodijpaoisdjf poisdjfg";
    s21_size_t kByte = 36;
    char res[kByte+8];
    char expected[kByte+8];

    s21_memcpy(res, src, kByte);
    memcpy(expected, src, kByte);

    ck_assert_mem_eq(res, expected, kByte);
} END_TEST

START_TEST(long_string_with_register_and_num) {
    char src[] = "aodasf ieuwfh luhasdfLIAUSHD liuh 12li3uh 12i4ouhsdfh";
    s21_size_t kByte = 53;
    char res[kByte+8];
    char expected[kByte+8];

    s21_memcpy(res, src, kByte);
    memcpy(expected, src, kByte);

    ck_assert_mem_eq(res, expected, kByte);
} END_TEST

START_TEST(long_string_with_register_and_num_and_simbol) {
    char src[] = "()()(((())):!,....aodasf ieuwfh luhasdfLIAUSHD liuh 12li3uh 12i4ouhsdfh";
    s21_size_t kByte = 71;
    char res[kByte+8];
    char expected[kByte+8];

    s21_memcpy(res, src, kByte);
    memcpy(expected, src, kByte);

    ck_assert_mem_eq(res, expected, kByte);
} END_TEST


Suite *suite_memcpy(void) {
    Suite *s = suite_create("suite_memcpy");
    TCase *tc = tcase_create("memcpy_tc");

    tcase_add_test(tc, hate_test);
    tcase_add_test(tc, zero_test_string);
    tcase_add_test(tc, any_empty);
    tcase_add_test(tc, zero_test_string_with_register);
    tcase_add_test(tc, zero_test_num);
    tcase_add_test(tc, one_byte_string);
    tcase_add_test(tc, one_byte_string_with_register);
    tcase_add_test(tc, one_byte_num);
    tcase_add_test(tc, basic_long_string);
    tcase_add_test(tc, long_string_with_register);
    tcase_add_test(tc, long_string_with_register_and_num);
    tcase_add_test(tc, long_string_with_register_and_num_and_simbol);

    suite_add_tcase(s, tc);
    return s;
}
