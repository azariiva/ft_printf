/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 17:32:50 by jvisser       #+#    #+#                 */
/*   Updated: 2019/01/09 17:32:52 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int	index;

	index = 0;
	while (s[index] != '\0')
		index++;
	if (c == '\0')
		return ((char *)&s[index]);
	while (index >= 0)
	{
		if (s[index] == c)
			return ((char *)&s[index]);
		index--;
	}
	return (NULL);
}
