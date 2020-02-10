/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ulltoa_base.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/13 17:21:21 by jvisser        #+#    #+#                */
/*   Updated: 2019/02/13 18:50:16 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	count_chars(unsigned long long value, unsigned long long base)
{
	int	count;

	count = 0;
	if (value == 0)
		return (1);
	while (value != 0)
	{
		value /= base;
		count++;
	}
	return (count);
}

static char	*mirror_array(char *str)
{
	int		length;
	int		index;
	char	temp;

	length = 0;
	while (str[length + 1])
		length++;
	if (str[0] == '-')
		index = 1;
	else
		index = 0;
	while (length > index)
	{
		temp = str[index];
		str[index] = str[length];
		str[length] = temp;
		index++;
		length--;
	}
	return (str);
}

static void	fill_array(char *array, unsigned long long value, int base)
{
	int		index;
	char	temp;

	index = 0;
	if (value == 0)
		index = 1;
	while (value != 0)
	{
		temp = value % base;
		value = value / base;
		if (temp >= 10)
			temp += 39;
		array[index] = temp + '0';
		index++;
	}
	array[index] = '\0';
}

char		*ft_ulltoa_base(unsigned long long value, int base)
{
	int		no_chars;
	char	*array;

	no_chars = count_chars(value, base);
	array = (char *)malloc(no_chars + 1);
	if (value == 0)
		array[0] = '0';
	fill_array(array, value, base);
	return (mirror_array(array));
}
