#ifndef MY_PRINTF_H_
#define MY_PRINTF_H_

#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <limits.h>

typedef struct printf_context_s {
    va_list args;
} printf_context_t;

typedef int (*flag_func_t)(printf_context_t *, int);

typedef struct flag_s {
    char c;
    flag_func_t function;
} flag_t;

/* my_printf */
int my_printf(const char *format, ...);

/* utilitary_functions */
int my_putchar(char c);
int my_putnbr_base_len(int nb, char const *base);
int my_putnbr_base_unsigned_len(unsigned int nb, char const *base);

/* flags */
int c_flag(printf_context_t *ctx, int precision);
int s_flag(printf_context_t *ctx, int precision);
int d_flag(printf_context_t *ctx, int precision);
int u_flag(printf_context_t *ctx, int precision);
int b_flag(printf_context_t *ctx, int precision);
int o_flag(printf_context_t *ctx, int precision);
int X_flag(printf_context_t *ctx, int precision);
int x_flag(printf_context_t *ctx, int precision);
int mark_flag(printf_context_t *ctx, int precision);
int f_flag(printf_context_t *ctx, int precision);

#endif /* !MY_PRINTF_H_ */
