#include "libft.h"
#include <wchar.h>

ssize_t	ft_wstrlen(const wchar_t *s)
{
    size_t          len;

    len = 0;
    while (*s) {
        len += ft_wclen(*s++);
    }
    return (len);
}