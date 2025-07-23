#include "my_printf.h"

int main(void)
{
    my_printf("################ MY_IMPL ################\n\n");
    my_printf("Len: %d\n", my_printf("Bonjour les amis, %d%%%c%s\n%s%K, %d, %u, %u\n", 4200078, 'q', "Ohayouuu", NULL, -2147483648, 200, -200));
    my_printf("Len: %d\n", my_printf("Number: %d, Hexa: %X, Hexa_small: %x, Binary: %b, Octal: %o\n", 42, 42, 42, 42, 42));
    my_printf("Len: %d\n", my_printf("Test float default precision: %f\n", 12.3456789));
    my_printf("Len: %d\n", my_printf("Test float precision 2: %.2f\n", 12.3456789));
    my_printf("Len: %d\n", my_printf("Test float precision 0: %.0f\n", 12.9456789));
    my_printf("Len: %d\n", my_printf("Test float negative: %.3f\n", -123.456789));

    my_printf("Float nb: %f\n", 12.4545466);
    my_printf("Negative float: %f\n", -123.456);
    my_printf("Len: %d\n", my_printf("%.2s\n", "Hello world"));

    /*my_printf("\n################ PRINTF ################\n\n");
    printf("Len: %d\n", my_printf("Bonjour les amis, %d%%%c%s\n%s%K, %d, %u, %u\n", 4200078, 'q', "Ohayouuu", NULL, -2147483648, 200, -200));
    printf("Len: %d\n", printf("Number: %d, Hexa: %X, Binary: %b, Octal: %o\n", 42, 42, 42, 42));
    printf("Len: %d\n", printf("Test float default precision: %f\n", 12.3456789));
    printf("Len: %d\n", printf("Test float precision 2: %.2f\n", 12.3456789));
    printf("Len: %d\n", printf("Test float precision 0: %.0f\n", 12.9456789));
    printf("Len: %d\n", printf("Test float negative: %.3f\n\n\n", -123.456789));

    printf("Float nb: %f\n", 12.4545466);
    printf("Negative float: %f\n", -123.456);
    printf("Len: %d\n", printf("%.2s\n", "Hello world"));*/

    return 0;
}
