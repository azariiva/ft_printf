/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/04 19:21:15 by jvisser        #+#    #+#                */
/*   Updated: 2019/03/06 16:11:25 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	reset_pf(t_pf *pf)
{
	ft_bzero(pf->flag, sizeof(pf->flag));
	pf->width = 0;
	pf->precision = 0;
	ft_bzero(pf->modifier, sizeof(pf->modifier));
	pf->data_type = 0;
}

void	if_conversion(t_pf *pf, int *i)
{
	parse_placeholder(pf, pf->format, i, *(pf->valist));
	if ((pf->data_type) > 0)
		print_placeholder(pf);
	if ((pf->data_type) == -1 && (pf->format)[*i])
		print_txt_c(pf, (pf->format)[*i]);
	reset_pf(pf);
}

int		loop_format(t_pf *pf, va_list va_2)
{
	int	i;

	i = 0;
	reset_pf(pf);
	if (!(validate_next(pf, ft_strdup(pf->format), va_2)))
		return (1);
	while ((pf->format)[i])
	{
		if ((pf->format)[i] == '{')
			print_color(pf, pf->format, &i);
		if ((pf->format)[i] != '%')
			ft_putchar_add_len((pf->format)[i], pf);
		if ((pf->format)[i] == '%')
		{
			if_conversion(pf, &i);
			if (!(validate_next(pf, ft_strdup(&((pf->format)[i + 1])), va_2)))
				return (1);
		}
		if ((pf->format)[i])
			i++;
	}
	return (0);
}

int		ft_printf(const char *format, ...)
{
	int		length;
	t_pf	*pf;
	va_list	va;
	va_list	va_2;

	if (!format)
		return (-1);
	pf = create_pf_struct();
	va_start(va, format);
	va_copy(va_2, va);
	pf->valist = &va;
	pf->format = (char*)format;
	if (loop_format(pf, va_2))
		return (-1);
	va_end(va);
	va_end(va_2);
	length = pf->len;
	free(pf);
	return (length);
}
