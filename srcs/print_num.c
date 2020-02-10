/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhilary <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:39:47 by fhilary           #+#    #+#             */
/*   Updated: 2020/02/10 18:39:50 by fhilary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	num_prec_zero(t_pf *pf)
{
	if (PLUS_FLAG || SPACE_FLAG)
		pf->width--;
	if (MIN_FLAG != 1 && pf->width > 0)
		print_padding_add_len(' ', &(pf->width), pf);
	if (PLUS_FLAG)
		ft_putchar_add_len('+', pf);
	if (SPACE_FLAG)
		ft_putchar_add_len(' ', pf);
	if (pf->width > 0)
		ft_putcharn(' ', pf->width);
}

void	print_zero_flag_space_plus_flag(t_pf *pf, char **tmp)
{
	if ((*tmp)[0] == '-')
	{
		ft_putchar_add_len('-', pf);
		(*tmp)++;
	}
	else if (PLUS_FLAG)
		ft_putchar_add_len('+', pf);
	else if (SPACE_FLAG)
		ft_putchar_add_len(' ', pf);
}

void	print_zero_flag_num(t_pf *pf, int *diff, char *tmp)
{
	if (tmp[0] == '-')
		pf->width--;
	if ((PLUS_FLAG == 1 || SPACE_FLAG == 1) && tmp[0] != '-')
		(*diff)--;
	if (pf->precision == -1 && pf->data_type != 'f' && pf->data_type != 'F')
		pf->precision = (int)ft_strlen(tmp);
	while (pf->precision > 0 && pf->width > pf->precision
	&& (pf->data_type != 'f' && pf->data_type != 'F') && *diff > 0)
	{
		ft_putchar_add_len(' ', pf);
		pf->width--;
		(*diff)--;
	}
	print_zero_flag_space_plus_flag(pf, &tmp);
	while ((*diff) > 0)
	{
		ft_putchar_add_len('0', pf);
		(*diff)--;
	}
	print_precision(pf, tmp);
	ft_putstr_add_len(tmp, pf);
}

void	print_no_zero_flag_num(t_pf *pf, int *diff, char *tmp)
{
	if (MIN_FLAG != 1)
		print_padding_add_len(' ', diff, pf);
	print_plus_space_flag(pf, tmp);
	if (tmp[0] == '-')
	{
		ft_putchar_add_len('-', pf);
		print_precision(pf, tmp);
		ft_putstr_add_len(&tmp[1], pf);
	}
	else
	{
		print_precision(pf, tmp);
		ft_putstr_add_len(tmp, pf);
	}
	print_padding_add_len(' ', diff, pf);
}

void	print_num_d(t_pf *pf, long long num)
{
	int		diff;
	char	*tmp;

	if (!num && pf->precision == -1)
	{
		num_prec_zero(pf);
		return ;
	}
	tmp = ft_lltoa(num);
	if (!tmp)
		display_error("Out of memory");
	diff = calc_diff(pf, tmp);
	if (ZERO_FLAG == 1)
		print_zero_flag_num(pf, &diff, tmp);
	else
		print_no_zero_flag_num(pf, &diff, tmp);
	free(tmp);
}
