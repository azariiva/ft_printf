/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstrch.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/12 15:38:29 by jvisser        #+#    #+#                */
/*   Updated: 2019/02/12 15:40:52 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstrch(char const *s, char c)
{
	int index;

	index = 0;
	while (s[index] && s[index] != c)
	{
		write(1, &s[index], 1);
		index++;
	}
}
