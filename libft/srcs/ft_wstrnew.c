#include "libft.h"
#include <wchar.h>

wchar_t	*ft_wstrnew(size_t size)
{
	wchar_t	*str;
	size_t	i;

	if (!(size + 1) || !(str = (wchar_t *)malloc((size + 1) * sizeof(wchar_t))))
		return (NULL);
	i = 0;
	while (i <= size)
		str[i++] = L'\0';
	return (str);
}