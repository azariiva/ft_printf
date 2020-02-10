/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_wstrdup.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/04 16:53:10 by jvisser        #+#    #+#                */
/*   Updated: 2019/03/04 16:58:57 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <stdlib.h>
#include "libft.h"

wchar_t	*ft_wstrdup(wchar_t *str)
{
	wchar_t			*result;
	int				len;

	len = ft_wstrbytes(str);
	result = (wchar_t*)malloc(len + 1);
	ft_memcpy(result, str, len + 1);
	return (result);
}
