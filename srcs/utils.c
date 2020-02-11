/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhilary <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:40:21 by fhilary           #+#    #+#             */
/*   Updated: 2020/02/10 18:40:23 by fhilary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	display_error(char *str)
{
	ft_putendl(str);
	exit(EXIT_FAILURE);
}

t_pf	*create_pf_struct(void)
{
	t_pf	*pf;

	pf = (t_pf*)malloc(sizeof(t_pf));
	if (pf == NULL)
		display_error("Out of memory");
	ft_bzero(pf, sizeof(t_pf));
	pf->data_type = 1;
	return (pf);
}