/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhilary <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:39:17 by fhilary           #+#    #+#             */
/*   Updated: 2020/02/10 18:39:21 by fhilary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	if_nothing(t_pf *pf, char *str, int *i)
{
	if (str[*i])
	{
		pf->data_type = 'c';
		validate_flags(pf);
	}
	pf->data_type = -1;
}

int		is_flag(char c)
{
	if (c == '-' || c == '+' || c == ' '
	|| c == '0' || c == '#')
		return (1);
	return (0);
}

int		is_modifier(char c)
{
	if (c == 'l' || c == 'h' || c == 'L'
	|| c == 'j' || c == 'z')
		return (1);
	return (0);
}

int		is_data_type(char c)
{
	if (c == 'c' || c == 's' || c == 'p'
	|| c == 'd' || c == 'i' || c == 'o' || c == 'u'
	|| c == 'x' || c == 'X' || c == 'f' || c == '%'
	|| c == 'D' || c == 'O' || c == 'U' || c == 'F'
	|| c == 'C' || c == 'S')
		return (1);
	return (0);
}

void	validate_flags(t_pf *pf)
{
	if (PLUS_FLAG == 1 && SPACE_FLAG == 1)
		SPACE_FLAG = 0;
	if (MIN_FLAG == 1 && ZERO_FLAG == 1)
		ZERO_FLAG = 0;
	if (pf->precision != 0 && ZERO_FLAG == 1
		&& (pf->data_type == 'd' || pf->data_type == 'i'
		|| pf->data_type == 'o' || pf->data_type == 'O'
		|| pf->data_type == 'u' || pf->data_type == 'U'
		|| pf->data_type == 'x' || pf->data_type == 'X'))
		ZERO_FLAG = 0;
}
