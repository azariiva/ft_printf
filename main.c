#include "./includes/libftprintf.h"
#include <stdio.h>

int main(void)
{
    ft_printf("{red}%ld{eocd}", 2147483648);
    return (0);
}