/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 15:22:08 by jvisser        #+#    #+#                */
/*   Updated: 2019/02/12 14:59:04 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	index_s1;
	size_t	index_s2;

	index_s1 = 0;
	index_s2 = 0;
	while (s1[index_s1])
		index_s1++;
	while (index_s2 < n && s2[index_s2])
	{
		s1[index_s1] = s2[index_s2];
		index_s1++;
		index_s2++;
	}
	s1[index_s1] = '\0';
	return (s1);
}
