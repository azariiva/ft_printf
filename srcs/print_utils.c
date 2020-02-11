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

void	ft_putchar_add_len(char c, t_pf *pf)
{
	write(1, &c, 1);
	pf->len++;
}

void	ft_putstr_add_len(char *str, t_pf *pf)
{
	int	i;

	i = 0;
	pf->len += ft_strlen(str);
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	print_plus_space_flag(t_pf *pf, char *num)
{
	if ((pf->flag & PLUS_FLAG) && num[0] != '-')
		ft_putchar_add_len('+', pf);
	if ((pf->flag & SPACE_FLAG) && num[0] != '-')
		ft_putchar_add_len(' ', pf);
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
