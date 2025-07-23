//
// Priax PROJECT
// my_printf.c
// File description:
// my_printf for C
//

#include "my_printf.h"

flag_t *get_flags()
{
    static flag_t flags[] = {
        {'c', &c_flag},
        {'s', &s_flag},
        {'d', &d_flag},
        {'i', &d_flag},
        {'f', &f_flag},
        {'b', &b_flag},
        {'X', &X_flag},
        {'x', &x_flag},
        {'%', &mark_flag},
        {'o', &o_flag},
        {'u', &u_flag},
        {'\0', NULL}
    };
    return flags;
}

static int parse_precision(const char *format, int *index)
{
    int prec = 0, i = *index;

    if (format[i] != '.')
        return -1;
    i++;
    if (format[i] < '0' || format[i] > '9')
        return -1;
    while (format[i] >= '0' && format[i] <= '9') {
        prec = prec * 10 + (format[i] - '0');
        i++;
    }
    *index = i;
    return prec;
}

int check_flag_and_precision(const char *format, int *i, printf_context_t *ctx)
{
    flag_t *flags = get_flags();
    int j = *i + 1;
    int k;
    int precision = -1;
    char flag_char;

    if (format[j] == '.') {
        precision = parse_precision(format, &j);
        if (precision < 0)
            precision = 0;
    }
    flag_char = format[j];
    *i = j;
    for (k = 0; flags[k].c != '\0'; k++) {
        if (flags[k].c == flag_char) {
            return flags[k].function(ctx, precision);
        }
    }
    write(1, "%", 1);
    write(1, &flag_char, 1);
    return 2;
}

int my_printf(const char *format, ...)
{
    int i, len = 0;
    printf_context_t ctx;
    va_start(ctx.args, format);

    for (i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%' && format[i + 1]) {
            len += check_flag_and_precision(format, &i, &ctx);
        } else {
            len += my_putchar(format[i]);
        }
    }

    va_end(ctx.args);
    return len;
}
