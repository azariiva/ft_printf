/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_listiter.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 11:22:41 by jvisser       #+#    #+#                 */
/*   Updated: 2019/01/11 11:22:41 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	while (lst && f)
	{
		f(lst);
		lst = lst->next;
	}
}
