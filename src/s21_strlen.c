#include "s21_string.h"

/**
 * @brief returns the length of the string
 * @warning S21_NULL str causes UB, possibly SEGFAULT crash
 * @param str string
 * @return s21_size_t length
 */

s21_size_t s21_strlen(const char *str) {
    s21_size_t len = 0;

    if (str) {
        for (int i = 0; str[i]; i++) {
            len++;
        }
    }

    return len;
}
