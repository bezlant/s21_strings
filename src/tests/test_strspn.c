#include "../tests_includes/s21_tests.h"

START_TEST(empty) {
    char src[] = "";
    char res[] = "";

    ck_assert_int_eq(s21_strspn(res, src),
                     strspn(res, src));
} END_TEST

START_TEST(gora_) {
    char src[] = "gora";
    char res[] = "";

    ck_assert_int_eq(s21_strspn(res, src),
                     strspn(res, src));
} END_TEST

START_TEST(_gora) {
    char src[] = "";
    char res[] = "gora";

    ck_assert_int_eq(s21_strspn(res, src),
                     strspn(res, src));
} END_TEST

START_TEST(any_register) {
    char src[] = "gora";
    char res[] = "gOra";

    ck_assert_int_eq(s21_strspn(res, src),
                     strspn(res, src));
} END_TEST

START_TEST(num_num) {
    char src[] = "123";
    char res[] = "123";

    ck_assert_int_eq(s21_strspn(res, src),
                     strspn(res, src));
} END_TEST

START_TEST(long_num_num) {
    char src[] = "12345";
    char res[] = "123";

    ck_assert_int_eq(s21_strspn(res, src),
                     strspn(res, src));
} END_TEST

START_TEST(num_long_num) {
    char src[] = "123";
    char res[] = "12345";

    ck_assert_int_eq(s21_strspn(res, src),
                     strspn(res, src));
} END_TEST

START_TEST(any_num) {
    char src[] = "1234567890";
    char res[] = "0987654321";

    ck_assert_int_eq(s21_strspn(res, src),
                     strspn(res, src));
} END_TEST

START_TEST(num_with_letter) {
    char src[] = "1A2A3A4A5A";
    char res[] = "123";

    ck_assert_int_eq(s21_strspn(res, src),
                     strspn(res, src));
} END_TEST

START_TEST(num_with_letter2) {
    char src[] = "a1aaa23aaa41235";
    char res[] = "123";

    ck_assert_int_eq(s21_strspn(res, src),
                     strspn(res, src));
} END_TEST

START_TEST(basic_test) {
    char src[] = "absD";
    char res[] = "aD";

    ck_assert_int_eq(s21_strspn(res, src),
                     strspn(res, src));
} END_TEST

START_TEST(any_sim) {
    char src[] = "32ASDASDPare[0g9jf m07y271234567890";
    char res[] = "0987654321";

    ck_assert_int_eq(s21_strspn(res, src),
                     strspn(res, src));
} END_TEST

START_TEST(upper_letter) {
    char src[] = "32ASDASDPare[0g9jf m07y271234567890";
    char res[] = "1234567890QWERTYUIOPASDFGHJKLZXCVBNM";

    ck_assert_int_eq(s21_strspn(res, src),
                     strspn(res, src));
} END_TEST

START_TEST(lower_letter) {
    char src[] = "32jersASDASDPare[0g9jf m07y271234567890";
    char res[] = "1234567890qwertyuiopasdfghjklczxcvbnm";

    ck_assert_int_eq(s21_strspn(res, src),
                     strspn(res, src));
} END_TEST

START_TEST(not_uniq_sim) {
    char src[] = "33333333333333333333333333333333333333333333333333333333333333333333333333333333333333";
    char res[] = "11111111111111111111111111111111111111111111111111111111111111111111111111111111111113";

    ck_assert_int_eq(s21_strspn(res, src),
                     strspn(res, src));
} END_TEST

Suite *suite_strspn(void) {
    Suite *s = suite_create("suite_strspn");
    TCase *tc = tcase_create("strspn_tc");

    tcase_add_test(tc, empty);
    tcase_add_test(tc, gora_);
    tcase_add_test(tc, _gora);
    tcase_add_test(tc, any_register);
    tcase_add_test(tc, num_num);
    tcase_add_test(tc, long_num_num);
    tcase_add_test(tc, num_long_num);
    tcase_add_test(tc, any_num);
    tcase_add_test(tc, num_with_letter);
    tcase_add_test(tc, num_with_letter2);
    tcase_add_test(tc, basic_test);
    tcase_add_test(tc, any_sim);
    tcase_add_test(tc, upper_letter);
    tcase_add_test(tc, lower_letter);
    tcase_add_test(tc, not_uniq_sim);

    suite_add_tcase(s, tc);
    return s;
}
