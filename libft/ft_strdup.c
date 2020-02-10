/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 14:10:05 by jvisser        #+#    #+#                */
/*   Updated: 2019/02/12 14:32:45 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		length;
	char	*duplicate;

	length = ft_strlen(s1);
	duplicate = (char*)malloc(sizeof(char) * (length + 1));
	if (!duplicate)
		return (NULL);
	ft_memcpy(duplicate, s1, length + 1);
	return (duplicate);
}
