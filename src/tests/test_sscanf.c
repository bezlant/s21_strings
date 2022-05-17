#include "../tests_includes/s21_tests.h"

START_TEST(EOF1) {
    char fstr[] = "%d";
    char str[] = "        ";

    int16_t res1 = s21_sscanf(str, fstr, 0);
    int16_t res2 = sscanf(str, fstr, 100);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(EOF2) {
    char fstr[] = "%d ";
    char str[] = "               ";
    int16_t a1 = 0, a2 = 0;

    int16_t res1 = s21_sscanf(str, fstr, &a1);
    int16_t res2 = sscanf(str, fstr, &a2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(EOF3) {
    char fstr[] = "%d ";
    char str[] = "  ";
    int16_t a1 = 0, a2 = 0;

    int16_t res1 = s21_sscanf(str, fstr, &a1);
    int16_t res2 = sscanf(str, fstr, &a2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(only_chars1) {
    char fstr[] = "%c %c %c %c";
    char str[] = "   a     b c d";
    int16_t a1 = 0, a2 = 5, b1 = 0, b2 = 5, c1 = 0, c2 = 5, d1 = 0, d2 = 5;

    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);

    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(only_chars2) {
    char fstr[] = "%c%c%c%c";
    char str[] = "abcd";
    int16_t a1 = 0, a2 = 5, b1 = 0, b2 = 5, c1 = 0, c2 = 5, d1 = 0, d2 = 5;

    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);

    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(only_chars3) {
    char fstr[] = "%c %c %c      %c";
    char str[] = "1 a 3   c           ";
    int16_t a1 = 0, a2 = 5, b1 = 0, b2 = 5, c1 = 0, c2 = 5, d1 = 0, d2 = 5;

    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(only_chars4) {
    char fstr[] = "%c %c %c %c";
    char str[] = "   000 0    ";
    int16_t a1 = 0, a2 = 5, b1 = 0, b2 = 5, c1 = 0, c2 = 5, d1 = 0, d2 = 5;

    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);

    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(only_chars5) {
    char fstr[] = "%c %c %c %c";
    char str[] = "tttt";
    int16_t a1 = 0, a2 = 5, b1 = 0, b2 = 5, c1 = 0, c2 = 5, d1 = 0, d2 = 5;

    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);

    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(special_symbols_as_chars1) {
    char fstr[] = "%c%c%c%c";
    char str[] = "\\\n\t\t\t";
    int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(special_symbols_as_chars2) {
    char fstr[] = "%c %c %c %c";
    char str[] = "z ' ' /";
    int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(special_symbols_as_chars3) {
    char fstr[] = "%c%*c%c%c";
    char str[] = "ABCD";
    int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;

    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1);

    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(chars_flags1) {
    char fstr[] = "%c %c %c %c";
    char str[] = "z *'@";
    int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(chars_flags2) {
    char fstr[] = "%1c %c %c %0c";
    char str[] = "z *'@";
    int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(chars_flags3) {
    char fstr[] = "%c %c %c %c";
    char str[] = "z *'@";
    int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(chars_flags4) {
    char fstr[] = "%c %c %c %c";
    char str[] = "z *'@";
    int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(chars_flags5) {
    char fstr[] = "%*c%*c%*c%c";
    char str[] = "abcde";
    int16_t a1 = 0, a2 = 0;

    int16_t res1 = s21_sscanf(str, fstr, &a1);
    int16_t res2 = sscanf(str, fstr, &a2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(chars_aster1) {
    char fstr[] = "%*c%*c%*c%*c";
    char str[] = "   c ";
    int16_t a1 = 0, a2 = 0;

    int16_t res1 = s21_sscanf(str, fstr, &a1);
    int16_t res2 = sscanf(str, fstr, &a2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(chars_aster2) {
    char fstr[] = "%*c%*c%*c%c";
    char str[] = "abcd ";
    int16_t a1 = 0, a2 = 0;

    int16_t res1 = s21_sscanf(str, fstr, &a1);
    int16_t res2 = sscanf(str, fstr, &a2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(only_ints1) {
    long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    const char fstr[] = "%ld %ld %ld %ld";
    const char str[] = "555 666 777 888";

    int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(only_ints2) {
    int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    const char str[] = "1337 21 5008 3000";
    const char fstr[] = "%hd %hd %hd %hd";

    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(only_ints3) {
    long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    const char str[] = "1337 21 5008 300004";
    const char fstr[] = "%lld %lld %lld %lld";

    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(ints_nwidth1) {
    long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    const char str[] = "1337 21 5008 300004";
    const char fstr[] = "%1lld %3lld %1lld %4lld";

    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(ints_nwidth2) {
    long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    const char str[] = "1337";
    const char fstr[] = "%1lld %1lld %1lld %1lld";

    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(ints_nwidth3) {
    long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    const char str[] = "100000000000000005";
    const char fstr[] = "%3lld%lld%1lld%5lld";

    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(ints_nwidth4) {
    long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    const char str[] = "1337";
    const char fstr[] = "%15lld %1lld %1lld %1lld";

    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(ints_astwidth1) {
    long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;
    const char str[] = "1337123123 1 123412341234 1 999999 0";
    const char fstr[] = "%*d %lld %*d %lld %*d %lld";

    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(ints_astwidth2) {
    long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    const char str[] = "1337";
    const char fstr[] = "%15lld %1lld %1lld %1lld";

    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(ints_astwidth3) {
    long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    const char str[] = "1337";
    const char fstr[] = "%15lld %1lld %1lld %1lld";

    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(ints_astwidth4) {
    long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    const char str[] = "1337";
    const char fstr[] = "%15lld %1lld %1lld %1lld";

    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(signed_ints1) {
    long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    const char str[] = "11337 ++3 -5 ------4";
    const char fstr[] = "%lld %lld %lld %lld";

    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(signed_ints2) {
    long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    const char str[] = "-1337 +1 -1 -1";
    const char fstr[] = "%15lld %1lld %1lld %5lld";

    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(signed_ints3) {
    long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    const char str[] = "-0 +0 +0 -0";
    const char fstr[] = "%2lld %1lld %1lld %1lld";

    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(signed_ints4) {
    long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    const char str[] = "1 01 10 0";
    const char fstr[] = "%lld %lld %lld %lld";

    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(spec_i_int1) {
    long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    const char str[] = "300 500 -600 +700";
    const char fstr[] = "%lli %lli %lli %lli";

    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(spec_i_int2) {
    long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    const char str[] = "300500-600+700 111";
    const char fstr[] = "%lli %lld %lld %lli";

    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(spec_i_int3) {
    long long a1 = 0, a2 = 0, c1 = 0, c2 = 0;
    char b1 = 0, b2 = 0, d1 = 0, d2 = 0;
    const char str[] = "300500-600+700+400";
    const char fstr[] = "%lli%c%lli%c";

    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(spec_i_int4) {
    long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    const char str[] = "  55555 f f f5555555 ddd   4    3    1 ";
    const char fstr[] = "%lli %lld %lld %lli";

    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(spec_i_hex1) {
    long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    const char str[] = "0xFFF 0xA123123 0x123123 0x0";
    const char fstr[] = "%lli %lld %lld %lli";

    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(spec_i_hex2) {
    long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    const char str[] = " 0xFFFF 0xf 0xf 0xf5555555 ddd   4    3    1 ";
    const char fstr[] = "%lli %lld %lld %lli";

    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(spec_i_oct1) {
    long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    const char str[] = "  055555 0f 0f 0f5555555 0ddd   4    3    1 ";
    const char fstr[] = "%lli %lld %lld %lli";

    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(spec_i_oct2) {
    long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    const char str[] = "  055555 0f 0f 0f5555555 0ddd   4    3    1 ";
    const char fstr[] = "%lli %lld %lld %lli";

    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

/* [%s] */

START_TEST(strings1) {
    char s1[BUFF_SIZE] = {'\0'};
    char s2[BUFF_SIZE] = {'\0'};
    char s3[BUFF_SIZE] = {'\0'};
    char s4[BUFF_SIZE] = {'\0'};

    char s5[BUFF_SIZE] = {'\0'};
    char s6[BUFF_SIZE] = {'\0'};
    char s7[BUFF_SIZE] = {'\0'};
    char s8[BUFF_SIZE] = {'\0'};

    const char str[] = "Aboba Floppa Keppa Shleppa Anuroba";
    const char fstr[] = "%s %s %s %s";

    int16_t res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
    int16_t res2 = sscanf(str, fstr, s5, s6, s7, s8);

    ck_assert_int_eq(res1, res2);

    ck_assert_str_eq(s1, s5);
    ck_assert_str_eq(s2, s6);
    ck_assert_str_eq(s3, s7);
    ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(strings_mixed3) {
    char s1[BUFF_SIZE] = {'\0'};
    char s2[BUFF_SIZE] = {'\0'};
    char s3[BUFF_SIZE] = {'\0'};
    char s4[BUFF_SIZE] = {'\0'};

    char s5[BUFF_SIZE] = {'\0'};
    char s6[BUFF_SIZE] = {'\0'};
    char s7[BUFF_SIZE] = {'\0'};
    char s8[BUFF_SIZE] = {'\0'};

    long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

    const char str[] = "Aboba 123 Floppa -3 Keppa 4444Shleppa 333Anuroba 3";
    const char fstr[] = "%s%ld%s%d%s%d%s";

    int16_t res1 = s21_sscanf(str, fstr, s1, &a1, s2, &b1, s3, &c1, s4, &d1);
    int16_t res2 = s21_sscanf(str, fstr, s5, &a2, s6, &b2, s7, &c2, s8, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);

    ck_assert_str_eq(s1, s5);
    ck_assert_str_eq(s2, s6);
    ck_assert_str_eq(s3, s7);
    ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(strings2) {
    char s1[BUFF_SIZE] = {'\0'};
    char s2[BUFF_SIZE] = {'\0'};
    char s3[BUFF_SIZE] = {'\0'};
    char s4[BUFF_SIZE] = {'\0'};

    char s5[BUFF_SIZE] = {'\0'};
    char s6[BUFF_SIZE] = {'\0'};
    char s7[BUFF_SIZE] = {'\0'};
    char s8[BUFF_SIZE] = {'\0'};

    const char str[] = "aboba\tshlepa\tasdfasdf\tasdfasdf";
    const char fstr[] = "%s%s%s%s";

    int16_t res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
    int16_t res2 = sscanf(str, fstr, s5, s6, s7, s8);

    ck_assert_int_eq(res1, res2);

    ck_assert_str_eq(s1, s5);
    ck_assert_str_eq(s2, s6);
    ck_assert_str_eq(s3, s7);
    ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(strings3) {
    char s1[BUFF_SIZE] = {'\0'};
    char s2[BUFF_SIZE] = {'\0'};
    char s3[BUFF_SIZE] = {'\0'};
    char s4[BUFF_SIZE] = {'\0'};

    char s5[BUFF_SIZE] = {'\0'};
    char s6[BUFF_SIZE] = {'\0'};
    char s7[BUFF_SIZE] = {'\0'};
    char s8[BUFF_SIZE] = {'\0'};

    const char str[] = "aboba\tkepaboba floppa shleppa koooppa ap p p p p";
    const char fstr[] = "%*s%*s%*s%*s";

    int16_t res1 = s21_sscanf(str, fstr);
    int16_t res2 = sscanf(str, fstr);

    ck_assert_int_eq(res1, res2);

    ck_assert_str_eq(s1, s5);
    ck_assert_str_eq(s2, s6);
    ck_assert_str_eq(s3, s7);
    ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(strings4) {
    char s1[BUFF_SIZE] = {'\0'};
    char s2[BUFF_SIZE] = {'\0'};
    char s3[BUFF_SIZE] = {'\0'};
    char s4[BUFF_SIZE] = {'\0'};

    char s5[BUFF_SIZE] = {'\0'};
    char s6[BUFF_SIZE] = {'\0'};
    char s7[BUFF_SIZE] = {'\0'};
    char s8[BUFF_SIZE] = {'\0'};

    const char str[] = "aboba\tshlepa\tasdfasdf\tasdfasdf";
    const char fstr[] = "%1s%1s%1s%1s";

    int16_t res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
    int16_t res2 = sscanf(str, fstr, s5, s6, s7, s8);

    ck_assert_int_eq(res1, res2);

    ck_assert_str_eq(s1, s5);
    ck_assert_str_eq(s2, s6);
    ck_assert_str_eq(s3, s7);
    ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(strings5) {
    char s1[BUFF_SIZE] = {'\0'};
    char s2[BUFF_SIZE] = {'\0'};
    char s3[BUFF_SIZE] = {'\0'};
    char s4[BUFF_SIZE] = {'\0'};

    char s5[BUFF_SIZE] = {'\0'};
    char s6[BUFF_SIZE] = {'\0'};
    char s7[BUFF_SIZE] = {'\0'};
    char s8[BUFF_SIZE] = {'\0'};

    const char str[] = "aboba\tshlepa\tasdfasdf\tasdfasdf";
    const char fstr[] = "%3s%3s%3s%3s";

    int16_t res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
    int16_t res2 = sscanf(str, fstr, s5, s6, s7, s8);

    ck_assert_int_eq(res1, res2);

    ck_assert_str_eq(s1, s5);
    ck_assert_str_eq(s2, s6);
    ck_assert_str_eq(s3, s7);
    ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(strings6) {
    char s1[BUFF_SIZE] = {'\0'};
    char s2[BUFF_SIZE] = {'\0'};
    char s3[BUFF_SIZE] = {'\0'};
    char s4[BUFF_SIZE] = {'\0'};

    char s5[BUFF_SIZE] = {'\0'};
    char s6[BUFF_SIZE] = {'\0'};
    char s7[BUFF_SIZE] = {'\0'};
    char s8[BUFF_SIZE] = {'\0'};

    const char str[] = "aboba\tshlepa\tasdfasdf\tasdfasdf";
    const char fstr[] = "%150s%1s%1s\t%3s";

    int16_t res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
    int16_t res2 = sscanf(str, fstr, s5, s6, s7, s8);

    ck_assert_int_eq(res1, res2);

    ck_assert_str_eq(s1, s5);
    ck_assert_str_eq(s2, s6);
    ck_assert_str_eq(s3, s7);
    ck_assert_str_eq(s4, s8);
}
END_TEST

// strings_mixed1

START_TEST(strings_mixed1) {
    unsigned long long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;
    long long d1 = 0, d2 = 0;
    long double e1 = 0, e2 = 0;

    const char str[] = "4444444"
                       "eeeeeee\teeeeeee";
    const char fstr[] = "%5s %1s %*s %*s %llu %s %llu %llu %lld %Lf %33s";

    char s1[BUFF_SIZE] = {'\0'};
    char s2[BUFF_SIZE] = {'\0'};
    char s3[BUFF_SIZE] = {'\0'};
    char s4[BUFF_SIZE] = {'\0'};
    char s5[BUFF_SIZE] = {'\0'};
    char s6[BUFF_SIZE] = {'\0'};
    char s7[BUFF_SIZE] = {'\0'};
    char s8[BUFF_SIZE] = {'\0'};
    char s9[BUFF_SIZE] = {'\0'};
    char s10[BUFF_SIZE] = {'\0'};

    int16_t res1 =
        s21_sscanf(str, fstr, s7, s9, &a1, s5, &b1, &c1, &d1, &e1, s1);
    int16_t res2 = sscanf(str, fstr, s8, s10, &a2, s6, &b2, &c2, &d2, &e2, s2);

    ck_assert_int_eq(res1, res2);
    ck_assert_str_eq(s1, s2);
    ck_assert_str_eq(s3, s4);
    ck_assert_str_eq(s5, s6);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(strings_mixed2) {
    int d1 = 0, d2 = 0, b1 = 0, b2 = 0, a1 = 0, a2 = 0;
    long long v1, v2;

    const char str[] = "1 1 1 1 1 -1";
    const char fstr[] = "%1s %5d %1s %1s %d %lld %d";

    char s1[BUFF_SIZE] = {'\0'};
    char s2[BUFF_SIZE] = {'\0'};
    char s3[BUFF_SIZE] = {'\0'};
    char s4[BUFF_SIZE] = {'\0'};
    char s5[BUFF_SIZE] = {'\0'};
    char s6[BUFF_SIZE] = {'\0'};

    int16_t res1 = s21_sscanf(str, fstr, s1, &a1, s2, s3, &b1, &v1, &d1);
    int16_t res2 = sscanf(str, fstr, s4, &a2, s5, s6, &b2, &v2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_str_eq(s1, s2);
    ck_assert_str_eq(s3, s4);
    ck_assert_str_eq(s5, s6);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

/* [%n] */

START_TEST(n1) {
    long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    int32_t n1 = 0, n2 = 5;

    const char str[BUFF_SIZE] = "50 160 70 80";
    const char fstr[BUFF_SIZE] = "%lli %lli %n %lli %lli";

    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &n1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &n2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(n1, n2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(n2) {
    int n1 = 1, n2 = 5;

    char s1[BUFF_SIZE] = {'\0'};
    char s2[BUFF_SIZE] = {'\0'};
    char s3[BUFF_SIZE] = {'\0'};
    char s5[BUFF_SIZE] = {'\0'};
    char s6[BUFF_SIZE] = {'\0'};
    char s7[BUFF_SIZE] = {'\0'};

    const char str[] = "cbobErobM fl? asdfasdflkasdf asdfasdf asdfasdf 88888";
    const char fstr[] = "%s %s %n %s";

    int32_t res1 = s21_sscanf(str, fstr, s1, s2, &n1, s3);
    int32_t res2 = sscanf(str, fstr, s5, s6, &n2, s7);

    ck_assert_int_eq(res1, res2);

    ck_assert_int_eq(n1, n2);
    ck_assert_str_eq(s1, s5);
    ck_assert_str_eq(s2, s6);
    ck_assert_str_eq(s3, s7);
}
END_TEST

START_TEST(n3) {
    int n1 = 0, n2 = 5;

    const char str[BUFF_SIZE] = "50 60 70 80";
    const char fstr[BUFF_SIZE] = "%n";

    int16_t res1 = s21_sscanf(str, fstr, &n1);
    int16_t res2 = sscanf(str, fstr, &n2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(n4) {
    long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    int32_t n1 = 0, n2 = 5;

    const char str[] = "50 60 70 80";
    const char fstr[] = "%lli %lli %n %lli %lli";

    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &n1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &n2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(n1, n2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(n5) {
    long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    int n1 = 0, n2 = 5;

    const char str[] = "50 60 70 80";
    const char fstr[] = "%lli %lli %n %lli %lli";

    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &n1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &n2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(n1, n2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

/* [%f] / [%g] / %[%G] */

START_TEST(floats1) {
    long double a1 = 1, a2 = 0, b1 = 1, b2 = 0, c1 = 1, c2 = 0, d1 = 1, d2 = 0;

    const char str[] = "53.1 -4.1135 41.3333 +2.0001";
    const char fstr[] = "%Lf %Lf %Lf %Lf";

    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_double_eq(a1, a2);
    ck_assert_double_eq(b1, b2);
    ck_assert_double_eq(c1, c2);
    ck_assert_double_eq(d1, d2);
}
END_TEST

START_TEST(floats2) {
    double a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

    const char str[] = "0.00001 -4123123 4. .";
    const char fstr[] = "%lf %lf %lf %lf";

    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_double_eq(a1, a2);
    ck_assert_double_eq(b1, b2);
    ck_assert_double_eq(c1, c2);
    ck_assert_double_eq(d1, d2);
}
END_TEST

START_TEST(floats3) {
    float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

    const char str[] = ". . . .";
    const char fstr[] = "%f %f %f %f";

    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_double_eq(a1, a2);
    ck_assert_double_eq(b1, b2);
    ck_assert_double_eq(c1, c2);
    ck_assert_double_eq(d1, d2);
}
END_TEST

START_TEST(floats4) {
    long double a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

    const char str[] = "513.41 -4.14135 414.3333 +112.0001";
    const char fstr[] = "%Lf %Lf %Lf %Lf";

    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_double_eq(a1, a2);
    ck_assert_double_eq(b1, b2);
    ck_assert_double_eq(c1, c2);
    ck_assert_double_eq(d1, d2);
}
END_TEST

START_TEST(floats5) {
    float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;

    const char str[] = "53.1 -4.1135 411231.333 +2.0001";
    const char fstr[] = "%*f %f %f %f";

    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2);

    ck_assert_int_eq(res1, res2);
    ck_assert_float_eq(a1, a2);
    ck_assert_float_eq(b1, b2);
    ck_assert_float_eq(c1, c2);
}
END_TEST

START_TEST(floats_sci1) {
    float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

    const char str[] = "1.4441 1.31e+4 -3.31e-4 0.444e-5";
    const char fstr[] = "%G %G %G %G";

    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_double_eq(a1, a2);
    ck_assert_double_eq(b1, b2);
    ck_assert_double_eq(c1, c2);
    ck_assert_double_eq(d1, d2);
}
END_TEST

START_TEST(floats_sci2) {
    float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

    const char str[] = "inf 1.31e+4 NaN 0.444e-5";
    const char fstr[] = "%G %G %G %G";

    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_ldouble_eq(a1, a2);
    // Unfortunately, assertions for inf do not work correctly in libcheck
    // ck_assert_ldouble_infinite(a1);
    // ck_assert_ldouble_infinite(a2);
    ck_assert_double_eq(b1, b2);
    ck_assert_float_nan(c1);
    ck_assert_float_nan(c2);
    ck_assert_double_eq(d1, d2);
}
END_TEST

START_TEST(floats_sci3) {
    float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

    const char str[] = "inF InF inF INF";
    const char fstr[] = "%G %G %G %G";

    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_ldouble_eq(a1, a2);
    ck_assert_double_eq(b1, b2);
    ck_assert_double_eq(c1, c2);
    ck_assert_double_eq(d1, d2);
}
END_TEST

START_TEST(floats_sci4) {
    float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

    const char str[] = "Nan NAN 0.0000 0";
    const char fstr[] = "%G %G %G %G";

    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_float_nan(a1);
    ck_assert_float_nan(a2);
    ck_assert_float_nan(b1);
    ck_assert_float_nan(b2);
    ck_assert_ldouble_eq(c1, c2);
    ck_assert_ldouble_eq(d1, d2);
}
END_TEST

START_TEST(floats_sci5) {
    float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

    const char str[] =
        "nAN           INF                   -0.1111         1e-10";
    const char fstr[] = "%G %G %G %G";

    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_float_nan(a1);
    ck_assert_float_nan(a2);
    ck_assert_ldouble_eq(b1, b2);
    ck_assert_ldouble_eq(c1, c2);
    ck_assert_ldouble_eq(d1, d2);
}
END_TEST

/* [%u] */

START_TEST(uint1) {
    unsigned short a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0,
                   d2 = 0;
    const char str[] = "-1337 +21 --5008 3000";
    const char fstr[] = "%hu %hu %hu %hu";

    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

    ck_assert_uint_eq(res1, res2);
    ck_assert_uint_eq(a1, a2);
    ck_assert_uint_eq(b1, b2);
    ck_assert_uint_eq(c1, c2);
    ck_assert_uint_eq(d1, d2);
}
END_TEST

START_TEST(uint2) {
    unsigned long long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0,
                           d1 = 0, d2 = 0;
    const char str[] = "-1337 233333331 5008 3000";
    const char fstr[] = "%1llu %2llu %5llu %4llu";

    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(uint3) {
    unsigned long long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;
    long long d1 = 0, d2 = 0;
    long double v1, v2;

    const char str[] =
        "\t\t\t\t\t\n 3      adsfdfa%$$$$`adfasdfasdfaszcvzcxvcv -1337 "
        "anurobich+ 21 -5008 -33000 0.3333";
    const char fstr[] = "%*s %*s %llu %s %llu %llu %lld %Lf";

    char s1[BUFF_SIZE] = {'\0'};
    char s2[BUFF_SIZE] = {'\0'};

    int16_t res1 = s21_sscanf(str, fstr, &a1, s1, &b1, &c1, &d1, &v1);
    int16_t res2 = sscanf(str, fstr, &a2, s2, &b2, &c2, &d2, &v2);

    ck_assert_uint_eq(res1, res2);
    ck_assert_str_eq(s1, s2);
    ck_assert_uint_eq(a1, a2);
    ck_assert_uint_eq(b1, b2);
    ck_assert_uint_eq(c1, c2);
    ck_assert_uint_eq(d1, d2);
    ck_assert_ldouble_eq_tol(v1, v2, 0.0001);
}
END_TEST

START_TEST(uint4) {
    unsigned short a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0,
                   d2 = 0;
    const char str[] = "-1337 +21 --5008 3000";
    const char fstr[] = "%hu %hu %hu %hu";

    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(uint5) {
    unsigned short a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0,
                   d2 = 0;
    const char str[] = "-1337 +21 --5008 3000";
    const char fstr[] = "%hu %hu %hu %hu";

    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(uint6) {
    unsigned short a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0,
                   d2 = 0;
    const char str[] = "-1337 +21 --5008 3000";
    const char fstr[] = "%hu %hu %hu %hu";

    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(upeer_hex_base_version) {
    uint32_t a1, a2;
    const char str[] = "F";
    const char fstr[] = "%X";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(upeer_hex_overflow) {
    uint32_t a1, a2;
    const char str[] = "0xFFFFFFFF";
    const char fstr[] = "%X";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(upeer_hex_0x) {
    uint32_t a1, a2;
    const char str[] = "0x";
    const char fstr[] = "%X";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(upeer_hex_0X) {
    uint32_t a1, a2;
    const char str[] = "0X";
    const char fstr[] = "%X";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(upeer_hex_empty) {
    uint32_t a1, a2;
    const char str[] = "";
    const char fstr[] = "%X";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);

    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(upeer_hex_fail) {
    uint32_t a1, a2;
    const char str[] = "qF";
    const char fstr[] = "%X";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);

    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(upeer_hex_spaces_tabs_sns) {
    uint32_t a1, a2;
    const char str[] = "          \n             \n     F";
    const char fstr[] = "%X";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(upeer_hex_short) {
    uint16_t a1, a2;
    const char str[] = "F";
    const char fstr[] = "%hX";
    uint16_t res1 = s21_sscanf(str, fstr, &a1);
    uint16_t res2 = sscanf(str, fstr, &a2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(upeer_hex_long) {
    unsigned long int a1, a2;
    const char str[] = "F";
    const char fstr[] = "%lX";
    uint16_t res1 = s21_sscanf(str, fstr, &a1);
    uint16_t res2 = sscanf(str, fstr, &a2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(upeer_hex_longlong) {
    unsigned long long int a1, a2;
    const char str[] = "F";
    const char fstr[] = "%llX";
    uint16_t res1 = s21_sscanf(str, fstr, &a1);
    uint16_t res2 = sscanf(str, fstr, &a2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(upeer_hex_2x) {
    uint32_t a1, a2;
    const char str[] = "0xFF0x0xFFF 0xFFxFF";
    const char fstr[] = "%X";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(upeer_hex_star) {
    const char str[] = "0xFF0x0xFFF 0xFFxFF";
    const char fstr[] = "%*X";
    uint32_t res1 = s21_sscanf(str, fstr);
    uint32_t res2 = sscanf(str, fstr);

    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(upeer_hex_nohex) {
    uint32_t a1, a2;
    const char str[] = "tqwqpl";
    const char fstr[] = "%X";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);

    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(upeer_hex_lower) {
    uint32_t a1, a2;
    const char str[] = "abcdef";
    const char fstr[] = "%X";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(upeer_hex_sign) {
    uint32_t a1, a2;
    const char str[] = "-f";
    const char fstr[] = "%X";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(lower_hex_base_version) {
    uint32_t a1, a2;
    const char str[] = "f";
    const char fstr[] = "%x";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(lower_hex_overflow) {
    uint32_t a1, a2;
    const char str[] = "0xfffffffffffffffffff";
    const char fstr[] = "%x";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(lower_hex_0x) {
    uint32_t a1, a2;
    const char str[] = "0x";
    const char fstr[] = "%x";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(lower_hex_0X) {
    uint32_t a1, a2;
    const char str[] = "0X";
    const char fstr[] = "%x";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(lower_hex_empty) {
    uint32_t a1, a2;
    const char str[] = "";
    const char fstr[] = "%x";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);

    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(lower_hex_fail) {
    uint32_t a1, a2;
    const char str[] = "qF";
    const char fstr[] = "%x";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);

    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(lower_hex_spaces_tabs_sns) {
    uint32_t a1, a2;
    const char str[] = "          \n             \n     F";
    const char fstr[] = "%x";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(lower_hex_short) {
    uint16_t a1, a2;
    const char str[] = "ff";
    const char fstr[] = "%hx";
    uint16_t res1 = s21_sscanf(str, fstr, &a1);
    uint16_t res2 = sscanf(str, fstr, &a2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(lower_hex_long) {
    unsigned long int a1, a2;
    const char str[] = "ff";
    const char fstr[] = "%lx";
    uint16_t res1 = s21_sscanf(str, fstr, &a1);
    uint16_t res2 = sscanf(str, fstr, &a2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(lower_hex_longlong) {
    unsigned long long int a1, a2;
    const char str[] = "faaaaaaaaaaaaf";
    const char fstr[] = "%llx";
    uint16_t res1 = s21_sscanf(str, fstr, &a1);
    uint16_t res2 = sscanf(str, fstr, &a2);

    ck_assert_int_eq(res1, res2);
    // ck_assert_unsigned long long int_eq(a1, a2);
    // ck_assert_uint64_eq(a1, a2);
    ck_assert_uint_eq(a1, a2);
}
END_TEST

START_TEST(lower_hex_2x) {
    uint32_t a1, a2;
    const char str[] = "0xFF0x0xFFF 0xFFxFF";
    const char fstr[] = "%x";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(lower_hex_star) {
    const char str[] = "0xFF0x0xFFF 0xFFxFF";
    const char fstr[] = "%*x";
    uint32_t res1 = s21_sscanf(str, fstr);
    uint32_t res2 = sscanf(str, fstr);

    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(lower_hex_nohex) {
    uint32_t a1, a2;
    const char str[] = "tqwqpl";
    const char fstr[] = "%x";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);

    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(lower_hex_lower) {
    uint32_t a1, a2;
    const char str[] = "abcdef";
    const char fstr[] = "%x";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(lower_hex_sign) {
    uint32_t a1, a2;
    const char str[] = "-f";
    const char fstr[] = "%x";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(upper_hex_len) {
    uint32_t a1, a2;
    const char str[] = "123531FFF";
    const char fstr[] = "%2X";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(lower_hex_len) {
    uint32_t a1, a2;
    const char str[] = "123531FFF";
    const char fstr[] = "%2x";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(octal_base_version) {
    uint32_t a1, a2;
    const char str[] = "777";
    const char fstr[] = "%o";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(octal_overflow) {
    uint32_t a1, a2;
    const char str[] = "0x7777777777777777777777";
    const char fstr[] = "%o";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(octal_0x) {
    uint32_t a1, a2;
    const char str[] = "0x";
    const char fstr[] = "%o";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(octal_0X) {
    uint32_t a1, a2;
    const char str[] = "0X";
    const char fstr[] = "%o";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(octal_empty) {
    uint32_t a1, a2;
    const char str[] = "";
    const char fstr[] = "%o";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);

    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(octal_fail) {
    uint32_t a1, a2;
    const char str[] = "q1";
    const char fstr[] = "%o";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);

    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(octal_spaces_tabs_sns) {
    uint32_t a1, a2;
    const char str[] = "          \n             \n     5";
    const char fstr[] = "%o";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(octal_short) {
    uint16_t a1, a2;
    const char str[] = "12";
    const char fstr[] = "%ho";
    uint16_t res1 = s21_sscanf(str, fstr, &a1);
    uint16_t res2 = sscanf(str, fstr, &a2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(octal_long) {
    unsigned long int a1, a2;
    const char str[] = "57234";
    const char fstr[] = "%lo";
    uint16_t res1 = s21_sscanf(str, fstr, &a1);
    uint16_t res2 = sscanf(str, fstr, &a2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(octal_longlong) {
    unsigned long long int a1, a2;
    const char str[] = "12356226137";
    const char fstr[] = "%llo";
    uint16_t res1 = s21_sscanf(str, fstr, &a1);
    uint16_t res2 = sscanf(str, fstr, &a2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(octal_2x) {
    uint32_t a1, a2;
    const char str[] = "0x12320x213x123213";
    const char fstr[] = "%o";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(octal_star) {
    const char str[] = "521561612";
    const char fstr[] = "%*o";
    uint32_t res1 = s21_sscanf(str, fstr);
    uint32_t res2 = sscanf(str, fstr);

    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(octal_nohex) {
    uint32_t a1, a2;
    const char str[] = "tqwqpl";
    const char fstr[] = "%o";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);

    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(octal_lower) {
    uint32_t a1, a2;
    const char str[] = "01234567";
    const char fstr[] = "%o";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(octal_sign) {
    uint32_t a1, a2;
    const char str[] = "-66";
    const char fstr[] = "%o";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(octal_len) {
    uint32_t a1, a2;
    const char str[] = "123531";
    const char fstr[] = "%2o";
    uint32_t res1 = s21_sscanf(str, fstr, &a1);
    uint32_t res2 = sscanf(str, fstr, &a2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(buff1) {
    int32_t a1, a2;
    int32_t b1, b2;
    const char str[] = "12 keppa 12";
    const char fstr[] = "%d keppa %d";
    int32_t res1 = s21_sscanf(str, fstr, &a1, &b1);
    int32_t res2 = sscanf(str, fstr, &a2, &b2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
}
END_TEST

START_TEST(buff2) {
    int32_t a1, a2;
    int32_t b1, b2;
    const char str[] = "12keppa12";
    const char fstr[] = "%dkeppa%d";
    int32_t res1 = s21_sscanf(str, fstr, &a1, &b1);
    int32_t res2 = sscanf(str, fstr, &a2, &b2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
}
END_TEST

START_TEST(pointer1) {
    int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;
    const char str[] = "0xFFFF 0xAAAA 0x7123 0xBBC1FF";
    const char fstr[] = "%p %p %p %p";

    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_ptr_eq(a1, a2);
    ck_assert_ptr_eq(b1, b2);
    ck_assert_ptr_eq(c1, c2);
    ck_assert_ptr_eq(d1, d2);
}
END_TEST

START_TEST(pointer2) {
    int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;
    const char str[] = "0xFFFF 0xAAAA 0x7123 0xBBC1FF";
    const char fstr[] = "%p %p %p %p";

    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_ptr_eq(a1, a2);
    ck_assert_ptr_eq(b1, b2);
    ck_assert_ptr_eq(c1, c2);
    ck_assert_ptr_eq(d1, d2);
}
END_TEST

START_TEST(pointer3) {
    int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;
    const char str[] = "0xFFFF 0xAAAA 0x7123 0xBBC1FF";
    const char fstr[] = "%p %p %p %p";

    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_ptr_eq(a1, a2);
    ck_assert_ptr_eq(b1, b2);
    ck_assert_ptr_eq(c1, c2);
    ck_assert_ptr_eq(d1, d2);
}
END_TEST

START_TEST(pointer4) {
    int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;
    const char str[] = "0xFFFF 0xAAAA 0x7123 0xBBC1FF";
    const char fstr[] = "%p %p %p %p";

    int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_ptr_eq(a1, a2);
    ck_assert_ptr_eq(b1, b2);
    ck_assert_ptr_eq(c1, c2);
    ck_assert_ptr_eq(d1, d2);
}
END_TEST

START_TEST(hard1) {
    int a1 = 0, a2 = 5, a3 = 3, a4 = 9;
    int32_t n1 = 500, n2 = 10000;

    const char str[] = "123123SkipMePlease!!!!123";
    const char fstr[] = "%dSkipMePlease!!!!%d %n";

    int16_t res1 = s21_sscanf(str, fstr, &a1, &a3, &n1);
    int16_t res2 = sscanf(str, fstr, &a2, &a4, &n2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(n1, n2);
    ck_assert_int_eq(a3, a4);
    ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(buff3) {
    int32_t a1, a2;
    int32_t b1 = 0, b2 = 0;
    const char str[] = "12keppa12";
    const char fstr[] = "%dkeppapos%d";
    int32_t res1 = s21_sscanf(str, fstr, &a1, &b1);
    int32_t res2 = sscanf(str, fstr, &a2, &b2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
}
END_TEST

START_TEST(perc1) {
    int32_t a1, a2;
    int32_t b1 = 80, b2 = 33;
    int32_t c1 = 55, c2 = 33;
    const char str[] = "12 % 13 % 14";
    const char fstr[] = "%d %% %d %% %d";
    int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1);
    int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(perc2) {
    int32_t a1, a2;
    int32_t b1 = 80, b2 = 33;
    int32_t c1 = 55, c2 = 33;
    const char str[] = "12%13%14";
    const char fstr[] = "%d%%%d%%%d";
    int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1);
    int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(perc3) {
    int32_t a1 = 1234, a2 = 33333;

    const char str[] = "%%%16";
    const char fstr[] = "%%%%%%%d";
    int32_t res1 = s21_sscanf(str, fstr, &a1);
    int32_t res2 = sscanf(str, fstr, &a2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(perc4) {
    const char str[] = "%%%";
    const char fstr[] = "%%%%%%";
    int32_t res1 = s21_sscanf(str, fstr);
    int32_t res2 = sscanf(str, fstr);

    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(perc5) {
    int32_t a1 = 1234, a2 = 33333;
    int32_t b1 = 1234, b2 = 33333;

    const char str[] = "%%123%888";
    const char fstr[] = "%%%%%d%%%d";
    int32_t res1 = s21_sscanf(str, fstr, &a1, &b1);
    int32_t res2 = sscanf(str, fstr, &a2, &b2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
}
END_TEST

START_TEST(mixed_ptrs1) {
    int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;

    const char str[] = "0xFFFF 0xAAA 7123 0xBBC1FF";
    const char fstr[] = "%p %p %p %p";

    int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_ptr_eq(a1, a2);
    ck_assert_ptr_eq(b1, b2);
    ck_assert_ptr_eq(c1, c2);
    ck_assert_ptr_eq(d1, d2);
}
END_TEST

START_TEST(mixed_ptrs2) {
    char *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;

    const char str[] = "0x4 0x3 0x2 0x1";
    const char fstr[] = "%p %p %p %p";

    int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_ptr_eq(a1, a2);
    ck_assert_ptr_eq(b1, b2);
    ck_assert_ptr_eq(c1, c2);
    ck_assert_ptr_eq(d1, d2);
}
END_TEST

START_TEST(mixed_ptrs3) {
    int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;

    const char str[] = "03033 0333 0123 0123 0x123 0xFFFFF 0xBBC1FF";
    const char fstr[] = "%p %p %p %p";

    int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_ptr_eq(a1, a2);
    ck_assert_ptr_eq(b1, b2);
    ck_assert_ptr_eq(c1, c2);
    ck_assert_ptr_eq(d1, d2);
}
END_TEST

START_TEST(mixed_ptrs4) {
    int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;

    const char str[] = "0xABCDEF 0xAAA 7123 0xBBC1FF";
    const char fstr[] = "%p %p %p %p";

    int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_ptr_eq(a1, a2);
    ck_assert_ptr_eq(b1, b2);
    ck_assert_ptr_eq(c1, c2);
    ck_assert_ptr_eq(d1, d2);
}
END_TEST

START_TEST(mixed_ptrs5) {
    int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;

    const char str[] = "NULL";
    const char fstr[] = "%p %p %p %p";

    int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_ptr_eq(a1, a2);
    ck_assert_ptr_eq(b1, b2);
    ck_assert_ptr_eq(c1, c2);
    ck_assert_ptr_eq(d1, d2);
}
END_TEST

START_TEST(hard3) {
    char a1, a2;
    char b1[256] = {'\0'};
    char b2[256] = {'\0'};
    float c1, c2;
    short int d1, d2;
    long long int e1, e2;

    const char str[] = "$AmIIn%%sane? %\n\n\n \n \n \n\t   InF 0 %FIN9D-ME%";
    const char fstr[] = "%c%5s%%%*s %%  %G %hi %%FIN%lldDME%%";

    int32_t res1 = s21_sscanf(str, fstr, &a1, b1, &c1, &d1, &e1);
    int32_t res2 = sscanf(str, fstr, &a2, b2, &c2, &d2, &e2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_str_eq(b1, b2);
    ck_assert_float_infinite(c1);
    ck_assert_float_infinite(c2);
    ck_assert_int_eq(d1, d2);
    ck_assert_int_eq(e1, e2);
}
END_TEST

START_TEST(hard4) {
    char a1, a2;
    char b1, b2;
    char c1, c2;
    char d1, d2;

    const char str[] = "%%$Char!StressssT%%estus!&&&";
    const char fstr[] = "%% %*c%*c%*c%*c%*c %c %c %c %c ### %*c";

    int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(hard5) {
    char a1, a2;
    char b1, b2;
    char c1, c2;
    char d1, d2;
    const char str[] = "%%$Char!StressssVIm User Aboba %% %%% %%% %% % % %% % "
                       "% % %% % % %% %T%%estus!%%&&&";
    const char fstr[] = "%% %*c%*c%*c%*c%*c %c %c %c %c %% %% %% %% %% %% %% "
                        "%% %% %% %% %% %% %% %% %% ### %*c";

    int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
}
END_TEST

Suite *suite_sscanf(void) {
    Suite *s = suite_create("suite_sscanf");
    TCase *tc = tcase_create("sscanf_tc");
    // %[width][length][specifier]

    // [EOF]
    // Flags: do nothing (unapplicable to this specifier)

    tcase_add_test(tc, EOF1);
    tcase_add_test(tc, EOF2);
    tcase_add_test(tc, EOF3);

    // // [%c]
    // // Flags:
    // // [Width] - N: 0, 1 - Do nothing; N > 1 - Undefined beh.
    // //          * - skips chars
    // // [Precision] - Any precision flag immediately stops sscanf (error)
    // // [Length] - Does nothing

    tcase_add_test(tc, only_chars1);
    tcase_add_test(tc, only_chars2);
    tcase_add_test(tc, only_chars3);
    tcase_add_test(tc, only_chars4);
    tcase_add_test(tc, only_chars5);
    tcase_add_test(tc, special_symbols_as_chars1);
    tcase_add_test(tc, special_symbols_as_chars2);
    tcase_add_test(tc, special_symbols_as_chars3);

    tcase_add_test(tc, chars_flags1);  // Precision flags lead to fail
    tcase_add_test(tc, chars_flags2);  // Width flags do nothing (if <= 1)
    tcase_add_test(
        tc, chars_flags3);  // Demonstrates how (*) works. * - ignore the char
    tcase_add_test(tc, chars_flags4);  // Length flags do nothing
    tcase_add_test(tc, chars_flags5);  // * flags - ignores char
    // Test cases specifically for (%*c), as this is very important concept
    tcase_add_test(tc, chars_aster1);
    tcase_add_test(tc, chars_aster2);

    // // [%d]/[%i]
    // // [Width]: * - skip token, (N) - read N chars as a number
    // // [Precision]: Not applicable to int, considered as UB

    // // Length (h, l, ll)
    tcase_add_test(tc, only_ints1);
    tcase_add_test(tc, only_ints2);
    tcase_add_test(tc, only_ints3);
    // // Width (N)
    tcase_add_test(tc, ints_nwidth1);
    tcase_add_test(tc, ints_nwidth2);
    tcase_add_test(tc, ints_nwidth3);
    tcase_add_test(tc, ints_nwidth4);
    // // Width (*)
    tcase_add_test(tc, ints_astwidth1);
    tcase_add_test(tc, ints_astwidth2);
    tcase_add_test(tc, ints_astwidth3);
    tcase_add_test(tc, ints_astwidth4);
    // // Negative & positive ints
    tcase_add_test(tc, signed_ints1);
    tcase_add_test(tc, signed_ints2);
    tcase_add_test(tc, signed_ints3);
    tcase_add_test(tc, signed_ints4);

    // // // [%i] Specifier. It may be INT, OCT, HEX

    tcase_add_test(tc, spec_i_int1);
    tcase_add_test(tc, spec_i_int2);
    // // Mixed with chars & ints
    tcase_add_test(tc, spec_i_int3);
    tcase_add_test(tc, spec_i_int4);

    tcase_add_test(tc, spec_i_oct1);
    tcase_add_test(tc, spec_i_oct2);
    tcase_add_test(tc, spec_i_hex1);
    tcase_add_test(tc, spec_i_hex2);

    // // [%s]
    // // Width: (N) - parses N chars, (*) - пропустить строку
    // // OUT: res = 4 (корректно парсит все в разные строки)
    // // int res = sscanf("abobashlepafloppakoppa", "%5s %6s %6s %4s", s1, s2,
    // s3,
    // // s4); Precision, length - not applicable

    tcase_add_test(tc, strings1);
    tcase_add_test(tc, strings2);
    tcase_add_test(tc, strings3);
    tcase_add_test(tc, strings4);
    tcase_add_test(tc, strings5);
    tcase_add_test(tc, strings6);
    tcase_add_test(tc, uint1);
    tcase_add_test(tc, uint2);
    tcase_add_test(tc, uint3);
    tcase_add_test(tc, uint4);
    tcase_add_test(tc, uint5);
    tcase_add_test(tc, uint6);
    tcase_add_test(tc, strings_mixed1);
    tcase_add_test(tc, strings_mixed2);
    tcase_add_test(tc, strings_mixed3);

    // // [%f] [%g] [%G]
    // // Width: (N) - parses N chars, (*) - пропустить строку
    // // Precision: take it into account while parsing AFTER (.)
    // // Length - l - long

    tcase_add_test(tc, floats1);
    tcase_add_test(tc, floats2);
    tcase_add_test(tc, floats3);
    tcase_add_test(tc, floats4);
    tcase_add_test(tc, floats5);

    tcase_add_test(tc, floats_sci1);
    tcase_add_test(tc, floats_sci2);
    tcase_add_test(tc, floats_sci3);
    tcase_add_test(tc, floats_sci4);
    tcase_add_test(tc, floats_sci5);

    // [%n] specifier

    tcase_add_test(tc, n1);

    tcase_add_test(tc, n2);
    tcase_add_test(tc, n3);
    tcase_add_test(tc, n4);
    tcase_add_test(tc, n5);

    tcase_add_test(tc, n2);
    tcase_add_test(tc, n3);
    tcase_add_test(tc, n4);
    tcase_add_test(tc, n5);

    tcase_add_test(tc, upeer_hex_base_version);
    tcase_add_test(tc, upeer_hex_overflow);
    tcase_add_test(tc, upeer_hex_0x);
    tcase_add_test(tc, upeer_hex_0X);
    tcase_add_test(tc, upeer_hex_empty);
    tcase_add_test(tc, upeer_hex_fail);
    tcase_add_test(tc, upeer_hex_spaces_tabs_sns);
    tcase_add_test(tc, upeer_hex_short);
    tcase_add_test(tc, upeer_hex_long);
    tcase_add_test(tc, upeer_hex_longlong);
    tcase_add_test(tc, upeer_hex_2x);
    tcase_add_test(tc, upeer_hex_star);
    tcase_add_test(tc, upeer_hex_nohex);
    tcase_add_test(tc, upeer_hex_lower);
    tcase_add_test(tc, upeer_hex_sign);
    tcase_add_test(tc, upper_hex_len);

    tcase_add_test(tc, lower_hex_base_version);
    tcase_add_test(tc, lower_hex_overflow);
    tcase_add_test(tc, lower_hex_0x);
    tcase_add_test(tc, lower_hex_0X);
    tcase_add_test(tc, lower_hex_empty);
    tcase_add_test(tc, lower_hex_fail);
    tcase_add_test(tc, lower_hex_spaces_tabs_sns);
    tcase_add_test(tc, lower_hex_short);
    tcase_add_test(tc, lower_hex_long);
    tcase_add_test(tc, lower_hex_longlong);
    tcase_add_test(tc, lower_hex_2x);
    tcase_add_test(tc, lower_hex_star);
    tcase_add_test(tc, lower_hex_nohex);
    tcase_add_test(tc, lower_hex_lower);
    tcase_add_test(tc, lower_hex_sign);
    tcase_add_test(tc, lower_hex_len);

    tcase_add_test(tc, octal_base_version);
    tcase_add_test(tc, octal_overflow);
    tcase_add_test(tc, octal_0x);
    tcase_add_test(tc, octal_0X);
    tcase_add_test(tc, octal_empty);
    tcase_add_test(tc, octal_fail);
    tcase_add_test(tc, octal_spaces_tabs_sns);
    tcase_add_test(tc, octal_short);
    tcase_add_test(tc, octal_long);
    tcase_add_test(tc, octal_longlong);
    tcase_add_test(tc, octal_2x);
    tcase_add_test(tc, octal_star);
    tcase_add_test(tc, octal_nohex);
    tcase_add_test(tc, octal_lower);
    tcase_add_test(tc, octal_sign);
    tcase_add_test(tc, octal_len);

    tcase_add_test(tc, pointer1);
    tcase_add_test(tc, pointer2);
    tcase_add_test(tc, pointer3);
    tcase_add_test(tc, pointer4);

    tcase_add_test(tc, buff1);
    tcase_add_test(tc, buff2);
    tcase_add_test(tc, buff3);

    tcase_add_test(tc, perc1);
    tcase_add_test(tc, perc2);
    tcase_add_test(tc, perc3);

    tcase_add_test(tc, perc3);
    tcase_add_test(tc, perc4);
    tcase_add_test(tc, perc5);

    tcase_add_test(tc, mixed_ptrs1);
    tcase_add_test(tc, mixed_ptrs2);
    tcase_add_test(tc, mixed_ptrs3);
    tcase_add_test(tc, mixed_ptrs4);
    tcase_add_test(tc, mixed_ptrs5);

    // Hard mixed tests

    tcase_add_test(tc, hard1);
    tcase_add_test(tc, hard3);
    tcase_add_test(tc, hard4);
    tcase_add_test(tc, hard5);

    suite_add_tcase(s, tc);

    return s;
}
