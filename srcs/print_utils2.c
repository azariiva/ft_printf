/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhilary <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:40:08 by fhilary           #+#    #+#             */
/*   Updated: 2020/02/10 18:40:11 by fhilary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		set_init_diff(t_pf *pf, char *num)
{
	int	result;

	result = 0;
	if (num[0] == '-')
	{
		if (pf->precision > (int)ft_strlen(&num[1]))
			result = pf->width - (pf->precision + 1);
		else
			result = pf->width - ft_strlen(num);
	}
	else
	{
		if (pf->precision > (int)ft_strlen(num))
			result = pf->width - pf->precision;
		else
			result = pf->width - ft_strlen(num);
	}
	return (result);
}

int		calc_diff(t_pf *pf, char *num)
{
	int	result;

	result = set_init_diff(pf, num);
	if (!(pf->flag & ZERO_FLAG) && (((pf->flag & PLUS_FLAG) && num[0] != '-')
	|| ((pf->flag & SPACE_FLAG) && num[0] != '-')))
		result--;
	if (pf->data_type == 'p'
	|| ((pf->flag & HASH_FLAG) && (pf->data_type == 'x'
	|| pf->data_type == 'X') && num[0] != '0'))
		result -= 2;
	if (((pf->flag & HASH_FLAG) && (pf->data_type == 'o' || pf->data_type == 'O')
	&& num[0] != '0') && pf->precision <= (int)ft_strlen(num))
		result--;
	if (result < 0)
		result = 0;
	return (result);
}

void	print_precision(t_pf *pf, char *num)
{
	if (num[0] == '-')
	{
		while (pf->precision > 0 && pf->precision > (int)ft_strlen(&num[1]))
		{
			write(1, "0", 1);
			pf->len++;
			pf->precision--;
		}
	}
	else
	{
		while (pf->precision > 0 && pf->precision > (int)ft_strlen(num))
		{
			write(1, "0", 1);
			pf->len++;
			pf->precision--;
		}
	}
}
