/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcat.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 14:58:15 by jvisser        #+#    #+#                */
/*   Updated: 2019/02/12 15:01:18 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *s1, const char *s2)
{
	int	index_s1;
	int	index_s2;

	index_s1 = 0;
	index_s2 = 0;
	while (s1[index_s1])
		index_s1++;
	while (s2[index_s2])
	{
		s1[index_s1] = s2[index_s2];
		index_s1++;
		index_s2++;
	}
	s1[index_s1] = '\0';
	return (s1);
}
