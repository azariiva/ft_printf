/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhilary <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:39:10 by fhilary           #+#    #+#             */
/*   Updated: 2020/02/10 18:39:13 by fhilary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	set_flag(t_pf *pf, char c, int *i)
{
	if (c == '-')
		pf->flag |= MIN_FLAG;
	else if (c == '+')
		pf->flag |= PLUS_FLAG;
	else if (c == ' ')
		pf->flag |= SPACE_FLAG;
	else if (c == '0')
		pf->flag |= ZERO_FLAG;
	else if (c == '#')
		pf->flag |= HASH_FLAG;
	(*i)++;
}

void	set_width(t_pf *pf, char *fmt, int *i, va_list valist)
{
	long	w;

	if (fmt[*i] == '*')
	{
		w = (long)va_arg(valist, int);
		if (w < 0)
		{
			w *= -1;
			pf->flag |= MIN_FLAG;
		}
		pf->width = (int)w;
		(*i)++;
	}
	else
	{
		pf->width = ft_atoi(&fmt[*i]);
		while (fmt[*i] >= '0' && fmt[*i] <= '9')
			(*i)++;
	}
}

void	set_precision(t_pf *pf, char *fmt, int *i, va_list valist)
{
	long	w;

	(*i)++;
	if (fmt[*i] == '*')
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
		pf->precision = ft_atoi(&fmt[*i]);
		if (pf->precision <= 0)
			pf->precision = -1;
	}
	while (fmt[*i] >= '0' && fmt[*i] <= '9')
		(*i)++;
}

void	set_modifier(t_pf *pf, char *fmt, int *i)
{
	if (fmt[*i] == 'l')
	{
		if (fmt[(*i) + 1] == 'l')
			pf->modifier |= LL_MOD;
		else
			pf->modifier |= L_MOD;
	}
	if (fmt[*i] == 'h')
	{
		if (fmt[(*i) + 1] == 'h')
			pf->modifier |= HH_MOD;
		else
			pf->modifier |= H_MOD;
	}
	if (fmt[*i] == 'L')
		pf->modifier |= CAP_L_MOD;
	if (fmt[*i] == 'j')
		pf->modifier |= J_MOD;
	if (fmt[*i] == 'z')
		pf->modifier |= Z_MOD;
	(*i)++;
}

void	parse_placeholder(t_pf *pf, char *fmt, int *i, va_list va)
{
	(*i)++;
	while (!(pf->data_type))
	{
		if (is_flag(fmt[*i]))
			set_flag(pf, fmt[*i], i);
		else if ((fmt[*i] >= '1' && fmt[*i] <= '9') || fmt[*i] == '*')
			set_width(pf, fmt, i, va);
		else if (fmt[*i] == '.')
			set_precision(pf, fmt, i, va);
		else if (is_modifier(fmt[*i]))
			set_modifier(pf, fmt, i);
		else if (is_data_type(fmt[*i]))
		{
			pf->data_type = fmt[*i];
			validate_flags(pf);
		}
		else
			if_nothing(pf, fmt, i);
	}
}
