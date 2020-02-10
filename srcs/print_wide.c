/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wide.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhilary <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:40:15 by fhilary           #+#    #+#             */
/*   Updated: 2020/02/10 18:40:17 by fhilary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		calc_diff_ws(t_pf *pf, wchar_t *str)
{
	int i;
	int	diff;
	int printlen;

	if (pf->precision > 0 && pf->precision < ft_wstrlen(str))
	{
		i = 0;
		printlen = 0;
		while (pf->precision >= (printlen + ft_wclen(str[i])))
		{
			printlen += ft_wclen(str[i]);
			i++;
		}
		diff = pf->width - printlen;
	}
	else if (pf->precision == -1)
		diff = pf->width;
	else
		diff = pf->width - ft_wstrlen(str);
	if (diff < 0)
		diff = 0;
	pf->len += diff;
	return (diff);
}

void	print_precision_ws(t_pf *pf, wchar_t *str)
{
	int	i;
	int res;

	i = 0;
	res = 0;
	if (pf->precision > 0)
	{
		while (str[i] && pf->precision && pf->precision >= ft_wclen(str[i]))
		{
			res = ft_putwchar(str[i]);
			i++;
			pf->len += res;
			pf->precision -= res;
		}
	}
	else if (pf->precision == 0)
	{
		while (str[i])
		{
			pf->len += ft_putwchar(str[i]);
			i++;
		}
	}
}

void	print_txt_ws(t_pf *pf, wchar_t *str)
{
	int		diff;
	bool	free_str;

	if (!str)
	{
		str = ft_wstrdup(L"(null)");
		free_str = true;
	}
	else
		free_str = false;
	diff = calc_diff_ws(pf, str);
	if (MIN_FLAG != 1)
		print_padding(pf, &diff);
	print_precision_ws(pf, str);
	if (diff > 0)
		ft_putcharn(' ', diff);
	if (free_str == true)
		free(str);
}

void	print_txt_wc(t_pf *pf, wchar_t c)
{
	int		diff;

	diff = 0;
	if (pf->width)
		diff = pf->width - ft_wclen(c);
	if (diff < 0)
		diff = 0;
	pf->len += diff;
	if (MIN_FLAG != 1)
	{
		if (ZERO_FLAG)
			ft_putcharn('0', diff);
		else
			ft_putcharn(' ', diff);
		diff = 0;
	}
	pf->len += ft_putwchar(c);
	ft_putcharn(' ', diff);
}
