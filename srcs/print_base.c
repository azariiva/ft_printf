/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhilary <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:39:32 by fhilary           #+#    #+#             */
/*   Updated: 2020/02/10 18:39:34 by fhilary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_0x(t_pf *pf, char *tmp)
{
	if (pf->data_type == 'p')
		pf->len += ft_putstr("0x");
	else if ((pf->flag & HASH_FLAG) && tmp[0] != '0')
	{
		if (pf->data_type == 'x')
			pf->len += ft_putstr("0x");
		else if (pf->data_type == 'X')
			pf->len += ft_putstr("0X");
		else if ((pf->data_type == 'o'
			|| pf->data_type == 'O')
			&& (int)ft_strlen(tmp) >= pf->precision)
			pf->len += ft_putchar('0');
	}
}

void	print_zero_flag_ull(t_pf *pf, int *diff, char *tmp)
{
	if (tmp[0] == '-')
	{
		ft_putchar('-');
		tmp++;
	}
	else
		pf->len--;
	pf->len++;
	print_0x(pf, tmp);
	print_padding_add_len('0', diff, pf);
	pf->len += ft_putstr(tmp);
}

void	print_ull(t_pf *pf, int *diff, char *tmp)
{
	if (!(pf->flag & MIN_FLAG))
		print_padding_add_len(' ', diff, pf);
	print_0x(pf, tmp);
	print_precision(pf, tmp);
	pf->len += ft_putstr(tmp);
	print_padding_add_len(' ', diff, pf);
}

int		print_b(t_pf *pf, unsigned long long num, int base)
{
	int		diff;
	char	*tmp;

	if (!num && pf->precision == -1
	&& !((pf->flag & HASH_FLAG) && (pf->data_type == 'o' || pf->data_type == 'O')))
	{
		if (pf->data_type == 'p')
			pf->len += ft_putstr("0x");
		pf->len += pf->width;
		ft_putcharn(' ', pf->width);
		return (1);
	}
	if (!(tmp = ft_ulltoa_base(num, base)))
		return (-1);
	if (pf->data_type == 'X')
		ft_strup(tmp);
	diff = calc_diff(pf, tmp);
	if (pf->flag & ZERO_FLAG)
		print_zero_flag_ull(pf, &diff, tmp);
	else
		print_ull(pf, &diff, tmp);
	free(tmp);
	return (0);
}
