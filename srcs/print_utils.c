/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhilary <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:40:01 by fhilary           #+#    #+#             */
/*   Updated: 2020/02/12 20:19:37 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_plus_space_flag(t_pf *pf, char *num)
{
	if ((pf->flag & PLUS_FLAG) && num[0] != '-')
		pf->len += ft_putchar_buf(&(pf->buf), '+');
	if ((pf->flag & SPACE_FLAG) && num[0] != '-')
		pf->len += ft_putchar_buf(&(pf->buf), ' ');
}

int		calc_diff(t_pf *pf, char *num)
{
	int	res;

	if (num[0] == '-')
		res = (pf->prec > (int)ft_strlen(num + 1) ? pf->width - (pf->prec + 1) \
				: pf->width - ft_strlen(num));
	else
		res = (pf->prec > (int)ft_strlen(num) ? pf->width - pf->prec : \
				pf->width - ft_strlen(num));
	if (!(pf->flag & ZERO_FLAG) && (((pf->flag & PLUS_FLAG) && num[0] != '-') \
				|| ((pf->flag & SPACE_FLAG) && num[0] != '-')))
		res--;
	if (pf->data_type == 'p' || ((pf->flag & HASH_FLAG) && \
				(pf->data_type == 'x' || pf->data_type == 'X') && \
				num[0] != '0'))
		res -= 2;
	if (((pf->flag & HASH_FLAG) && (pf->data_type == 'o' || \
					pf->data_type == 'O') && num[0] != '0') && \
						pf->prec <= (int)ft_strlen(num))
		res--;
	return (res < 0 ? 0 : res);
}

void	print_precision(t_pf *pf, char *num)
{
	if (num[0] == '-')
		while (pf->prec > 0 && pf->prec > (int)ft_strlen(&num[1]))
		{
			pf->len += ft_putchar_buf(&(pf->buf), '0');
			pf->prec--;
		}
	else
		while (pf->prec > 0 && pf->prec > (int)ft_strlen(num))
		{
			pf->len += ft_putchar_buf(&(pf->buf), '0');
			pf->prec--;
		}
}
