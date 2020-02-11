/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhilary <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:40:28 by fhilary           #+#    #+#             */
/*   Updated: 2020/02/10 18:40:33 by fhilary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		validate_address(wchar_t c)
{
	size_t			len;
	unsigned char	*str;

	len = 0;
	str = ft_formatwchar(c, &len);
	if (!str || is_utf8(str, len))
	{
		free(str);
		return (1);
	}
	else
	{
		free(str);
		return (0);
	}
}

static int		validate_wide_data(t_pf *pf, va_list valist)
{
	wchar_t	c;
	wchar_t	*str;

	if (pf->data_type == 'C' || (pf->data_type == 'c' && (pf->modifier & L_MOD)))
	{
		c = va_arg(valist, wchar_t);
		if (validate_address(c))
			return (0);
	}
	else if (pf->data_type == 'S' || (pf->data_type == 's' && (pf->modifier & L_MOD)))
	{
		str = va_arg(valist, wchar_t*);
		while (str && *str)
		{
			if (validate_address(*str))
				return (0);
			str++;
		}
	}
	return (1);
}

int				validate_next(t_pf *pf, char *format, va_list valist)
{
	int		i;

	i = 0;
	reset_pf(pf);
	while (format && format[i] && format[i] != '%')
		i++;
	if (format[i] == '%')
	{
		parse_placeholder(pf, format, &i, valist);
		if (pf->data_type == 'C' || (pf->data_type == 'c' && (pf->modifier & L_MOD))
		|| pf->data_type == 'S' || (pf->data_type == 's' && (pf->modifier & L_MOD)))
		{
			if (!validate_wide_data(pf, valist))
			{
				va_end(valist);
				return (0);
			}
		}
		else
			cast_placeholder(pf, valist);
		reset_pf(pf);
	}
	free(format);
	return (1);
}
