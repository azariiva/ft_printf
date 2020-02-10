/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_wstrbytes.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/04 16:54:56 by jvisser        #+#    #+#                */
/*   Updated: 2019/03/04 16:57:47 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>

int		ft_wstrbytes(wchar_t *wstr)
{
	int		len;
	wchar_t	*p;

	p = wstr;
	while (*p)
		p++;
	len = (char*)p - (char*)wstr;
	return (len);
}
