#include "s21_string.h"

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
    s21_memset(dest, '\0', n);

    for (s21_size_t i = 0; i < n && src[i]; i++) {
        dest[i] = src[i];
    }

    return dest;
}
