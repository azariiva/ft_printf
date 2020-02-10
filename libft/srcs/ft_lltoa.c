/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lltoa.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/13 12:33:10 by jvisser        #+#    #+#                */
/*   Updated: 2019/03/01 18:36:39 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_lltoa(long long n)
{
	char		*s;
	size_t		len;
	long long	tmp;

	len = (n <= 0);
	tmp = n;
	while (tmp)
	{
		++len;
		tmp /= 10;
	}
	if (!(s = ft_strnew(len)))
		return (0);
	tmp = len - 2;
	s[len - 1] = ft_llabs(n % 10) + '0';
	if (n < 0)
		s[0] = '-';
	n = ft_llabs(n / 10);
	while (n)
	{
		s[tmp--] = n % 10 + '0';
		n /= 10;
	}
	return (s);
}
