/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_wclen.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/04 15:07:14 by jvisser        #+#    #+#                */
/*   Updated: 2019/03/04 15:09:33 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>

int	ft_wclen(wchar_t wc)
{
	if (wc >= 0x00 && wc <= 0x7F)
		return (1);
	else if (wc >= 0x80 && wc <= 0x7FF)
		return (2);
	else if (wc >= 0x800 && wc <= 0xFFFF)
		return (3);
	else if (wc >= 0x10000 && wc <= 0x10FFFF)
		return (4);
	return (0);
}
