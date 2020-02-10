/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdel.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 10:56:33 by jvisser       #+#    #+#                 */
/*   Updated: 2019/01/11 10:56:34 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*next;

	if (alst != NULL && del != NULL)
	{
		while (*alst)
		{
			del((*alst)->content, (*alst)->content_size);
			next = (*alst)->next;
			free(*alst);
			*alst = NULL;
			*alst = next;
		}
	}
}
