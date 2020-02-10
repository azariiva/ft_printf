/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvisser <jvisser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 15:35:28 by jvisser           #+#    #+#             */
/*   Updated: 2019/01/14 14:35:57 by jvisser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		length_dest;
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	i = size;
	while (i-- != 0 && *dst != '\0')
		dst++;
	length_dest = dst - d;
	i = size - length_dest;
	if (i-- == 0)
		return (length_dest + ft_strlen(src));
	while (*src != '\0')
	{
		if (i != 0)
		{
			*dst++ = *src;
			i--;
		}
		src++;
	}
	*dst = '\0';
	return (length_dest + (src - s));
}
