#include "../tests_includes/s21_tests.h"

START_TEST(Doubles1) {
    long double a1 = 1, b1 = 2, d1 = 3, c1 = 4;
    long double a2 = 5, b2 = 6, d2 = 7, c2 = 8;

    const char str1[] = "5.0000123";
    const char str2[] = "3.11";
    const char str3[] = "0.11123";
    const char str4[] = "777.123456001";

    a1 = s21_strtold(str1);
    a2 = strtold(str1, NULL);

    b1 = s21_strtold(str2);
    b2 = strtold(str2, NULL);

    c1 = s21_strtold(str3);
    c2 = strtold(str3, NULL);

    d1 = s21_strtold(str4);
    d2 = strtold(str4, NULL);

    ck_assert_double_eq_tol(a1, a2, 0.0000001);

    ck_assert_double_eq_tol(b1, b2, 0.00001);
    ck_assert_double_eq_tol(c1, c2, 0.00001);
    ck_assert_double_eq_tol(d1, d2, 0.00001);
}
END_TEST

START_TEST(Doubles2) {
    long double a1 = 1, b1 = 2, d1 = 3, c1 = 4;
    long double a2 = 5, b2 = 6, d2 = 7, c2 = 8;

    const char str1[] = "0.123";
    const char str2[] = "0.00001";
    const char str3[] = "35.4444";
    const char str4[] = "133.000";

    a1 = s21_strtold(str1);
    a2 = strtold(str1, NULL);

    b1 = s21_strtold(str2);
    b2 = strtold(str2, NULL);

    c1 = s21_strtold(str3);
    c2 = strtold(str3, NULL);

    d1 = s21_strtold(str4);
    d2 = strtold(str4, NULL);

    ck_assert_double_eq_tol(a1, a2, 0.00001);
    ck_assert_double_eq_tol(b1, b2, 0.00001);
    ck_assert_double_eq_tol(c1, c2, 0.00001);
    ck_assert_double_eq_tol(d1, d2, 0.00001);
}
END_TEST

START_TEST(Doubles3) {
    long double a1 = 1, b1 = 2, d1 = 3, c1 = 4;
    long double a2 = 5, b2 = 6, d2 = 7, c2 = 8;

    const char str1[] = "777";
    const char str2[] = "4.051235";
    const char str3[] = "1.5";
    const char str4[] = "123.36666";

    a1 = s21_strtold(str1);
    a2 = strtold(str1, NULL);

    b1 = s21_strtold(str2);
    b2 = strtold(str2, NULL);

    c1 = s21_strtold(str3);
    c2 = strtold(str3, NULL);

    d1 = s21_strtold(str4);
    d2 = strtold(str4, NULL);

    ck_assert_double_eq_tol(a1, a2, 0.00001);
    ck_assert_double_eq_tol(b1, b2, 0.00001);
    ck_assert_double_eq_tol(c1, c2, 0.00001);
    ck_assert_double_eq_tol(d1, d2, 0.00001);
}
END_TEST

START_TEST(Doubles4) {
    long double a1 = 1, b1 = 2, d1 = 3, c1 = 4;
    long double a2 = 5, b2 = 6, d2 = 7, c2 = 8;

    const char str1[] = "5.12";
    const char str2[] = "1.11";
    const char str3[] = ".";
    const char str4[] = "1";

    a1 = s21_strtold(str1);
    a2 = strtold(str1, NULL);

    b1 = s21_strtold(str2);
    b2 = strtold(str2, NULL);

    c1 = s21_strtold(str3);
    c2 = strtold(str3, NULL);

    d1 = s21_strtold(str4);
    d2 = strtold(str4, NULL);

    ck_assert_double_eq_tol(a1, a2, 0.00001);
    ck_assert_double_eq_tol(b1, b2, 0.00001);
    ck_assert_double_eq_tol(c1, c2, 0.00001);
    ck_assert_double_eq_tol(d1, d2, 0.00001);
}
END_TEST

START_TEST(expon1) {
    long double a1 = 1, b1 = 2, d1 = 3, c1 = 4;
    long double a2 = 5, b2 = 6, d2 = 7, c2 = 8;

    const char str1[] = "10e-4";
    const char str2[] = "1.5e+2";
    const char str3[] = "5.123e-3";
    const char str4[] = "17.5812e+2";

    a1 = s21_strtold(str1);
    a2 = strtold(str1, NULL);

    b1 = s21_strtold(str2);
    b2 = strtold(str2, NULL);

    c1 = s21_strtold(str3);
    c2 = strtold(str3, NULL);

    d1 = s21_strtold(str4);
    d2 = strtold(str4, NULL);

    ck_assert_double_eq_tol(a1, a2, 0.00001);
    ck_assert_double_eq_tol(b1, b2, 0.00001);
    ck_assert_double_eq_tol(c1, c2, 0.00001);
    ck_assert_double_eq_tol(d1, d2, 0.00001);
}
END_TEST

START_TEST(expon2) {
    long double a1 = 1, b1 = 2, d1 = 3, c1 = 4;
    long double a2 = 5, b2 = 6, d2 = 7, c2 = 8;

    const char str1[] = "512.0e-0";
    const char str2[] = "90931.3e-4";
    const char str3[] = "51123.1e-3";
    const char str4[] = "0.123123e+5";

    a1 = s21_strtold(str1);
    a2 = strtold(str1, NULL);

    b1 = s21_strtold(str2);
    b2 = strtold(str2, NULL);

    c1 = s21_strtold(str3);
    c2 = strtold(str3, NULL);

    d1 = s21_strtold(str4);
    d2 = strtold(str4, NULL);

    ck_assert_double_eq_tol(a1, a2, 0.00001);
    ck_assert_double_eq_tol(b1, b2, 0.00001);
    ck_assert_double_eq_tol(c1, c2, 0.00001);
    ck_assert_double_eq_tol(d1, d2, 0.00001);
}
END_TEST

START_TEST(expon3) {
    long double a1 = 1, b1 = 2, d1 = 3, c1 = 4;
    long double a2 = 5, b2 = 6, d2 = 7, c2 = 8;

    const char str1[] = "1243.2e-2";
    const char str2[] = "7887e-4";
    const char str3[] = "1230";
    const char str4[] = "1230";

    a1 = s21_strtold(str1);
    a2 = strtold(str1, NULL);

    b1 = s21_strtold(str2);
    b2 = strtold(str2, NULL);

    c1 = s21_strtold(str3);
    c2 = strtold(str3, NULL);

    d1 = s21_strtold(str4);
    d2 = strtold(str4, NULL);

    ck_assert_double_eq_tol(a1, a2, 0.00001);
    ck_assert_double_eq_tol(b1, b2, 0.00001);
    ck_assert_double_eq_tol(c1, c2, 0.00001);
    ck_assert_double_eq_tol(d1, d2, 0.00001);
}
END_TEST

START_TEST(expon4) {
    long double a1 = 1, b1 = 2, d1 = 3, c1 = 4;
    long double a2 = 5, b2 = 6, d2 = 7, c2 = 8;

    const char str1[] = "4123e-1";
    const char str2[] = "61234e-5";
    const char str3[] = "41.3e-3";
    const char str4[] = "111e-3";

    a1 = s21_strtold(str1);
    a2 = strtold(str1, NULL);

    b1 = s21_strtold(str2);
    b2 = strtold(str2, NULL);

    c1 = s21_strtold(str3);
    c2 = strtold(str3, NULL);

    d1 = s21_strtold(str4);
    d2 = strtold(str4, NULL);

    ck_assert_double_eq_tol(a1, a2, 0.00001);
    ck_assert_double_eq_tol(b1, b2, 0.00001);
    ck_assert_double_eq_tol(c1, c2, 0.00001);
    ck_assert_double_eq_tol(d1, d2, 0.00001);
}
END_TEST

START_TEST(inf_nan1) {
    long double a1 = 1, b1 = 2, d1 = 3, c1 = 4;
    long double a2 = 5, b2 = 6, d2 = 7, c2 = 8;

    const char str1[] = "Inf";
    const char str2[] = "naN";
    const char str3[] = "inf";
    const char str4[] = "nan";

    a1 = s21_strtold(str1);
    a2 = strtold(str1, NULL);

    b1 = s21_strtold(str2);
    b2 = strtold(str2, NULL);

    c1 = s21_strtold(str3);
    c2 = strtold(str3, NULL);

    d1 = s21_strtold(str4);
    d2 = strtold(str4, NULL);

    ck_assert_ldouble_infinite(a1);
    ck_assert_ldouble_infinite(a2);

    ck_assert_ldouble_infinite(c1);
    ck_assert_ldouble_infinite(c2);

    ck_assert_ldouble_nan(b1);
    ck_assert_ldouble_nan(b2);

    ck_assert_ldouble_nan(d1);
    ck_assert_ldouble_nan(d2);
}
END_TEST

START_TEST(inf_nan2) {
    long double a1 = 1, b1 = 2, d1 = 3, c1 = 4;
    long double a2 = 5, b2 = 6, d2 = 7, c2 = 8;

    const char str1[] = "nAn";
    const char str2[] = "inf";
    const char str3[] = "NAN";
    const char str4[] = "INF";

    a1 = s21_strtold(str1);
    a2 = strtold(str1, NULL);

    b1 = s21_strtold(str2);
    b2 = strtold(str2, NULL);

    c1 = s21_strtold(str3);
    c2 = strtold(str3, NULL);

    d1 = s21_strtold(str4);
    d2 = strtold(str4, NULL);

    ck_assert_ldouble_infinite(b1);
    ck_assert_ldouble_infinite(b2);

    ck_assert_ldouble_infinite(d1);
    ck_assert_ldouble_infinite(d2);

    ck_assert_ldouble_nan(a1);
    ck_assert_ldouble_nan(a2);

    ck_assert_ldouble_nan(c1);
    ck_assert_ldouble_nan(c2);
}
END_TEST

START_TEST(inf_nan3) {
    long double a1 = 1, b1 = 2, d1 = 3, c1 = 4;
    long double a2 = 5, b2 = 6, d2 = 7, c2 = 8;

    const char str1[] = "inf";
    const char str2[] = "NAN";
    const char str3[] = "nan";
    const char str4[] = "INFFF";

    a1 = s21_strtold(str1);
    a2 = strtold(str1, NULL);

    b1 = s21_strtold(str2);
    b2 = strtold(str2, NULL);

    c1 = s21_strtold(str3);
    c2 = strtold(str3, NULL);

    d1 = s21_strtold(str4);
    d2 = strtold(str4, NULL);

    ck_assert_ldouble_infinite(a1);
    ck_assert_ldouble_infinite(a2);

    ck_assert_ldouble_infinite(d1);
    ck_assert_ldouble_infinite(d2);

    ck_assert_ldouble_nan(b1);
    ck_assert_ldouble_nan(b2);

    ck_assert_ldouble_nan(c1);
    ck_assert_ldouble_nan(c2);
}
END_TEST

START_TEST(inf_nan4) {
    long double a1 = 1, b1 = 2, d1 = 3, c1 = 4;
    long double a2 = 5, b2 = 6, d2 = 7, c2 = 8;

    const char str1[] = "NAN";
    const char str2[] = "NAN";
    const char str3[] = "naN";
    const char str4[] = "Inf";

    a1 = s21_strtold(str1);
    a2 = strtold(str1, NULL);

    b1 = s21_strtold(str2);
    b2 = strtold(str2, NULL);

    c1 = s21_strtold(str3);
    c2 = strtold(str3, NULL);

    d1 = s21_strtold(str4);
    d2 = strtold(str4, NULL);

    ck_assert_ldouble_nan(a1);
    ck_assert_ldouble_nan(a2);
    ck_assert_ldouble_nan(b1);
    ck_assert_ldouble_nan(b2);
    ck_assert_ldouble_nan(c1);
    ck_assert_ldouble_nan(c2);

    ck_assert_ldouble_infinite(d1);
    ck_assert_ldouble_infinite(d2);
}
END_TEST

START_TEST(Mixed1) {
    long double a1 = 1, b1 = 2, d1 = 3, c1 = 4;
    long double a2 = 5, b2 = 6, d2 = 7, c2 = 8;

    const char str1[] = "888.1234";
    const char str2[] = "-4.14135";
    const char str3[] = "+112.0001";
    const char str4[] = "513.41";

    a1 = s21_strtold(str1);
    a2 = strtold(str1, NULL);

    b1 = s21_strtold(str2);
    b2 = strtold(str2, NULL);

    c1 = s21_strtold(str3);
    c2 = strtold(str3, NULL);

    d1 = s21_strtold(str4);
    d2 = strtold(str4, NULL);

    ck_assert_double_eq_tol(a1, a2, 0.00001);
    ck_assert_double_eq_tol(b1, b2, 0.00001);
    ck_assert_double_eq_tol(c1, c2, 0.00001);
    ck_assert_double_eq_tol(d1, d2, 0.00001);
}
END_TEST

START_TEST(Mixed2) {
    long double a1 = 1, b1 = 2, d1 = 3, c1 = 4;
    long double a2 = 5, b2 = 6, d2 = 7, c2 = 8;

    const char str1[] = "+2.0001";
    const char str2[] = "1.4441";
    const char str3[] = "0.444e-5";
    const char str4[] = "-3.31e-4";

    a1 = s21_strtold(str1);
    a2 = strtold(str1, NULL);

    b1 = s21_strtold(str2);
    b2 = strtold(str2, NULL);

    c1 = s21_strtold(str3);
    c2 = strtold(str3, NULL);

    d1 = s21_strtold(str4);
    d2 = strtold(str4, NULL);

    ck_assert_double_eq_tol(a1, a2, 0.00001);
    ck_assert_double_eq_tol(b1, b2, 0.00001);
    ck_assert_double_eq_tol(c1, c2, 0.00001);
    ck_assert_double_eq_tol(d1, d2, 0.00001);
}
END_TEST

START_TEST(Mixed3) {
    long double a1 = 1, b1 = 2, d1 = 3, c1 = 4;
    long double a2 = 5, b2 = 6, d2 = 7, c2 = 8;

    const char str1[] = "inf";
    const char str2[] = "1.31e+4";
    const char str3[] = "+0.444e-5";
    const char str4[] = "-0.444e-5";

    a1 = s21_strtold(str1);
    a2 = strtold(str1, NULL);

    b1 = s21_strtold(str2);
    b2 = strtold(str2, NULL);

    c1 = s21_strtold(str3);
    c2 = strtold(str3, NULL);

    d1 = s21_strtold(str4);
    d2 = strtold(str4, NULL);


    ck_assert_ldouble_infinite(a1);
    ck_assert_ldouble_infinite(a2);

    ck_assert_double_eq_tol(b1, b2, 0.00001);
    ck_assert_double_eq_tol(c1, c2, 0.00001);
    ck_assert_double_eq_tol(d1, d2, 0.00001);
}
END_TEST

START_TEST(Mixed4) {
    long double a1 = 1, b1 = 2, d1 = 3, c1 = 4;
    long double a2 = 5, b2 = 6, d2 = 7, c2 = 8;

    const char str1[] = "0.00001";
    const char str2[] = "-4123123";
    const char str3[] = "4.";
    const char str4[] = ".";

    a1 = s21_strtold(str1);
    a2 = strtold(str1, NULL);

    b1 = s21_strtold(str2);
    b2 = strtold(str2, NULL);

    c1 = s21_strtold(str3);
    c2 = strtold(str3, NULL);

    d1 = s21_strtold(str4);
    d2 = strtold(str4, NULL);

    ck_assert_double_eq_tol(a1, a2, 0.00001);
    ck_assert_double_eq_tol(b1, b2, 0.00001);
    ck_assert_double_eq_tol(c1, c2, 0.00001);
    ck_assert_double_eq_tol(d1, d2, 0.00001);
}
END_TEST

START_TEST(Mixed5) {
    long double a1 = 1, b1 = 2, d1 = 3, c1 = 4;
    long double a2 = 5, b2 = 6, d2 = 7, c2 = 8;

    const char str1[] = "-9.4";
    const char str2[] = "+49.410e-3";
    const char str3[] = "-1.3";
    const char str4[] = "123.5";

    a1 = s21_strtold(str1);
    a2 = strtold(str1, NULL);

    b1 = s21_strtold(str2);
    b2 = strtold(str2, NULL);

    c1 = s21_strtold(str3);
    c2 = strtold(str3, NULL);

    d1 = s21_strtold(str4);
    d2 = strtold(str4, NULL);

    ck_assert_double_eq_tol(a1, a2, 0.00001);
    ck_assert_double_eq_tol(b1, b2, 0.00001);
    ck_assert_double_eq_tol(c1, c2, 0.00001);
    ck_assert_double_eq_tol(d1, d2, 0.00001);
}
END_TEST

START_TEST(Mixed6) {
    long double a1 = 1, b1 = 2, d1 = 3, c1 = 4;
    long double a2 = 5, b2 = 6, d2 = 7, c2 = 8;

    const char str1[] = "999.31";
    const char str2[] = "-31";
    const char str3[] = "-0.0003e+5";
    const char str4[] = "4.1";

    a1 = s21_strtold(str1);
    a2 = strtold(str1, NULL);

    b1 = s21_strtold(str2);
    b2 = strtold(str2, NULL);

    c1 = s21_strtold(str3);
    c2 = strtold(str3, NULL);

    d1 = s21_strtold(str4);
    d2 = strtold(str4, NULL);

    ck_assert_double_eq_tol(a1, a2, 0.00001);
    ck_assert_double_eq_tol(b1, b2, 0.00001);
    ck_assert_double_eq_tol(c1, c2, 0.00001);
    ck_assert_double_eq_tol(d1, d2, 0.00001);
}
END_TEST

START_TEST(Mixed7) {
    long double a1 = 1, b1 = 2, d1 = 3, c1 = 4;
    long double a2 = 5, b2 = 6, d2 = 7, c2 = 8;

    const char str1[] = "123.5";
    const char str2[] = "-555.1";
    const char str3[] = "0.4";
    const char str4[] = "5.1";

    a1 = s21_strtold(str1);
    a2 = strtold(str1, NULL);

    b1 = s21_strtold(str2);
    b2 = strtold(str2, NULL);

    c1 = s21_strtold(str3);
    c2 = strtold(str3, NULL);

    d1 = s21_strtold(str4);
    d2 = strtold(str4, NULL);

    ck_assert_double_eq_tol(a1, a2, 0.00001);
    ck_assert_double_eq_tol(b1, b2, 0.00001);
    ck_assert_double_eq_tol(c1, c2, 0.00001);
    ck_assert_double_eq_tol(d1, d2, 0.00001);
}
END_TEST

START_TEST(Mixed8) {
    long double a1 = 1, b1 = 2, d1 = 3, c1 = 4;
    long double a2 = 5, b2 = 6, d2 = 7, c2 = 8;

    const char str1[] = "-999.1";
    const char str2[] = "NAN";
    const char str3[] = "-0.00001";
    const char str4[] = "0";

    a1 = s21_strtold(str1);
    a2 = strtold(str1, NULL);

    b1 = s21_strtold(str2);
    b2 = strtold(str2, NULL);

    c1 = s21_strtold(str3);
    c2 = strtold(str3, NULL);

    d1 = s21_strtold(str4);
    d2 = strtold(str4, NULL);

    ck_assert_ldouble_nan(b1);
    ck_assert_ldouble_nan(b2);


    ck_assert_double_eq_tol(a1, a2, 0.00001);
    ck_assert_double_eq_tol(c1, c2, 0.00001);

    ck_assert_double_eq_tol(d1, d2, 0.00001);
}
END_TEST

START_TEST(Mixed9) {
    long double a1 = 1, b1 = 2, d1 = 3, c1 = 4;
    long double a2 = 5, b2 = 6, d2 = 7, c2 = 8;

    const char str1[] = "1234.4";
    const char str2[] = "555.1";
    const char str3[] = "6.001";
    const char str4[] = "6.11234";

    a1 = s21_strtold(str1);
    a2 = strtold(str1, NULL);

    b1 = s21_strtold(str2);
    b2 = strtold(str2, NULL);

    c1 = s21_strtold(str3);
    c2 = strtold(str3, NULL);

    d1 = s21_strtold(str4);
    d2 = strtold(str4, NULL);

    ck_assert_double_eq_tol(a1, a2, 0.00001);
    ck_assert_double_eq_tol(b1, b2, 0.00001);
    ck_assert_double_eq_tol(c1, c2, 0.00001);
    ck_assert_double_eq_tol(d1, d2, 0.00001);
}
END_TEST

START_TEST(Mixed10) {
    long double a1 = 1, b1 = 2, d1 = 3, c1 = 4;
    long double a2 = 5, b2 = 6, d2 = 7, c2 = 8;

    const char str1[] = "61234";
    const char str2[] = "4";
    const char str3[] = "8888.1";
    const char str4[] = "40000";

    a1 = s21_strtold(str1);
    a2 = strtold(str1, NULL);

    b1 = s21_strtold(str2);
    b2 = strtold(str2, NULL);

    c1 = s21_strtold(str3);
    c2 = strtold(str3, NULL);

    d1 = s21_strtold(str4);
    d2 = strtold(str4, NULL);

    ck_assert_double_eq_tol(a1, a2, 0.00001);
    ck_assert_double_eq_tol(b1, b2, 0.00001);
    ck_assert_double_eq_tol(c1, c2, 0.00001);
    ck_assert_double_eq_tol(d1, d2, 0.00001);
}
END_TEST

START_TEST(Mixed11) {
    long double a1 = 1, b1 = 2, d1 = 3, c1 = 4;
    long double a2 = 5, b2 = 6, d2 = 7, c2 = 8;

    const char str1[] = "-1";
    const char str2[] = "-1.4e-6";
    const char str3[] = "+3.1e+3";
    const char str4[] = "5.4";

    a1 = s21_strtold(str1);
    a2 = strtold(str1, NULL);

    b1 = s21_strtold(str2);
    b2 = strtold(str2, NULL);

    c1 = s21_strtold(str3);
    c2 = strtold(str3, NULL);

    d1 = s21_strtold(str4);
    d2 = strtold(str4, NULL);

    ck_assert_double_eq_tol(a1, a2, 0.00001);
    ck_assert_double_eq_tol(b1, b2, 0.00001);
    ck_assert_double_eq_tol(c1, c2, 0.00001);
    ck_assert_double_eq_tol(d1, d2, 0.00001);
}
END_TEST

START_TEST(Mixed12) {
    long double a1 = 1, b1 = 2, d1 = 3, c1 = 4;
    long double a2 = 5, b2 = 6, d2 = 7, c2 = 8;

    const char str1[] = "5e-4";
    const char str2[] = "0.3e-1";
    const char str3[] = "94.881e+1";
    const char str4[] = "54";

    a1 = s21_strtold(str1);
    a2 = strtold(str1, NULL);

    b1 = s21_strtold(str2);
    b2 = strtold(str2, NULL);

    c1 = s21_strtold(str3);
    c2 = strtold(str3, NULL);

    d1 = s21_strtold(str4);
    d2 = strtold(str4, NULL);

    ck_assert_double_eq_tol(a1, a2, 0.00001);
    ck_assert_double_eq_tol(b1, b2, 0.00001);
    ck_assert_double_eq_tol(c1, c2, 0.00001);
    ck_assert_double_eq_tol(d1, d2, 0.00001);
}
END_TEST

Suite *suite_strtold(void) {
    Suite *s = suite_create("suite_strtold");
    TCase *tc = tcase_create("strtold_tc");

    // Doubles

    tcase_add_test(tc, Doubles1);
    tcase_add_test(tc, Doubles2);
    tcase_add_test(tc, Doubles3);
    tcase_add_test(tc, Doubles4);

    // Doubles with expon (e)

    tcase_add_test(tc, expon1);
    tcase_add_test(tc, expon2);
    tcase_add_test(tc, expon3);
    tcase_add_test(tc, expon4);

    // // Infinity, Nan

    tcase_add_test(tc, inf_nan1);
    tcase_add_test(tc, inf_nan2);
    tcase_add_test(tc, inf_nan3);
    tcase_add_test(tc, inf_nan4);

    // // Mixed

    tcase_add_test(tc, Mixed1);
    tcase_add_test(tc, Mixed2);
    tcase_add_test(tc, Mixed3);
    tcase_add_test(tc, Mixed4);
    tcase_add_test(tc, Mixed5);
    tcase_add_test(tc, Mixed6);
    tcase_add_test(tc, Mixed7);
    tcase_add_test(tc, Mixed8);
    tcase_add_test(tc, Mixed9);
    tcase_add_test(tc, Mixed10);
    tcase_add_test(tc, Mixed11);
    tcase_add_test(tc, Mixed12);

    suite_add_tcase(s, tc);
    return s;
}
