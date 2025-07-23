#include "my_printf.h"

/* -- FLAGS -- */

int c_flag(printf_context_t *ctx, int precision)
{
    char c;

    (void)precision;
    c = va_arg(ctx->args, int);

    return write(1, &c, 1);
}

int s_flag(printf_context_t *ctx, int precision)
{
    char *s = va_arg(ctx->args, char *);
    int i, len = 0;
    if (!s)
        s = "(null)";

    if (precision >= 0) {
        for (i = 0; i < precision && s[i]; i++)
            len += write(1, &s[i], 1);
    } else {
        len = write(1, s, strlen(s));
    }
    return len;
}

int d_flag(printf_context_t *ctx, int precision)
{
    (void)precision;
    return my_putnbr_base_len(va_arg(ctx->args, int), "0123456789");
}

int u_flag(printf_context_t *ctx, int precision)
{
    unsigned int u;

    (void)precision;
    u = va_arg(ctx->args, unsigned int);
    
    return my_putnbr_base_unsigned_len(u, "0123456789");
}

int b_flag(printf_context_t *ctx, int precision)
{
    unsigned int b;

    (void)precision;
    b = va_arg(ctx->args, unsigned int);

    return my_putnbr_base_unsigned_len(b, "01");
}

int o_flag(printf_context_t *ctx, int precision)
{
    unsigned int o;

    (void)precision;
    o = va_arg(ctx->args, unsigned int);
    
    return my_putnbr_base_unsigned_len(o, "01234567");
}

int X_flag(printf_context_t *ctx, int precision)
{
    unsigned int x;

    (void)precision;
    x = va_arg(ctx->args, unsigned int);
    
    return my_putnbr_base_unsigned_len(x, "0123456789ABCDEF");
}

int x_flag(printf_context_t *ctx, int precision)
{
    unsigned int x;

    (void)precision;
    x = va_arg(ctx->args, unsigned int);
    
    return my_putnbr_base_unsigned_len(x, "0123456789abcdef");
}

int mark_flag(printf_context_t *ctx, int precision)
{
    char c;
    
    (void)ctx;
    (void)precision;
    c = '%';

    return write(1, &c, 1);
}

int f_flag(printf_context_t *ctx, int precision)
{
    double decimal_part, factor, number = va_arg(ctx->args, double);
    int is_negative, digit, len = 0;
    long long integer_part, dec_int, div;

    if (precision < 0)
        precision = 6;

    is_negative = 0;
    if (number < 0) {
        is_negative = 1;
        number = -number;
    }

    factor = pow(10, precision);
    number += 0.5 / factor;

    integer_part = (long long)number;
    decimal_part = number - integer_part;

    if (is_negative)
        len += my_putchar('-');

    len += my_putnbr_base_len(integer_part, "0123456789");

    if (precision > 0) {
        len += my_putchar('.');
        dec_int = (long long)(decimal_part * factor);
        div = factor / 10;
        while (div > 0) {
            digit = dec_int / div;
            len += my_putchar('0' + digit);
            dec_int %= div;
            div /= 10;
        }
    }
    return len;
}
