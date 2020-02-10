/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvisser <jvisser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 18:23:00 by jvisser           #+#    #+#             */
/*   Updated: 2019/01/14 17:21:01 by jvisser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	int index;

	index = 0;
	while (((unsigned char)(s1)[index] == (unsigned char)(s2)[index])
	&& ((unsigned char)(s1)[index] && (unsigned char)(s2)[index]))
		index++;
	if ((unsigned char)(s1)[index] != (unsigned char)(s2)[index])
		return ((unsigned char)(s1)[index] - (unsigned char)(s2)[index]);
	return (0);
}
