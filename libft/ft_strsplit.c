/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsplit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 14:36:04 by jvisser        #+#    #+#                */
/*   Updated: 2019/02/12 14:55:56 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static	int		countwords(char const *s, char c)
{
	int	index;
	int	result;

	index = 0;
	result = 0;
	while (s[index] == c && c != '\0')
		index++;
	while (s[index])
	{
		while (s[index] != c && s[index])
			index++;
		while (s[index] == c && s[index])
			index++;
		result++;
	}
	return (result);
}

static	int		countletters(char *s, char c)
{
	int	result;

	result = 0;
	while (s[result] != c)
		result++;
	return (result);
}

static	void	fill_array(char *result, char *s, int letters)
{
	int	index;

	index = 0;
	while (index != letters)
	{
		result[index] = s[index];
		index++;
	}
	result[index] = '\0';
}

static void		make_array(char **result, int words, const char *s, char c)
{
	int	index_w;
	int	index_s;
	int	letters;

	index_w = 0;
	index_s = 0;
	letters = 0;
	while (index_w < words)
	{
		while (s[index_s] == c)
			index_s++;
		letters = countletters((char*)&s[index_s], c);
		result[index_w] = (char *)malloc(letters + 1);
		if (!result[index_w])
			return ;
		fill_array(result[index_w], (char*)&s[index_s], letters);
		index_s += letters;
		index_w++;
	}
	result[index_w] = NULL;
}

char			**ft_strsplit(char const *s, char c)
{
	int		words;
	char	**result;

	if (!s)
		return (NULL);
	words = countwords(s, c);
	result = (char**)malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	make_array(result, words, s, c);
	return (result);
}
