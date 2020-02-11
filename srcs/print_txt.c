/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_txt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhilary <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:39:55 by fhilary           #+#    #+#             */
/*   Updated: 2020/02/10 18:39:57 by fhilary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		calc_diff_s(t_pf *pf, char *str)
{
	int	diff;

	if (pf->precision > 0 && pf->precision < (int)ft_strlen(str))
		diff = pf->width - pf->precision;
	else if (pf->precision == -1)
		diff = pf->width;
	else
		diff = pf->width - ft_strlen(str);
	if (diff < 0)
		diff = 0;
	pf->len += diff;
	return (diff);
}

void	print_padding(t_pf *pf, int *diff)
{
	if (pf->flag & ZERO_FLAG)
		ft_putcharn('0', *diff);
	else
		ft_putcharn(' ', *diff);
	*diff = 0;
}

void	print_txt_s(t_pf *pf, char *str)
{
	int		diff;
	bool	free_b;

	if (!str)
	{
		str = ft_strdup("(null)");
		free_b = true;
	}
	else
		free_b = false;
	diff = calc_diff_s(pf, str);
	if (!(pf->flag & MIN_FLAG))
		print_padding(pf, &diff);
	if (pf->precision != -1)
	{
		if (pf->precision > 0)
			pf->len += ft_putstrn(str, pf->precision);
		else
			pf->len += ft_putstr(str);
	}
	if (diff > 0)
		ft_putcharn(' ', diff);
	if (free_b == true)
		free(str);
}

void	print_txt_c(t_pf *pf, char c)
{
	int		diff;

	diff = 0;
	if (pf->width > 0)
		diff = pf->width - 1;
	pf->len += diff;
	if (!(pf->flag & MIN_FLAG))
	{
		if (pf->flag & ZERO_FLAG)
			ft_putcharn('0', diff);
		else
			ft_putcharn(' ', diff);
		diff = 0;
	}
	pf->len++;
	ft_putchar(c);
	ft_putcharn(' ', diff);
}
