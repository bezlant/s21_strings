#include "s21_string.h"

// src: ABCDEFG
// dest: ..[CDEFG]
// buf:
// res:

/**
 * @brief Copies n bytes from memory area src to memory area dest. The memory
 * ares may overlap: copying takes place as though the bytes in src are first
 * copied into tmp array that does not overlap src or dest, and then the bytes
 * are then copies from the tmp to dest.
 *
 * @param dest
 * @param src
 * @param n
 * @return void*
 */

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
    char *to = (char *)dest;
    char *from = (char *)src;

    char *tmp = (char *)malloc(sizeof(char) * n);

    if (tmp) {
        s21_memcpy(tmp, from, n);
        s21_memcpy(to, tmp, n);
        free(tmp);
    }
    return dest;
}
