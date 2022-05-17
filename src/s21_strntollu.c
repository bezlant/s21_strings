#include "s21_string.h"

unsigned long long int s21_strntollu(const char *string, char **endptr,
                                     int basis, int n_byte) {
    unsigned long long res = 0;
    short sign = 1;
    if (endptr)
        *endptr = S21_NULL;
    char dict[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (*string == '-') {
        sign = -1;
        string++;
    }
    if (basis == 16 &&
        (!s21_strncmp(string, "0x", 2) || !s21_strncmp(string, "0X", 2)))
        string += 2;
    long long val;
    short exit = 0;
    while (*string && n_byte && !exit) {
        char *tmp2;
        char current_sim =
            (*string >= 'a' && *string <= 'z') ? *string - 'a' + 'A' : *string;
        tmp2 = s21_strchr(dict, (int)current_sim);
        if (!tmp2) {
            exit = 1;
        } else {
            val = (tmp2 - dict) / sizeof(char);

            if (val >= basis) {
                exit = 1;
            } else {
                res = res * basis + val;
                string++;
                n_byte--;
            }
        }
        if (exit)
            *endptr = (char *)string;
    }
    return res * sign;
}
