#include "s21_string.h"

/**
 * @brief Returns the length of the maximum initial segment (span)
 * of the null-terminated byte string pointed to by @str1,
 * that consists of only the characters found in the null-terminated byte string
 * pointed to by @str2.
 *
 * @param str1 - C string where the search is performed
 * @param str2 - C string what is being searched for
 * @return s21_size_t - returns the length of the maximum initial substring
 * consisting only of str2 characters
 */

s21_size_t s21_strspn(const char *str1, const char *str2) {
    s21_size_t counter = 0;

    for (const char *a = str1; *a; a++) {
        unsigned short was = 0;
        for (const char *b = str2; *b; b++) {
            if (*a == *b) {
                counter++;
                was = 1;
                break;
            }
        }
        if (!was)
            break;
    }
    return counter;
}
