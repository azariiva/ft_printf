#include <wchar.h>

int	ft_wclen(wchar_t c)
{
	if (c >= 0x00 && c <= 0x7F)
		return (1);
	else if (c >= 0x80 && c <= 0x7FF)
		return (2);
	else if (c >= 0x800 && c <= 0xFFFF)
		return (3);
	else if (c >= 0x10000 && c <= 0x10FFFF)
		return (4);
	return (0);
}