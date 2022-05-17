#include "../tests_includes/s21_tests.h"

START_TEST(empty_dest_and_src) {
    char src[200] = "";
    char src2[200] = "";
    s21_size_t copy_kByte = 0;

    char *res = src;
    char *expected = src2;
    s21_size_t check_kByte = 0;

    s21_memmove(res, src, copy_kByte);
    memmove(expected, src2, copy_kByte);

    ck_assert_mem_eq(res, expected, check_kByte);
} END_TEST

START_TEST(empty_dest) {
    char src[200] = "123SDFAZ`ESFsdfsdf";
    char src2[200] = "123SDFAZ`ESFsdfsdf";
    s21_size_t copy_kByte = 10;

    char res[200] = "";
    char expected[200] = "";
    s21_size_t check_kByte = 10;

    s21_memmove(res, src, copy_kByte);
    memmove(expected, src2, copy_kByte);

    ck_assert_mem_eq(res, expected, check_kByte);
} END_TEST


START_TEST(empty_src) {
    char src[200] = "";
    char src2[200] = "";
    s21_size_t copy_kByte = 0;

    char res[200] = "i hate memcmp";
    char expected[200] = "i hate memcmp";
    s21_size_t check_kByte = 13;

    s21_memmove(res, src, copy_kByte);
    memmove(expected, src2, copy_kByte);

    ck_assert_mem_eq(res, expected, check_kByte);
} END_TEST

START_TEST(write_in_left) {
    char src[200] = "Hate";
    char src2[200] = "Hate";
    s21_size_t copy_kByte = 4;

    char res[200] = "i hate memcmp";
    char expected[200] = "i hate memcmp";
    s21_size_t check_kByte = 17;

    s21_memmove(res, src, copy_kByte);
    memmove(expected, src2, copy_kByte);

    ck_assert_mem_eq(res, expected, check_kByte);
} END_TEST

START_TEST(write_in_right) {
    char src[200] = "Hate";
    char src2[200] = "Hate";
    s21_size_t copy_kByte = 4;

    char res[200] = "i hate memcmp";
    char expected[200] = "i hate memcmp";
    s21_size_t check_kByte = 17;

    s21_memmove(res + 13, src, copy_kByte);
    memmove(expected + 13, src2, copy_kByte);

    ck_assert_mem_eq(res, expected, check_kByte);
} END_TEST

START_TEST(write_in_mid) {
    char src[200] = "Hate";
    char src2[200] = "Hate";
    s21_size_t copy_kByte = 4;

    char res[200] = "i hate memcmp";
    char expected[200] = "i hate memcmp";
    s21_size_t check_kByte = 17;

    s21_memmove(res + 5, src, copy_kByte);
    memmove(expected + 5, src2, copy_kByte);

    ck_assert_mem_eq(res, expected, check_kByte);
} END_TEST

START_TEST(overlap_write_in_left) {
    char src[200] = "I HATE memmove!!!";
    char src2[200] = "I HATE memmove!!!";
    s21_size_t copy_kByte = 17;

    char *res = src;
    char *expected = src2;
    s21_size_t check_kByte = 34;

    s21_memmove(res, src, copy_kByte);
    memmove(expected, src2, copy_kByte);

    ck_assert_mem_eq(res, expected, check_kByte);
} END_TEST

START_TEST(overlap_write_in_right) {
    char src[200] = "I HATE memmove!!!";
    char src2[200] = "I HATE memmove!!!";
    s21_size_t copy_kByte = 17;

    char *res = src + 17;
    char *expected = src2 + 17;
    s21_size_t check_kByte = 34;

    s21_memmove(res, src, copy_kByte);
    memmove(expected, src2, copy_kByte);

    ck_assert_mem_eq(res, expected, check_kByte);
} END_TEST

START_TEST(overlap_write_in_mid) {
    char src[200] = "I HATE memmove!!!";
    char src2[200] = "I HATE memmove!!!";
    s21_size_t copy_kByte = 17;

    char *res = src + 5;
    char *expected = src2 + 5;
    s21_size_t check_kByte = 34;

    s21_memmove(res, src, copy_kByte);
    memmove(expected, src2, copy_kByte);

    ck_assert_mem_eq(res, expected, check_kByte);
} END_TEST


START_TEST(zero_test_string) {
    char src[] = "aboba";
    s21_size_t kByte = 0;
    char res[kByte+8];
    char expected[kByte+8];

    s21_memmove(res, src, kByte);
    memmove(expected, src, kByte);

    ck_assert_mem_eq(res, expected, kByte);
} END_TEST

START_TEST(any_empty) {
    char src[] = "";
    s21_size_t kByte = 0;
    char res[kByte+8];
    char expected[kByte+8];

    s21_memmove(res, src, kByte);
    memmove(expected, src, kByte);

    ck_assert_mem_eq(res, expected, kByte);
} END_TEST

START_TEST(zero_test_string_with_register) {
    char src[] = "I hate memcmp";
    s21_size_t kByte = 0;
    char res[kByte+8];
    char expected[kByte+8];

    s21_memmove(res, src, kByte);
    memmove(expected, src, kByte);

    ck_assert_mem_eq(res, expected, kByte);
} END_TEST


START_TEST(zero_test_num) {
    char src[] = "123";
    s21_size_t kByte = 1;
    char res[kByte+8];
    char expected[kByte+8];

    s21_memmove(res, src, kByte);
    memmove(expected, src, kByte);

    ck_assert_mem_eq(res, expected, kByte);
} END_TEST

START_TEST(one_byte_string) {
    char src[] = "aboba";
    s21_size_t kByte = 1;
    char res[kByte+8];
    char expected[kByte+8];

    s21_memmove(res, src, kByte);
    memmove(expected, src, kByte);

    ck_assert_mem_eq(res, expected, kByte);
} END_TEST

START_TEST(one_byte_string_with_register) {
    char src[] = "Zboba";
    s21_size_t kByte = 1;
    char res[kByte+8];
    char expected[kByte+8];

    s21_memmove(res, src, kByte);
    memmove(expected, src, kByte);

    ck_assert_mem_eq(res, expected, kByte);
} END_TEST


START_TEST(one_byte_num) {
    char src[] = "09";
    s21_size_t kByte = 1;
    char res[kByte+8];
    char expected[kByte+8];

    s21_memmove(res, src, kByte);
    memmove(expected, src, kByte);

    ck_assert_mem_eq(res, expected, kByte);
} END_TEST

START_TEST(basic_long_string) {
    char src[] = "abobasdafoijasdofjas asdopij";
    s21_size_t kByte = 28;
    char res[kByte+8];
    char expected[kByte+8];

    s21_memmove(res, src, kByte);
    memmove(expected, src, kByte);

    ck_assert_mem_eq(res, expected, kByte);
} END_TEST

START_TEST(long_string_with_register) {
    char src[] = "aposkd AOSIjFasodijpaoisdjf poisdjfg";
    s21_size_t kByte = 36;
    char res[kByte+8];
    char expected[kByte+8];

    s21_memmove(res, src, kByte);
    memmove(expected, src, kByte);

    ck_assert_mem_eq(res, expected, kByte);
} END_TEST

START_TEST(long_string_with_register_and_num) {
    char src[] = "aodasf ieuwfh luhasdfLIAUSHD liuh 12li3uh 12i4ouhsdfh";
    s21_size_t kByte = 53;
    char res[kByte+8];
    char expected[kByte+8];

    s21_memmove(res, src, kByte);
    memmove(expected, src, kByte);

    ck_assert_mem_eq(res, expected, kByte);
} END_TEST

START_TEST(long_string_with_register_and_num_and_simbol) {
    char src[] = "()()(((())):!,....aodasf ieuwfh luhasdfLIAUSHD liuh 12li3uh 12i4ouhsdfh";
    s21_size_t kByte = 71;
    char res[kByte+8];
    char expected[kByte+8];

    s21_memmove(res, src, kByte);
    memmove(expected, src, kByte);

    ck_assert_mem_eq(res, expected, kByte);
} END_TEST

START_TEST(ints) {
    int src[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    s21_size_t kByte = 4;
    char res[kByte+8];
    char expected[kByte+8];

    s21_memmove(res, src, kByte);
    memmove(expected, src, kByte);

    ck_assert_mem_eq(res, expected, kByte);
} END_TEST

START_TEST(floats) {
    float src[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    s21_size_t kByte = 8;
    char res[kByte+8];
    char expected[kByte+8];

    s21_memmove(res, src, kByte);
    memmove(expected, src, kByte);

    ck_assert_mem_eq(res, expected, kByte);
} END_TEST

START_TEST(long_doubels) {
    long double src[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    s21_size_t kByte = 16;
    char res[kByte + 8];
    char expected[kByte + 8];

    s21_memmove(res, src, kByte);
    memmove(expected, src, kByte);

    ck_assert_mem_eq(res, expected, kByte);
} END_TEST



Suite *suite_memmove(void) {
    Suite *s = suite_create("suite_memmove");
    TCase *tc = tcase_create("memmove_tc");

    tcase_add_test(tc, empty_dest_and_src);
    tcase_add_test(tc, empty_dest);
    tcase_add_test(tc, empty_src);
    tcase_add_test(tc, write_in_left);
    tcase_add_test(tc, write_in_right);
    tcase_add_test(tc, write_in_mid);
    tcase_add_test(tc, overlap_write_in_left);
    tcase_add_test(tc, overlap_write_in_right);
    tcase_add_test(tc, overlap_write_in_mid);

    // Old teste
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
    tcase_add_test(tc, ints);
    tcase_add_test(tc, floats);
    tcase_add_test(tc, long_doubels);

    suite_add_tcase(s, tc);
    return s;
}
