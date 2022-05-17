#include "s21_string.h"

/**
 * @brief Finds the next token in a null-terminated byte string pointed to by
 * str. The separator characters are identified by null-terminated byte string
 * pointed to by delim.
 *
 * @warning Strtok mutates source string. CPP docs: "If such character was
 * found, it is replaced by the null character '\0' and the pointer to the
 * following character is stored in a static location for subsequent
 * invocations."
 *
 * @param str String to be tokenized or S21_NULL.
 * @param delim Delimiters of the string.
 * @return char* Next token.
 */

char *s21_strtok(char *str, const char *delim) {
    static int next_null, tok;
    static s21_size_t ind;
    static char *max_ptr;
    static char *addr;

    // We can't initialize static vars to non-const value
    // because static vars are stored in .data section of binary
    if (str) {
        tok = 1;
        ind = 0, next_null = 0;
        addr = str + s21_strspn(str, delim);  // skipping trailing delims, if any;
        max_ptr = str + s21_strlen(str);
    }

    char *res = S21_NULL;

    if (!(addr >= max_ptr || next_null)) {
        int non_delim = 1;
        for (int i = 0; addr[i]; i++) {
            s21_size_t step = s21_strspn(addr + i, delim);
            if (step) {
                non_delim = 0;
                for (s21_size_t j = i; j < i + step; j++) addr[j] = '\0';

                ind = step + i;
                break;
            }
        }

        if (tok == 1 && non_delim) next_null = 1;

        res = addr;   // old start of the string
        addr += ind;  // new start of the new string
    }

    ++tok;
    return res;
}
