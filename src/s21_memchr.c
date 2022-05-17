#include "s21_string.h"

/**
 * @brief Searches within the first num bytes of the block of memory pointed by
ptr for the first occurrence of value (interpreted as an unsigned char), and
returns a pointer to it.
 *
 * @param str Pointer to the block of memory where the search is performed.
 * @param c Value to be located. The value is passed as an int, but the function
performs a byte per byte search using the unsigned char conversion of this
value.
 * @param n Number of bytes to be analyzed.
s21_size_t is an unsigned integral type.
 * @return void* A pointer to the first occurrence of value in the block of
memory pointed by ptr.
 */

void *s21_memchr(const void *str, int c, s21_size_t n) {
    unsigned char *ptr = (unsigned char *)str;
    void *out = S21_NULL;
    for (s21_size_t i = 0; i < n && ptr; i++) {
        if (*ptr == (unsigned char)c) {
            out = ptr;
            break;
        }
        ptr++;
    }
    return out;
}
