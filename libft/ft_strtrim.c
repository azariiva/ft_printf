/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvisser <jvisser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:08:32 by jvisser           #+#    #+#             */
/*   Updated: 2019/01/14 16:38:22 by jvisser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static	char	*if_empty(char *result)
{
	if (!(result = (char*)malloc(1)))
		return (NULL);
	result[0] = '\0';
	return (result);
}

char			*ft_strtrim(char const *s)
{
	int		index;
	int		index_result;
	int		end_index;
	char	*result;

	if (!s)
		return (NULL);
	index = 0;
	while (s[index] == ' ' || s[index] == '\t' || s[index] == '\n')
		index++;
	end_index = 0;
	while (s[end_index + 1])
		end_index++;
	while (s[end_index] == ' ' || s[end_index] == '\t' || s[end_index] == '\n')
		end_index--;
	result = NULL;
	if (index > end_index)
		return (if_empty(result));
	if (!(result = (char *)malloc(end_index - index + 2)))
		return (NULL);
	index_result = 0;
	while (index <= end_index)
		result[index_result++] = s[index++];
	result[index_result] = '\0';
	return (result);
}
