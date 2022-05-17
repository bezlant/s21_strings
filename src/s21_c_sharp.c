#include "s21_string.h"

/**
 * @brief Returns a copy of string (str) converted to uppercase. In case of any
 * error, return S21_NULL.
 * @warning This function uses malloc, thus free is required from the user.
 * @param str - str to produce uppercase copy of.
 * @return pointer to the newly created string.
 */

void *s21_to_upper(const char *str) {
    char *str_copy = S21_NULL;

    if (str != S21_NULL) {
        s21_size_t len = s21_strlen(str);

        str_copy = (char *)malloc(sizeof(char) * (len + 1));

        if (str_copy) {
            for (s21_size_t i = 0; i <= len; i++) {
                if (str[i] >= 'a' && str[i] <= 'z') {
                    str_copy[i] = (str[i] - 'a') + 'A';
                } else {
                    str_copy[i] = str[i];
                }
            }
            str_copy[len] = '\0';
        }
    }

    return str_copy;
}

/**
 * @brief Returns a copy of string (str) converted to lowercase. In case of any
 * error, return S21_NULL.
 * @warning This function uses malloc, thus free is required from the user.
 * @param str - str to produce lowercase copy of.
 * @return pointer to the newly created string.
 */

void *s21_to_lower(const char *str) {
    char *str_copy = S21_NULL;

    if (str != S21_NULL) {
        s21_size_t len = s21_strlen(str);

        str_copy = (char *)malloc(sizeof(char) * (len + 1));

        if (str_copy) {
            for (s21_size_t i = 0; i <= len; i++) {
                if (str[i] >= 'A' && str[i] <= 'Z') {
                    str_copy[i] = (str[i] - 'A') + 'a';
                } else {
                    str_copy[i] = str[i];
                }
            }
            str_copy[len] = '\0';
        }
    }

    return str_copy;
}

/**
 * @brief Returns a new string in which a specified string (str) is inserted at
 * a specified index position (start_index) in the given string (src). In case
 * of any error, return S21_NULL
 * @warning If start_index is greater than str_len, this is considered as error.
 * S21_NULL will be returned.
 * @warning Malloc is used, free required from the user.
 *
 * @param src String to be inserted.
 * @param str Target of insertion.
 * @param start_index Starting index of insertion of src into target.
 * @return void* pointer to the new merged string
 */

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
    char *res = S21_NULL;

    if (src != S21_NULL && str != S21_NULL) {
        s21_size_t src_len = s21_strlen(src);
        s21_size_t str_len = s21_strlen(str);
        s21_size_t new_len = src_len + str_len;

        res = calloc(new_len + 1, sizeof(char));

        if (res) {
            for (s21_size_t i = 0, j = 0, m = 0; i < new_len; i++) {
                if (i < start_index || !str[m])
                    res[i] = src[j++];
                else
                    res[i] = str[m++];
            }
            res[new_len] = '\0';
        }
    } else if (str == S21_NULL && src != S21_NULL) {
        res = calloc(s21_strlen(src) + 1, sizeof(char));
        s21_strcpy(res, src);
    }
    return res;
}

/**
 * @brief Returns a new string in which all leading and trailing occurrences of
 * a set of specified characters (trim_chars) from the given string (src) are
 * removed. In case of any error, return S21_NULL
 * @warning Function allocates memory, user is assumed to free.
 *
 * @param src Target of trimming.
 * @param trim_chars Chars to be trimmed from the src.
 * @return void* Pointer to the new string with trimmed chars.
 */

void *s21_trim(const char *src, const char *trim_chars) {
    char *res = S21_NULL;

    if (src) {
        if (trim_chars && *trim_chars) {
            s21_size_t len = s21_strlen(src);
            s21_size_t chars_len = s21_strlen(trim_chars);

            s21_trim_left(&src, trim_chars, &len, chars_len);
            if (len)
                s21_trim_right(&src, trim_chars, &len, chars_len);

            res = (char *)malloc(sizeof(char) * (len + 1));

            if (res) {
                for (s21_size_t i = 0; i < len + 1; i++) {
                    if (i < len) {
                        res[i] = src[i];
                    } else {
                        res[i] = '\0';
                    }
                }
            }
        } else {
            res = s21_trim(src, " \t\n");
        }
    }

    return res;
}

void s21_trim_left(const char **src, const char *trim_chars,
                   s21_size_t *src_len, const s21_size_t trim_chars_len) {
    s21_size_t m = 0;

    while (src && m != trim_chars_len) {
        if ((**src) == trim_chars[m]) {
            (*src)++;
            (*src_len) -= 1;
            m = 0;
            continue;
        }
        m++;
    }
}

void s21_trim_right(const char **src, const char *trim_chars,
                    s21_size_t *src_len, const s21_size_t trim_chars_len) {
    s21_size_t m = 0;
    s21_size_t i = (*src_len) - 1;

    while (src && m != trim_chars_len) {
        if ((*src)[i] == trim_chars[m]) {
            i--;
            (*src_len)--;
            m = 0;
            continue;
        }

        m++;
    }
}
