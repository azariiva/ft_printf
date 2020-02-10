/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_utf8_4b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhilary <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:39:02 by fhilary           #+#    #+#             */
/*   Updated: 2020/02/10 18:39:06 by fhilary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static size_t	check_4byte_1(unsigned char *str, size_t len, size_t *i,
														bool *checked)
{
	if (str[*i] == 0xF0)
	{
		if (*i + 3 < len)
		{
			if (str[*i + 1] < 0x90 || str[*i + 1] > 0xBF)
				return (2);
			if (str[*i + 2] < 0x80 || str[*i + 2] > 0xBF)
				return (3);
			if (str[*i + 3] < 0x80 || str[*i + 3] > 0xBF)
				return (4);
		}
		else
			return (1);
		*i += 4;
		*checked = true;
	}
	return (0);
}

static size_t	check_4byte_2(unsigned char *str, size_t len, size_t *i,
														bool *checked)
{
	if (str[*i] >= 0xF1 && str[*i] <= 0xF3)
	{
		if (*i + 3 < len)
		{
			if (str[*i + 1] < 0x80 || str[*i + 1] > 0xBF)
				return (2);
			if (str[*i + 2] < 0x80 || str[*i + 2] > 0xBF)
				return (3);
			if (str[*i + 3] < 0x80 || str[*i + 3] > 0xBF)
				return (4);
		}
		else
			return (1);
		*i += 4;
		*checked = true;
	}
	return (0);
}

static size_t	check_4byte_3(unsigned char *str, size_t len, size_t *i,
														bool *checked)
{
	if (str[*i] == 0xF4)
	{
		if (*i + 3 < len)
		{
			if (str[*i + 1] < 0x80 || str[*i + 1] > 0x8F)
				return (2);
			if (str[*i + 2] < 0x80 || str[*i + 2] > 0xBF)
				return (3);
			if (str[*i + 3] < 0x80 || str[*i + 3] > 0xBF)
				return (4);
		}
		else
			return (1);
		*i += 4;
		*checked = true;
	}
	return (0);
}

size_t			check_4byte_utf8(unsigned char *str, size_t len, size_t *i,
														bool *checked)
{
	if (check_4byte_1(str, len, i, checked)
	|| check_4byte_2(str, len, i, checked)
	|| check_4byte_3(str, len, i, checked))
		return (3);
	return (0);
}
