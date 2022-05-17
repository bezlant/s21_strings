#include "s21_string.h"

static int s21_includes_exponent(const char *buffer);
static long double s21_atof(const char *buffer);
static long double s21_apply_exponent(long double res, const char *buffer);
static int s21_case_insens_search(const char *buff, const char *pat);
static int s21_includes_inf_nan(const char *buffer);
static long double s21_return_nan_inf(const char *buffer);

long double s21_strtold(const char *buffer) {
    long double res = 0.0;
    int includes_inf_nan = s21_includes_inf_nan(buffer);

    if (!includes_inf_nan) {
        res = s21_atof(buffer);

        if (s21_includes_exponent(buffer)) {
            res = s21_apply_exponent(res, buffer);
        }
    }

    return (includes_inf_nan) ? s21_return_nan_inf(buffer) : res;
}

static int s21_case_insens_search(const char *buff, const char *pat) {
    int found = 0;
    int len = (int)s21_strlen(pat);

    for (int i = 0; buff[i] && !found; i++) {
        int counter = 0;
        for (int j = 0; j < len; j++) {
            if ((buff[i] == (pat[j] - 'A') + 'a') ||
                (buff[i] == (pat[j] - 'a') + 'A') ||
                pat[j] == buff[i]) {
                counter++;
                i++;
            }

            if (len == counter) {
                found = 1;
                break;
            }
        }
    }

    return found;
}

static int s21_includes_inf_nan(const char *buffer) {
    int res = 0;

    int test1 = s21_case_insens_search(buffer, "inf");
    int test2 = s21_case_insens_search(buffer, "nan");

    if (test1 || test2) {
        res = 1;
    }

    return res;
}

static long double s21_return_nan_inf(const char *buffer) {
    int res = 0;

    for (int i = 0; buffer[i]; i++) {
        if (buffer[i] == 'i' || buffer[i] == 'I') {
            res = 1;
            break;
        }

        if (buffer[i] == 'n' || buffer[i] == 'N') {
            res = 2;
            break;
        }
    }

    return (res == 1) ? INFINITY : NAN;
}

/**
 * @brief Searches for exponent notation in string buffer and applies found exponent to res.
 * In case of any errors sets res to 0.
 *
 * @param res - Target for exponent
 * @param buffer - String contatining exponent
 * @return long double - Res after exponentiation
 */

static long double s21_apply_exponent(long double res, const char *buffer) {
    char sign = '+';
    int expon = 0;

    for (char *p = (char *)buffer; *p; p++) {
        if (*p == 'e' || *p == 'E') {
            sign = *(p + 1);
            expon = s21_atoi(p + 2);
        }
    }

    while (expon) {
        if (sign == '-') {
            res /= 10.0;
        } else {
            res *= 10.0;
        }
        expon--;
    }

    return res;
}

/**
 * @brief Returns true/false if input str includes scientific notation symbols, such as
 * Inf, NAN, e
 * @arg Buffer - pointer to string
 * @return bool
 */

static int s21_includes_exponent(const char *buffer) {
    int res = 0;

    for (char *p = (char *)buffer; *p; p++) {
        if (s21_strspn(p, "eE")) {
            res = 1;
            break;
        }
    }

    return res;
}

static long double s21_atof(const char *buffer) {
    long double frac = 0.0;
    char *p = (char *)buffer;
    int minus_flag = (*p == '-');
    if (*p == '-' || *p == '+')
        p++;

    long double res = s21_atoi(p);

    while (s21_isdigit(*p))
        p++;

    if (*p == '.') {
        p++;
        // (!) Important step for correct parsing of 123.000001
        int trailing_zeros = s21_strspn(p, "0");
        // (!) Atoi discards trailing zeros (BUG: 123.00001 == 123.1)
        frac = s21_atoi(p);
        int tmp = (int)frac;
        while (tmp) {
            frac /= 10.0;
            tmp /= 10;
        }
        while (trailing_zeros) {
            frac /= 10.0;
            trailing_zeros--;
        }
    }

    res += frac;

    return minus_flag ? -res : res;
}
