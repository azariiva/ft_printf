/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/05 17:13:21 by jvisser        #+#    #+#                */
/*   Updated: 2019/03/01 18:30:19 by jvisser       ########   odam.nl         */
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

void	change_to_upper(char *tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		if (tmp[i] >= 'a' && tmp[i] <= 'z')
			tmp[i] -= 32;
		i++;
	}
}
