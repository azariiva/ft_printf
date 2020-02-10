/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlench.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/12 15:45:21 by jvisser        #+#    #+#                */
/*   Updated: 2019/02/12 15:46:05 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlench(const char *s, char c)
{
	size_t	result;

	result = 0;
	while (s[result] && s[result] != c)
		result++;
	return (result);
}
