#include "../tests_includes/s21_tests.h"

START_TEST(correct_token_string) {
    char str1[] = "Aboba++Floppa_! Kotya====!Shleppa";
    char str2[] = "Aboba++Floppa_! Kotya====!Shleppa";
    const char delims[] = "+_! =";

    char *got = s21_strtok(str1, delims);
    char *expected = strtok(str2, delims);


    ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
    ck_assert_str_eq(got, expected);


    while (got && expected) {
        got = s21_strtok(NULL, delims);
        expected = strtok(NULL, delims);

        ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));

        if (got || expected) {
            ck_assert_str_eq(got, expected);
        } else {
            ck_assert_ptr_null(got);
            ck_assert_ptr_null(expected);
        }
    }
} END_TEST

START_TEST(hard_token_string) {
    char str1[] = "++Aboba++Floppa_! Kotya===!Shleppa+++ A +";
    char str2[] = "++Aboba++Floppa_! Kotya===!Shleppa+++ A +";
    const char delims[] = "+_! =";

    char *got = s21_strtok(str1, delims);
    char *expected = strtok(str2, delims);

    ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
    ck_assert_str_eq(got, expected);

    while (got && expected) {
        got = s21_strtok(NULL, delims);
        expected = strtok(NULL, delims);

        ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));

        if (got || expected) {
            ck_assert_str_eq(got, expected);
        } else {
            ck_assert_ptr_null(got);
            ck_assert_ptr_null(expected);
        }
    }
} END_TEST

START_TEST(unary_delimiters) {
    char str1[] = "Aboba+Anuroba_Floppa!Kotya_Kekus";
    char str2[] = "Aboba+Anuroba_Floppa!Kotya_Kekus";
    const char delims[] = "+_! =";

    char *got = s21_strtok(str1, delims);
    char *expected = strtok(str2, delims);

    ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
    ck_assert_str_eq(got, expected);

    while (got && expected) {
        got = s21_strtok(NULL, delims);
        expected = strtok(NULL, delims);

        ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));

        if (got || expected) {
            ck_assert_str_eq(got, expected);
        } else {
            ck_assert_ptr_null(got);
            ck_assert_ptr_null(expected);
        }
    }
} END_TEST

START_TEST(no_delims) {
    char str1[] = "AbobaHasNoDelims";
    char str2[] = "AbobaHasNoDelims";
    const char delims[] = "+_! =";

    char *got = s21_strtok(str1, delims);
    char *expected = strtok(str2, delims);

    ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
    ck_assert_str_eq(got, expected);

    while (got && expected) {
        got = s21_strtok(NULL, delims);
        expected = strtok(NULL, delims);


        ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));

        if (got || expected) {
            ck_assert_str_eq(got, expected);
        } else {
            ck_assert_ptr_null(got);
            ck_assert_ptr_null(expected);
        }
    }
} END_TEST

START_TEST(only_delims) {
    char str1[] = "++++++++";
    char str2[] = "++++++++";
    const char delims[] = "+_! =";

    char *got = s21_strtok(str1, delims);
    char *expected = strtok(str2, delims);

    ck_assert_ptr_null(got);
    ck_assert_ptr_null(expected);
} END_TEST


START_TEST(too_many_uses_non_segfault) {
    char str1[] = "Aboba_Floppa_Roba";
    char str2[] = "Aboba_Floppa_Roba";
    const char delims[] = "+_! =";

    char *got = s21_strtok(str1, delims);
    char *expected = strtok(str2, delims);

    ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
    ck_assert_str_eq(got, expected);

    int i = 5;
    while (i) {
        got = s21_strtok(NULL, delims);
        expected = strtok(NULL, delims);
        i--;

        ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));

        if (got || expected) {
            ck_assert_str_eq(got, expected);
        } else {
            ck_assert_ptr_null(got);
            ck_assert_ptr_null(expected);
        }
    }
} END_TEST

START_TEST(even_n_of_delims) {
    char str1[] = "Roba++++Kepa++A++++B__V";
    char str2[] = "Roba++++Kepa++A++++B__V";
    const char delims[] = "+_! =";

    char *got = s21_strtok(str1, delims);
    char *expected = strtok(str2, delims);

    ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
    ck_assert_str_eq(got, expected);

    while (got && expected) {
        got = s21_strtok(NULL, delims);
        expected = strtok(NULL, delims);

        ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));

        if (got || expected) {
            ck_assert_str_eq(got, expected);
        } else {
            ck_assert_ptr_null(got);
            ck_assert_ptr_null(expected);
        }
    }
} END_TEST

START_TEST(odd_n_of_delims) {
    char str1[] = "Aboba__+Floppa_  Roba";
    char str2[] = "Aboba__+Floppa_  Roba";
    const char delims[] = "+_! =";

    char *got = s21_strtok(str1, delims);
    char *expected = strtok(str2, delims);

    ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
    ck_assert_str_eq(got, expected);

    while (got && expected) {
        got = s21_strtok(NULL, delims);
        expected = strtok(NULL, delims);

        ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));

        if (got || expected) {
            ck_assert_str_eq(got, expected);
        } else {
            ck_assert_ptr_null(got);
            ck_assert_ptr_null(expected);
        }
    }
} END_TEST

START_TEST(mixed_n_of_delims) {
    char str1[] = "Aboba__Floppa_+++Roba_Kepa";
    char str2[] = "Aboba__Floppa_+++Roba_Kepa";
    const char delims[] = "+_! =";

    char *got = s21_strtok(str1, delims);
    char *expected = strtok(str2, delims);

    ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
    ck_assert_str_eq(got, expected);

    while (got && expected) {
        got = s21_strtok(NULL, delims);
        expected = strtok(NULL, delims);

        ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));

        if (got || expected) {
            ck_assert_str_eq(got, expected);
        } else {
            ck_assert_ptr_null(got);
            ck_assert_ptr_null(expected);
        }
    }
} END_TEST

START_TEST(hard_mixed) {
    char str1[] = "     Aboba__+ Flo!ppa_   Roba+";
    char str2[] = "     Aboba__+ Flo!ppa_   Roba+";
    const char delims[] = "+_! =";

    char *got = s21_strtok(str1, delims);
    char *expected = strtok(str2, delims);

    ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
    ck_assert_str_eq(got, expected);

    while (got || expected) {
        got = s21_strtok(NULL, delims);
        expected = strtok(NULL, delims);

        ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));

        if (got || expected) {
            ck_assert_str_eq(got, expected);
        } else {
            ck_assert_ptr_null(got);
            ck_assert_ptr_null(expected);
        }
    }
} END_TEST

START_TEST(mixed_hard_incorrect) {
    char str1[] = "!Stepa__ !M!ish a____Anton+An!!!drey";
    char str2[] = "!Stepa__ !M!ish a____Anton+An!!!drey";
    const char delims[] = "+_! =";

    char *got = s21_strtok(str1, delims);
    char *expected = strtok(str2, delims);

    ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
    ck_assert_str_eq(got, expected);

    while (got || expected) {
        got = s21_strtok(NULL, delims);
        expected = strtok(NULL, delims);

        ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));

        if (got || expected) {
            ck_assert_str_eq(got, expected);
        } else {
            ck_assert_ptr_null(got);
            ck_assert_ptr_null(expected);
        }
    }
} END_TEST

START_TEST(very_hard_mixed) {
    char str1[] = "!       A!B!C!D!E!!F!!G";
    char str2[] = "!       A!B!C!D!E!!F!!G";
    const char delims[] = "+_! =";

    char *got = s21_strtok(str1, delims);
    char *expected = strtok(str2, delims);

    ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
    ck_assert_str_eq(got, expected);

    while (got || expected) {
        got = s21_strtok(NULL, delims);
        expected = strtok(NULL, delims);

        if (got || expected) {
            ck_assert_str_eq(got, expected);
            ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
        } else {
            ck_assert_ptr_null(got);
            ck_assert_ptr_null(expected);
        }
    }
} END_TEST



Suite *suite_strtok(void) {
    Suite *s = suite_create("suite_strtok");
    TCase *tc = tcase_create("strtok_tc");

    tcase_add_test(tc, correct_token_string);
    tcase_add_test(tc, hard_token_string);
    tcase_add_test(tc, only_delims);
    tcase_add_test(tc, even_n_of_delims);
    tcase_add_test(tc, odd_n_of_delims);
    tcase_add_test(tc, mixed_n_of_delims);
    tcase_add_test(tc, too_many_uses_non_segfault);
    tcase_add_test(tc, hard_mixed);
    tcase_add_test(tc, mixed_hard_incorrect);
    tcase_add_test(tc, very_hard_mixed);
    tcase_add_test(tc, unary_delimiters);
    tcase_add_test(tc, no_delims);

    suite_add_tcase(s, tc);
    return s;
}
