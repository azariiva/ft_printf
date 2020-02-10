/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 18:31:59 by jvisser        #+#    #+#                */
/*   Updated: 2019/02/12 14:24:07 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	count_chars(long value, long base)
{
	int	count;
	int	power;

	count = 1;
	power = base;
	if (base == 10 && value < 0)
	{
		value *= -1;
		count++;
	}
	if (value >= 0)
	{
		while (base <= value)
		{
			base = base * power;
			count++;
		}
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

static void	fill_array(char *array, long value, int base)
{
	int		index;
	char	temp;

	index = 0;
	if (value <= 0)
	{
		if (value < 0)
			array[index] = '-';
		value *= -1;
		index++;
	}
	while (value != 0)
	{
		temp = value % base;
		value = value / base;
		if (temp >= 10)
			temp += 7;
		array[index] = temp + '0';
		index++;
	}
	array[index] = '\0';
}

static char	*fill_smallest_nbr(long value, int base)
{
	int		no_chars;
	char	*array;

	if (value < 0 && base != 10)
		value *= -1;
	no_chars = count_chars(value, base);
	array = (char*)malloc(no_chars + 1);
	if (!array)
		return (NULL);
	fill_array(array, value, base);
	return (mirror_array(array));
}

char		*ft_itoa_base(int value, int base)
{
	int		no_chars;
	char	*array;

	if (value == -2147483648)
		return (fill_smallest_nbr(value, base));
	if (value < 0 && base != 10)
		value *= -1;
	no_chars = count_chars(value, base);
	array = (char *)malloc(no_chars + 1);
	if (!array)
		return (NULL);
	if (value == 0)
		array[0] = '0';
	fill_array(array, value, base);
	return (mirror_array(array));
}
