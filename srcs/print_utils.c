/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhilary <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:40:01 by fhilary           #+#    #+#             */
/*   Updated: 2020/02/10 18:40:04 by fhilary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_padding_add_len(char c, int *diff, t_pf *pf)
{
	pf->len += *diff;
	ft_putcharn(c, *diff);
	*diff = 0;
}

void	print_plus_space_flag(t_pf *pf, char *num)
{
	if ((pf->flag & PLUS_FLAG) && num[0] != '-')
		pf->len += ft_putchar('+');
	if ((pf->flag & SPACE_FLAG) && num[0] != '-')
		pf->len += ft_putchar(' ');
}

void	ft_putstrn_add_len(char const *s, size_t n, t_pf *pf)
{
	int index;

	index = 0;
	while (s[index] && n)
	{
		write(1, &s[index], 1);
		pf->len++;
		index++;
		n--;
	}
}
