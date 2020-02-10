/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvisser <jvisser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 13:03:16 by jvisser           #+#    #+#             */
/*   Updated: 2019/01/15 14:55:08 by jvisser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *p;

	p = s;
	while (n != 0)
	{
		if (*p++ == (unsigned char)c)
			return ((void *)(p - 1));
		n--;
	}
	return (NULL);
}
