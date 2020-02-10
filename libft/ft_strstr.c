/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 17:38:58 by jvisser       #+#    #+#                 */
/*   Updated: 2019/01/09 17:38:58 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	index_h;
	int index_n;

	index_h = 0;
	index_n = 0;
	if (!needle[index_n])
		return ((char *)haystack);
	while (haystack[index_h])
	{
		index_n = 0;
		while (haystack[index_h + index_n] == needle[index_n])
		{
			index_n++;
			if (needle[index_n] == '\0')
				return ((char *)&haystack[index_h]);
		}
		index_h++;
	}
	return (NULL);
}
