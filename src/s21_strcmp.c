#include "s21_string.h"

/**
 * @brief Compares the C string str1 to the C string str2.
 *
 * @param str1 C string to be compared.
 * @param str2 C string to be compared.
 * @return int 0 - the contents of both strings are equal, other code - not
 * equal
 */

int s21_strcmp(const char *str1, const char *str2) {
    int res = 0;

    if (str1 && str2) {
        int i = 0;

        while (str1[i] && str1[i] == str2[i]) {
            i++;
        }

        res = str1[i] - str2[i];
    }

    return res;
}
