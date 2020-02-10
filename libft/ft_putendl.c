/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putendl.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 18:07:58 by jvisser       #+#    #+#                 */
/*   Updated: 2019/01/10 18:07:59 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putendl(char const *s)
{
	if (!s)
		return ;
	while (*s)
		write(1, s++, 1);
	write(1, "\n", 1);
}
