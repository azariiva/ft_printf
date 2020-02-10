/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_powerof.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 18:07:46 by jvisser        #+#    #+#                */
/*   Updated: 2019/03/04 16:12:06 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

long long	ft_powerof(const size_t nb, size_t power)
{
	long long	result;

	result = (long long)nb;
	if (nb == 0)
		return (0);
	while (power-- > 1)
		result *= nb;
	return (result);
}
