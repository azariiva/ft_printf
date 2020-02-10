/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 16:26:08 by jvisser        #+#    #+#                */
/*   Updated: 2019/02/12 14:25:33 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		countnumbers(int n)
{
	int	result;

	result = 0;
	if (n <= 0)
		result = 1;
	while (n)
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

	temp = 0;
	index = 0;
	index2 = 0;
	while (str[index2 + 1])
		index2++;
	while (index < index2)
	{
		temp = str[index];
		str[index] = str[index2];
		str[index2] = temp;
		index++;
		index2--;
	}
}

static void		fill_array(char *result, long n)
{
	int	temp;
	int	index;

	temp = n;
	index = 0;
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
		n /= 10;
		index++;
	}
	if (temp < 0)
	{
		result[index] = '-';
		index++;
	}
	result[index] = '\0';
	reverse_string(result);
}

char			*ft_itoa(int n)
{
	char	*result;

	if (!(result = (char *)malloc(countnumbers(n) + 1)))
		return (NULL);
	fill_array(result, n);
	return (result);
}
