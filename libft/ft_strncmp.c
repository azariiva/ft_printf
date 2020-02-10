/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvisser <jvisser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 18:44:37 by jvisser           #+#    #+#             */
/*   Updated: 2019/01/14 17:43:31 by jvisser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t index;

	index = 0;
	while (((unsigned char)s1[index] == (unsigned char)s2[index])
	&& ((unsigned char)s1[index] && (unsigned char)s2[index]) && index < n)
		index++;
	if ((unsigned char)s1[index] != (unsigned char)s2[index] && index < n)
		return ((unsigned char)s1[index] - (unsigned char)s2[index]);
	return (0);
}
