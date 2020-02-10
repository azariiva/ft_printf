/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_formatwchar.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/04 14:20:26 by jvisser        #+#    #+#                */
/*   Updated: 2019/03/04 14:32:25 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <string.h>
#include <stdlib.h>

static unsigned char	*format_morewchar(wchar_t c, size_t *len,
												unsigned char *str)
{
	if (c >= 0x800 && c <= 0xFFFF)
	{
		str[2] = (c & 63) + 128;
		c = c >> 6;
		str[1] = (c & 63) + 128;
		c = c >> 6;
		str[0] = (c & 15) + 224;
		*len = 3;
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
		*len = 4;
	}
	else
		return (NULL);
	return (str);
}

unsigned char			*format_wchar(wchar_t c, size_t *len)
{
	unsigned char	*str;

	str = (unsigned char*)malloc(4);
	if (!str)
		return (NULL);
	if (c >= 0x00 && c <= 0x7F)
	{
		str[0] = (c & 127);
		*len = 1;
	}
	else if (c >= 0x80 && c <= 0x7FF)
	{
		str[1] = (c & 63) + 128;
		c = c >> 6;
		str[0] = (c & 31) + 192;
		*len = 2;
	}
	else
		return (format_morewchar(c, len, str));
	return (str);
}
