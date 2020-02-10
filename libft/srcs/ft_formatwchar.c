#include <wchar.h>
#include "libft.h"

static unsigned char	*ft_helper(wchar_t c, size_t *len,
												unsigned char *str)
{
	if (c >= 0x800 && c <= 0xFFFF)
	{
		str[2] = (c & 0x3F) + 128;
		c >>= 6;
		str[1] = (c & 0x3F) + 128;
		c >>= 6;
		str[0] = (c & 0xF) + 224;
		*len = 3;
	}
	else if (c >= 0x10000 && c <= 0x10FFFF)
	{
		str[3] = (c & 0x3F) + 0x80;
		c >>= 6;
		str[2] = (c & 0x3F) + 0x80;
		c >>= 6;
		str[1] = (c & 0x3F) + 0x80;
		c >>= 6;
		str[0] = (c & 0x7) + 0xF0;
		*len = 4;
	}
	else
	{
		free(str);
		str = NULL;
	}
	return (str);
}

unsigned char			*ft_formatwchar(wchar_t c, size_t *len)
{
	unsigned char	*str;

	if (!(str = (unsigned char*)ft_strnew(4)))
		return (NULL);
	if (c >= 0x00 && c <= 0x7F)
	{
		str[0] = (c & 0x7F);
		*len = 1;
	}
	else if (c >= 0x80 && c <= 0x7FF)
	{
		str[1] = (c & 0x3F) + 0x80;
		c >>= 6;
		str[0] = (c & 0x1F) + 192;
		*len = 2;
	}
	else
		str = ft_helper(c, len, str);
	return (str);
}
