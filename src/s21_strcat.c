#include "s21_string.h"

char *s21_strcat(char *dest, const char *src) {
    int dest_len = s21_strlen(dest);
    int i = 0;

    for (; src[i]; i++) {
        dest[dest_len + i] = src[i];
    }

    dest[dest_len + i] = '\0';

    return dest;
}
