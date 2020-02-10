/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 13:44:37 by jvisser        #+#    #+#                */
/*   Updated: 2019/02/12 15:09:35 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		index;
	int		index2;
	int		length;
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	length = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)malloc(length + 1);
	if (!result)
		return (NULL);
	index = 0;
	index2 = 0;
	while (s1[index])
	{
		result[index] = s1[index];
		index++;
	}
	while (s2[index2])
	{
		result[index + index2] = s2[index2];
		index2++;
	}
	result[index + index2] = '\0';
	return (result);
}
