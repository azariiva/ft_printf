/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvisser <jvisser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 12:37:22 by jvisser           #+#    #+#             */
/*   Updated: 2019/01/17 13:20:20 by jvisser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstnadd(t_list **alst, t_list *new, size_t n)
{
	t_list	*temp;

	if (!n)
	{
		ft_lstadd(alst, new);
		return ;
	}
	temp = *alst;
	while (temp)
	{
		if (!--n || !temp->next)
		{
			new->next = temp->next;
			temp->next = new;
			return ;
		}
		temp = temp->next;
	}
}
