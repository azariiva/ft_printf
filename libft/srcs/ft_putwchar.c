#include "libft.h"

static int	ft_putmorewchar(wchar_t c, char *str)
{
	if (c >= 0x800 && c <= 0xFFFF)
	{
		str[2] = (c & 63) + 128;
		c = c >> 6;
		str[1] = (c & 63) + 128;
		c = c >> 6;
		str[0] = (c & 15) + 224;
		return (ft_putstr(str));
	}
	else if (c >= 0x10000 && c <= 0x10FFFF)
	{
		str[3] = (c & 63) + 128;
		c = c >> 6;
		str[2] = (c & 63) + 128;
		c = c >> 6;
		str[1] = (c & 63) + 128;
		c = c >> 6;
		str[0] = (c & 7) + 240;
		return (ft_putstr(str));
	}
	return (0);
}

int			ft_putwchar(wchar_t c)
{
	char	str[5];

	ft_bzero(str, 5);
	if (c >= 0x00 && c <= 0x7F)
	{
		return (ft_putstr(str));
	}
	else if (c >= 0x80 && c <= 0x7FF)
	{
		str[1] = (c & 63) + 128;
		c = c >> 6;
		str[0] = (c & 31) + 192;
		return (ft_putstr(str));
	}
	else
		return (ft_putmorewchar(c, str));
	return (0);
}
