#include "my_printf.h"

int my_putchar(char c)
{
    return write(1, &c, 1);
}

int my_putnbr_base_len(int nb, char const *base)
{
    int digit;
    int len = 0;
    int len_base = strlen(base);
    char c;

    if (base == NULL || *base == '\0') {
        return 0;
    }

    if (nb < 0) {
        write(1, "-", 1);
        if (nb == INT_MIN) {
            len += my_putnbr_base_len(-(nb / 10), base);
            c = '0' + -(nb % 10);
            write(1, &c, 1);
            return len + 2;
        }
        nb = -nb;
        len++;
    }
    if (nb >= len_base) {
        len += my_putnbr_base_len(nb / len_base, base);
    }
    digit = nb % len_base;
    write(1, &base[digit], 1);
    len++;
    return len;
}

int my_putnbr_base_unsigned_len(unsigned int nb, char const *base)
{
    unsigned int digit;
    int len = 0;
    unsigned int len_base = strlen(base);

    if (base == NULL || *base == '\0') {
        return 0;
    }

    if (nb >= len_base) {
        len += my_putnbr_base_unsigned_len(nb / len_base, base);
    }
    digit = nb % len_base;
    write(1, &base[digit], 1);
    len++;
    return len;
}
