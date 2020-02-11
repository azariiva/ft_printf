/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:35:34 by blinnea           #+#    #+#             */
/*   Updated: 2020/02/11 19:50:22 by fhilary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	iswhitespace(char c)
{
	return ((c == ' ') || (c == '\n') || c == '\t');
}

char		*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;
	size_t	len;

	if (!s)
		return (NULL);
	start = 0;
	while (s[start] && iswhitespace(s[start]))
		++start;
	if (!s[start])
		len = 0;
	else
	{
		end = ft_strlen(s) - 1;
		while (iswhitespace(s[end]))
			--end;
		len = end - start + 1;
	}
	return (ft_strsub(s, start, len));
}
