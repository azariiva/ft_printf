/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchri.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/12 15:32:02 by jvisser        #+#    #+#                */
/*   Updated: 2019/02/12 15:32:15 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_strchri(const char *s, char c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
