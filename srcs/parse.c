/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/05 15:35:26 by jvisser        #+#    #+#                */
/*   Updated: 2019/03/07 18:09:27 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	set_flag(t_pf *pf, char c, int *i)
{
	if (c == '-')
		MIN_FLAG = 1;
	else if (c == '+')
		PLUS_FLAG = 1;
	else if (c == ' ')
		SPACE_FLAG = 1;
	else if (c == '0')
		ZERO_FLAG = 1;
	else if (c == '#')
		HASH_FLAG = 1;
	(*i)++;
}

void	set_width(t_pf *pf, char *str, int *i, va_list valist)
{
	long	w;

	if (str[*i] == '*')
	{
		w = (long)va_arg(valist, int);
		if (w < 0)
		{
			w *= -1;
			MIN_FLAG = 1;
		}
		pf->width = (int)w;
		(*i)++;
	}
	else
	{
		pf->width = ft_atoi(&str[*i]);
		while (str[*i] >= '0' && str[*i] <= '9')
			(*i)++;
	}
}

void	set_precision(t_pf *pf, char *str, int *i, va_list valist)
{
	long	w;

	(*i)++;
	if (str[*i] == '*')
	{
		w = (long)va_arg(valist, int);
		if (w >= 0)
		{
			pf->precision = (int)w;
			if (pf->precision == 0)
				pf->precision = -1;
		}
		(*i)++;
	}
	else
	{
		pf->precision = ft_atoi(&str[*i]);
		if (pf->precision <= 0)
			pf->precision = -1;
	}
	while (str[*i] >= '0' && str[*i] <= '9')
		(*i)++;
}

void	set_modifier(t_pf *pf, char *str, int *i)
{
	if (str[*i] == 'l')
	{
		if (str[(*i) + 1] == 'l')
			LL_MOD = 1;
		else
			L_MOD = 1;
	}
	if (str[*i] == 'h')
	{
		if (str[(*i) + 1] == 'h')
			HH_MOD = 1;
		else
			H_MOD = 1;
	}
	if (str[*i] == 'L')
		CAP_L_MOD = 1;
	if (str[*i] == 'j')
		J_MOD = 1;
	if (str[*i] == 'z')
		Z_MOD = 1;
	(*i)++;
}

void	parse_placeholder(t_pf *pf, char *str, int *i, va_list va)
{
	(*i)++;
	while (!(pf->data_type))
	{
		if (is_flag(str[*i]))
			set_flag(pf, str[*i], i);
		else if ((str[*i] >= '1' && str[*i] <= '9') || str[*i] == '*')
			set_width(pf, str, i, va);
		else if (str[*i] == '.')
			set_precision(pf, str, i, va);
		else if (is_modifier(str[*i]))
			set_modifier(pf, str, i);
		else if (is_data_type(str[*i]))
		{
			pf->data_type = str[*i];
			validate_flags(pf);
		}
		else
			if_nothing(pf, str, i);
	}
}
