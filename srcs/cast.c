/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cast.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/04 12:39:38 by jvisser        #+#    #+#                */
/*   Updated: 2019/03/04 12:39:53 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	cast_num(t_pf *pf, va_list valist)
{
	if (LL_MOD || J_MOD || Z_MOD)
		va_arg(valist, long long);
	else if (L_MOD || pf->data_type == 'D')
		va_arg(valist, long);
	else if (HH_MOD)
		va_arg(valist, int);
	else if (H_MOD)
		va_arg(valist, int);
	else
		va_arg(valist, int);
}

void	cast_decimal(t_pf *pf, va_list valist)
{
	if (CAP_L_MOD)
		va_arg(valist, long double);
	else
		(va_arg(valist, double));
}

void	cast_txt(t_pf *pf, va_list valist)
{
	if (pf->data_type == 'S' || (pf->data_type == 's' && L_MOD))
		va_arg(valist, wchar_t*);
	else if (pf->data_type == 's')
		va_arg(valist, char*);
	if (pf->data_type == 'C' || (pf->data_type == 'c' && L_MOD))
		va_arg(valist, char*);
	else if (pf->data_type == 'c')
		va_arg(valist, char*);
}

void	cast_base(t_pf *pf, va_list valist)
{
	if (LL_MOD || J_MOD)
		va_arg(valist, unsigned long long);
	else if (L_MOD || Z_MOD || pf->data_type == 'p'
	|| pf->data_type == 'O' || pf->data_type == 'U')
		va_arg(valist, unsigned long);
	else if (HH_MOD)
		va_arg(valist, unsigned int);
	else if (H_MOD)
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
