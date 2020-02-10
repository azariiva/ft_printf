/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_txt.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/10 14:38:28 by jvisser        #+#    #+#                */
/*   Updated: 2019/03/07 16:33:34 by jvisser       ########   odam.nl         */
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
	if (ZERO_FLAG)
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
	if (MIN_FLAG != 1)
		print_padding(pf, &diff);
	if (pf->precision != -1)
	{
		if (pf->precision > 0)
			ft_putstrn_add_len(str, pf->precision, pf);
		else
			ft_putstr_add_len(str, pf);
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
	if (MIN_FLAG != 1)
	{
		if (ZERO_FLAG)
			ft_putcharn('0', diff);
		else
			ft_putcharn(' ', diff);
		diff = 0;
	}
	pf->len++;
	ft_putchar(c);
	ft_putcharn(' ', diff);
}
