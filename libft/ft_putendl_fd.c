/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putendln_fd.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 18:49:05 by jvisser       #+#    #+#                 */
/*   Updated: 2019/01/10 18:49:06 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putendl_fd(char const *s, int fd)
{
	if (!s)
		return ;
	while (*s)
		write(fd, s++, 1);
	write(fd, "\n", 1);
}
