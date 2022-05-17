#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
    char *res = S21_NULL;
    s21_size_t len = s21_strlen(str);

    for (int i = len; i >= 0; i--) {
        if (str[i] == c) {
            res = ((char *)str) + i;
            break;
        }
    }

    return res;
}
