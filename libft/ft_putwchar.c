/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putwchar.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/04 13:11:34 by jvisser        #+#    #+#                */
/*   Updated: 2019/03/04 14:31:26 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <unistd.h>

static int	ft_putmorewchar(wchar_t c, char *str)
{
	if (c >= 0x800 && c <= 0xFFFF)
	{
		str[2] = (c & 63) + 128;
		c = c >> 6;
		str[1] = (c & 63) + 128;
		c = c >> 6;
		str[0] = (c & 15) + 224;
		write(1, str, 3);
		return (3);
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
		write(1, str, 4);
		return (4);
	}
	return (0);
}

int			ft_putwchar(wchar_t c)
{
	char	str[4];

	if (c >= 0x00 && c <= 0x7F)
	{
		write(1, &c, 1);
		return (1);
	}
	else if (c >= 0x80 && c <= 0x7FF)
	{
		str[1] = (c & 63) + 128;
		c = c >> 6;
		str[0] = (c & 31) + 192;
		write(1, str, 2);
		return (2);
	}
	else
		return (ft_putmorewchar(c, str));
	return (0);
}
