/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 18:00:13 by jvisser       #+#    #+#                 */
/*   Updated: 2019/01/09 18:00:13 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	index_h;
	size_t	index_n;

	index_h = 0;
	index_n = 0;
	if (!needle[index_n])
		return ((char *)haystack);
	while (haystack[index_h] != '\0' && index_h < len)
	{
		index_n = 0;
		while (haystack[index_h + index_n] == needle[index_n]
				&& index_h + index_n < len)
		{
			index_n++;
			if (needle[index_n] == '\0')
				return ((char *)&haystack[index_h]);
		}
		index_h++;
	}
	return (NULL);
}
