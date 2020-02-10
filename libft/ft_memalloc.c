/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memalloc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 09:59:50 by jvisser       #+#    #+#                 */
/*   Updated: 2019/01/10 09:59:51 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*result;

	if (!(result = (void *)malloc(size)))
		return (NULL);
	ft_memset(result, 0, size);
	return (result);
}
