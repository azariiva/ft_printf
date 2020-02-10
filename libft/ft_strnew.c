/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 10:44:32 by jvisser        #+#    #+#                */
/*   Updated: 2019/02/12 14:59:44 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*result;

	result = (char *)malloc(size + 1);
	if (!result)
		return (NULL);
	ft_memset(result, '\0', size + 1);
	return (result);
}
