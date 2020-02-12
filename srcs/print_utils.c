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

void	print_plus_space_flag(t_pf *pf, char *num)
{
	if ((pf->flag & PLUS_FLAG) && num[0] != '-')
		pf->len += ft_putchar_buf(&(pf->buf), '+');
	if ((pf->flag & SPACE_FLAG) && num[0] != '-')
		pf->len += ft_putchar_buf(&(pf->buf), ' ');
}
