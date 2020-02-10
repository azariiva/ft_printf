/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_utf8.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/04 18:34:30 by jvisser        #+#    #+#                */
/*   Updated: 2019/03/05 13:20:27 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
**	---------------------------------------------------------------------------
**	| Code Points       | First Byte | Second Byte | Third Byte | Fourth Byte |
**	| U+0000..U+007F    |     00..7F |             |            |             |
**	| U+0080..U+07FF    |     C2..DF |      80..BF |            |             |
**	| U+0800..U+0FFF    |         E0 |      A0..BF |     80..BF |             |
**	| U+1000..U+CFFF    |     E1..EC |      80..BF |     80..BF |             |
**	| U+D000..U+D7FF    |         ED |      80..9F |     80..BF |             |
**	| U+E000..U+FFFF    |     EE..EF |      80..BF |     80..BF |             |
**	| U+10000..U+3FFFF  |         F0 |      90..BF |     80..BF |      80..BF |
**	| U+40000..U+FFFFF  |     F1..F3 |      80..BF |     80..BF |      80..BF |
**	| U+100000..U+10FFFF|         F4 |      80..8F |     80..BF |      80..BF |
**	---------------------------------------------------------------------------
*/

size_t	check_2byte_utf8(unsigned char *str, size_t len, size_t *i,
														bool *checked)
{
	if (str[*i] >= 0xC2 && str[*i] <= 0xDF)
	{
		if (*i + 1 < len)
		{
			if (str[*i + 1] < 0x80 || str[*i + 1] > 0xBF)
				return (2);
		}
		else
			return (1);
		*i += 2;
		*checked = true;
	}
	return (0);
}

size_t	is_utf8(unsigned char *str, size_t len)
{
	bool	checked;
	size_t	i;

	i = 0;
	while (i < len)
	{
		checked = false;
		if (str[i] <= 0x7F)
			i += 1;
		else if (check_2byte_utf8(str, len, &i, &checked))
			return (2);
		else if (check_3byte_utf8(str, len, &i, &checked))
			return (3);
		else if (check_4byte_utf8(str, len, &i, &checked))
			return (4);
		else if (checked == false)
			return (1);
	}
	return (0);
}
