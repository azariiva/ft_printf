/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_utf8_3b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhilary <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:38:54 by fhilary           #+#    #+#             */
/*   Updated: 2020/02/10 18:38:57 by fhilary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static size_t	check_3byte_1(unsigned char *str, size_t len, size_t *i,
														bool *checked)
{
	if (str[*i] == 0xE0)
	{
		if (*i + 2 < len)
		{
			if (str[*i + 1] < 0xA0 || str[*i + 1] > 0xBF)
				return (2);
			if (str[*i + 2] < 0x80 || str[*i + 2] > 0xBF)
				return (3);
		}
		else
			return (1);
		*i += 3;
		*checked = true;
	}
	return (0);
}

static size_t	check_3byte_2(unsigned char *str, size_t len, size_t *i,
														bool *checked)
{
	if (str[*i] >= 0xE1 && str[*i] <= 0xEC)
	{
		if (*i + 2 < len)
		{
			if (str[*i + 1] < 0x80 || str[*i + 1] > 0xBF)
				return (2);
			if (str[*i + 2] < 0x80 || str[*i + 2] > 0xBF)
				return (3);
		}
		else
			return (1);
		*i += 3;
		*checked = true;
	}
	return (0);
}

static size_t	check_3byte_3(unsigned char *str, size_t len, size_t *i,
														bool *checked)
{
	if (str[*i] == 0xED)
	{
		if (*i + 2 < len)
		{
			if (str[*i + 1] < 0x80 || str[*i + 1] > 0x9F)
				return (2);
			if (str[*i + 2] < 0x80 || str[*i + 2] > 0xBF)
				return (3);
		}
		else
			return (1);
		*i += 3;
		*checked = true;
	}
	return (0);
}

static size_t	check_3byte_4(unsigned char *str, size_t len, size_t *i,
														bool *checked)
{
	if (str[*i] >= 0xEE && str[*i] <= 0xEF)
	{
		if (*i + 2 < len)
		{
			if (str[*i + 1] < 0x80 || str[*i + 1] > 0xBF)
				return (2);
			if (str[*i + 2] < 0x80 || str[*i + 2] > 0xBF)
				return (3);
		}
		else
			return (1);
		*i += 3;
		*checked = true;
	}
	return (0);
}

size_t			check_3byte_utf8(unsigned char *str, size_t len, size_t *i,
														bool *checked)
{
	if (check_3byte_1(str, len, i, checked)
	|| check_3byte_2(str, len, i, checked)
	|| check_3byte_3(str, len, i, checked)
	|| check_3byte_4(str, len, i, checked))
		return (3);
	return (0);
}
