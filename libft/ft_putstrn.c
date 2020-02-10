/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstrn.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/12 17:36:10 by jvisser        #+#    #+#                */
/*   Updated: 2019/02/12 17:37:31 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>

void	ft_putstrn(char const *s, size_t n)
{
	int index;

	index = 0;
	while (s[index] && n)
	{
		write(1, &s[index], 1);
		index++;
		n--;
	}
}
