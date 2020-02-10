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
#include <limits.h>
#include <stdlib.h>

static int		countnumbers(long long n)
{
	int	result;

	result = 0;
	if (n <= 0)
		result = 1;
	while (n != 0)
	{
		n /= 10;
		result++;
	}
	return (result);
}

static void		reverse_string(char *str)
{
	char	temp;
	int		index;
	int		index2;
	int		length;

	temp = 0;
	length = 0;
	index = 0;
	while (str[length + 1])
		length++;
	index2 = length;
	while (index < index2)
	{
		temp = str[index];
		str[index++] = str[index2];
		str[index2--] = temp;
	}
}

static void		fill_array(char *result, long long n)
{
	int			index;
	long long	temp;

	index = 0;
	temp = n;
	if (n == 0)
	{
		result[index] = '0';
		index++;
	}
	if (n < 0)
		n *= -1;
	while (n != 0)
	{
		result[index] = (n % 10) + '0';
		index++;
		n /= 10;
	}
	if (temp < 0)
	{
		result[index] = '-';
		index++;
	}
	result[index] = '\0';
	reverse_string(result);
}

char			*smallest_long_long(void)
{
	char	*result;

	result = ft_strdup("-9223372036854775808");
	if (result == NULL)
		return (NULL);
	return (result);
}

char			*ft_lltoa(long long n)
{
	int		numbers;
	char	*result;

	numbers = countnumbers(n);
	if (n == LONG_MIN)
		return (smallest_long_long());
	result = (char *)malloc(numbers + 1);
	if (result == NULL)
		return (NULL);
	fill_array(result, n);
	return (result);
}
