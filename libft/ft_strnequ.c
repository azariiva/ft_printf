/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnequ.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 12:54:52 by jvisser        #+#    #+#                */
/*   Updated: 2019/02/12 14:59:25 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	index;

	index = 0;
	if (!s1 || !s2)
		return (0);
	while ((s1[index] == s2[index]) && (s1[index] && s2[index]) && index < n)
		index++;
	if (s1[index] != s2[index] && index < n)
		return (0);
	return (1);
}
