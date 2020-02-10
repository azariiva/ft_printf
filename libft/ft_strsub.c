/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsub.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 12:57:38 by jvisser        #+#    #+#                */
/*   Updated: 2019/02/12 15:14:05 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	index;
	char	*result;

	if (s == NULL)
		return (NULL);
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	index = 0;
	while (index != len)
	{
		result[index] = s[start];
		index++;
		start++;
	}
	result[index] = '\0';
	return (result);
}
