#include "libft.h"
#include <wchar.h>

wchar_t	*ft_wstrdup(wchar_t *s)
{
	size_t	len;
	wchar_t	*new;

	len = ft_wstrlen(s);
	if (!(new = ft_wstrnew(len)))
		return (NULL);
	return (ft_memcpy(new, s, len));
}

