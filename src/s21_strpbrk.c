#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
    char *res = S21_NULL;

    for (const char *a = str1; *a; a++) {
        for (const char *b = str2; *b; b++) {
            if (*a == *b) {
                res = (char *)a;
                break;
            }
        }

        if (res) {
            break;
        }
    }

    return res;
}
