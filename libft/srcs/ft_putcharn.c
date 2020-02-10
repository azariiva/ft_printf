/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putcharn.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/12 17:42:35 by jvisser        #+#    #+#                */
/*   Updated: 2019/02/12 18:04:48 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>

void	ft_putcharn(char c, size_t n)
{
	while (n > 0)
	{
		write(1, &c, 1);
		n--;
	}
}
