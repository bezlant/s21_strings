#include "s21_string.h"
#ifndef SRC_S21_SSCANF_H_
#define SRC_S21_SSCANF_H_

#if defined(VERBOSE_MODE) && defined(DEBUG)
typedef enum specifier {
    NONE_SPEC,
    CHAR,
    DECIMAL,
    INT,
    SCI_e,
    SCI_E,
    FLOAT,
    SHORT_FLOAT_g,
    SHORT_FLOAT_G,
    UNSIGNED_OCT,
    STR,
    UNSIGNED_DEC_INT,
    UNSIGNED_HEX_x,
    UNSIGNED_HEX_X,
    POINTER_ADDR,
    N_OF_SCANNED_CHARS_UNTIL_N_OCCURS,
    PERCENT_CHAR
} specifier;
#endif

typedef enum width_t { NONE_WIDTH,
                       WIDTH_NUMBER,
                       WIDTH_AST } width_t;

typedef enum length_t {
    NONE_LENGTH,
    LENGTH_SHORT,
    LENGTH_LONG,
    LENGTH_LONG_LONG,
    LENGTH_DOUBLE,
    LENGTH_LONG_DOUBLE
} length_t;

typedef struct token {
    void *addr;  // Address of corresponding vararg pointer
    // %[width][.precision][length][specifier]
    width_t width;
    unsigned int width_n;

    length_t length_t;

    char buff[512];
    char spec;
} token;

int s21_sscanf(const char *str, const char *format, ...);

/* (0) Helper functions */
int check_EOF_string(const char *src);
void write_chars_to_buff(char **str, const char *chars, char *buff,
                         int16_t width, int start_ind);
unsigned long long int s21_strntollu(const char *string, char **endptr,
                                     int basis, int n_byte);
int s21_isspace(char c);
void unsigned_type_converter(token *tok, unsigned long long int result,
                             int sign);
void int_type_converter(token *tok, long long int result, int sign);
void float_type_converter(token *tok, long double result);
int s21_isalpha(char c);

/* (1) Token (rules) parsing stage */
token parse_tokens(char **fstr, va_list *va);
void fstr_parse_width(char **fstr, token *tok);
void fstr_parse_length(char **fstr, token *tok);
void fstr_parse_specifier(char **fstr, token *tok);
int parse_number_from_fstr(char **fstr);

void fstr_parse_buffer(char **fstr, token *tok);
void skip_spaces_in_str(char **src);
void skip_chars_in_buffer(char **src, int *fail, token *tok);

/* (2) Memory writing stage */
void write_tokens_to_memory(char **src, token *tokens, int tok_len, int *res);
void write_char_to_memory(char **str, int *res, token *tok, int *fail);
void write_int_to_memory(char **str, int *fail_flag, int *res, token *tok);
void write_unspec_int_to_memory(char **str, int *fail_flag, int *res,
                                token *tok);
void write_float_to_memory(char **str, int *res, token *tok);
void write_string_to_memory(char **str, const int *fail_flag, int *res, token *tok);
void write_unsigned_to_memory(char **str, int *fail_flag, int *res, token *tok);
void write_hex_or_oct_to_memory(char **str, int *fail_flag, int *res,
                                token *tok, int base);

#endif  // SRC_S21_SSCANF_H_
