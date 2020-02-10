/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 11:27:12 by jvisser        #+#    #+#                */
/*   Updated: 2019/02/12 14:33:46 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*first_adress;
	t_list	*tmp_new;
	t_list	*new;

	if (!lst || !f)
		return (NULL);
	new = f(lst);
	first_adress = ft_lstnew(new->content, new->content_size);
	if (first_adress)
	{
		tmp_new = first_adress;
		lst = lst->next;
		while (lst)
		{
			new = f(lst);
			tmp_new->next = ft_lstnew(new->content, new->content_size);
			if (!(tmp_new->next))
				return (NULL);
			tmp_new = tmp_new->next;
			lst = lst->next;
		}
	}
	return (first_adress);
}
