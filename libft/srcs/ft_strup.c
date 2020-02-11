#include "libft.h"

void	ft_strup(char *tmp)
{
	tmp--;
	while (*++tmp)
		*tmp = ft_toupper(*tmp);
}