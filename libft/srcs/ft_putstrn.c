#include "libft.h"

int ft_putstrn(const char *str, size_t n)
{
    size_t  len;

    len = ft_strlen(str);
    return (write(STDOUT_FILENO, str, (len > n ? n : len)));
}