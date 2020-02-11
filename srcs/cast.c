/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhilary <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:38:17 by fhilary           #+#    #+#             */
/*   Updated: 2020/02/10 18:38:22 by fhilary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	cast_num(t_pf *pf, va_list valist)
{
	if ((pf->modifier & LL_MOD) || (pf->modifier & J_MOD) || (pf->modifier & Z_MOD))
		va_arg(valist, long long);
	else if ((pf->modifier & L_MOD) || pf->data_type == 'D')
		va_arg(valist, long);
	else if (pf->modifier & HH_MOD)
		va_arg(valist, int);
	else if (pf->modifier & H_MOD)
		va_arg(valist, int);
	else
		va_arg(valist, int);
}

void	cast_decimal(t_pf *pf, va_list valist)
{
	if (pf->modifier & CAP_L_MOD)
		va_arg(valist, long double);
	else
		(va_arg(valist, double));
}

void	cast_txt(t_pf *pf, va_list valist)
{
	if (pf->data_type == 'S' || (pf->data_type == 's' && (pf->modifier & L_MOD)))
		va_arg(valist, wchar_t*);
	else if (pf->data_type == 's')
		va_arg(valist, char*);
	if (pf->data_type == 'C' || (pf->data_type == 'c' && (pf->modifier & L_MOD)))
		va_arg(valist, char*);
	else if (pf->data_type == 'c')
		va_arg(valist, char*);
}

void	cast_base(t_pf *pf, va_list valist)
{
	if ((pf->modifier & LL_MOD) || (pf->modifier & J_MOD))
		va_arg(valist, unsigned long long);
	else if ((pf->modifier & L_MOD) || (pf->modifier & Z_MOD) || pf->data_type == 'p'
	|| pf->data_type == 'O' || pf->data_type == 'U')
		va_arg(valist, unsigned long);
	else if (pf->modifier & HH_MOD)
		va_arg(valist, unsigned int);
	else if (pf->modifier & H_MOD)
		va_arg(valist, unsigned int);
	else
		va_arg(valist, unsigned int);
}

void	cast_placeholder(t_pf *pf, va_list valist)
{
	if (pf->data_type == 'd' || pf->data_type == 'D'
	|| pf->data_type == 'i')
		cast_num(pf, valist);
	if (pf->data_type == 'f' || pf->data_type == 'F')
		cast_decimal(pf, valist);
	else if (pf->data_type == 'o' || pf->data_type == 'O'
	|| pf->data_type == 'u' || pf->data_type == 'U'
	|| pf->data_type == 'x' || pf->data_type == 'X'
	|| pf->data_type == 'p')
		cast_base(pf, valist);
	else if (pf->data_type == 's' || pf->data_type == 'S'
	|| pf->data_type == 'c' || pf->data_type == 'C'
	|| pf->data_type == '%')
		cast_txt(pf, valist);
}
