/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/06 17:13:21 by jvisser        #+#    #+#                */
/*   Updated: 2019/03/01 18:30:14 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_num(t_pf *pf)
{
	long long	n;

	if (LL_MOD || J_MOD || Z_MOD)
		n = va_arg(*(pf->valist), long long);
	else if (L_MOD || pf->data_type == 'D')
		n = (long long)va_arg(*(pf->valist), long);
	else if (HH_MOD)
		n = (long long)((signed char)(va_arg(*(pf->valist), int)));
	else if (H_MOD)
		n = (long long)((short)(va_arg(*(pf->valist), int)));
	else
		n = (long long)va_arg(*(pf->valist), int);
	print_num_d(pf, n);
}

void	print_decimal(t_pf *pf)
{
	long double	n;

	if (!(pf->precision))
		pf->precision = 6;
	if (CAP_L_MOD)
		n = va_arg(*(pf->valist), long double);
	else if (L_MOD)
		n = (long double)(va_arg(*(pf->valist), double));
	else
		n = (long double)(va_arg(*(pf->valist), double));
	print_num_f(pf, n);
}

void	print_txt(t_pf *pf)
{
	if (pf->data_type == 'S' || (pf->data_type == 's' && L_MOD))
		print_txt_ws(pf, va_arg(*(pf->valist), wchar_t*));
	else if (pf->data_type == 's')
		print_txt_s(pf, va_arg(*(pf->valist), char*));
	if (pf->data_type == 'C' || (pf->data_type == 'c' && L_MOD))
		print_txt_wc(pf, (wchar_t)(va_arg(*(pf->valist), char*)));
	else if (pf->data_type == 'c')
		print_txt_c(pf, (char)(va_arg(*(pf->valist), char*)));
	if (pf->data_type == '%')
		print_txt_c(pf, '%');
}

void	print_base(t_pf *pf)
{
	int					base;
	unsigned long long	n;

	if (pf->data_type == 'o' || pf->data_type == 'O')
		base = 8;
	else if (pf->data_type == 'x' || pf->data_type == 'X'
	|| pf->data_type == 'p')
		base = 16;
	else
		base = 10;
	n = 0;
	if (LL_MOD || J_MOD)
		n = va_arg(*(pf->valist), unsigned long long);
	else if (L_MOD || Z_MOD || pf->data_type == 'p'
	|| pf->data_type == 'O' || pf->data_type == 'U')
		n = (unsigned long long)va_arg(*(pf->valist), unsigned long);
	else if (HH_MOD)
		n = (unsigned long long)((unsigned char)va_arg(*(pf->valist),
			unsigned int));
	else if (H_MOD)
		n = (unsigned long long)((unsigned short)va_arg(*(pf->valist),
			unsigned int));
	else
		n = (unsigned long long)va_arg(*(pf->valist), unsigned int);
	print_b(pf, n, base);
}

void	print_placeholder(t_pf *pf)
{
	if (pf->data_type == 'd' || pf->data_type == 'D'
	|| pf->data_type == 'i')
		print_num(pf);
	if (pf->data_type == 'f' || pf->data_type == 'F')
		print_decimal(pf);
	else if (pf->data_type == 'o' || pf->data_type == 'O'
	|| pf->data_type == 'u' || pf->data_type == 'U'
	|| pf->data_type == 'x' || pf->data_type == 'X'
	|| pf->data_type == 'p')
		print_base(pf);
	else if (pf->data_type == 's' || pf->data_type == 'S'
	|| pf->data_type == 'c' || pf->data_type == 'C'
	|| pf->data_type == '%')
		print_txt(pf);
}
