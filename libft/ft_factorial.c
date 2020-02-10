/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_factorial.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 19:03:19 by jvisser        #+#    #+#                */
/*   Updated: 2019/02/12 14:22:17 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_factorial(int nb)
{
	int result;

	result = nb;
	if (nb < 0 || nb > 12)
		return (0);
	if (nb == 0)
		return (1);
	while (nb > 1)
	{
		nb--;
		result = result * nb;
	}
	return (result);
}
