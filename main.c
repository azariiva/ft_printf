#include "./includes/libftprintf.h"
#include <stdio.h>

int main(void)
{
    ft_printf("{red}%ld{eoc}", 2147483648);
    return (0);
}