/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhilary <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:38:28 by fhilary           #+#    #+#             */
/*   Updated: 2020/02/10 18:38:32 by fhilary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	more_bold(t_pf *pf, char *color)
{
	if (ft_strequ(color, "{bold blue}"))
	{
		pf->len += ft_putstr(ANSI_BOLD_BLUE);
		return (1);
	}
	else if (ft_strequ(color, "{bold magenta}"))
	{
		pf->len += ft_putstr(ANSI_BOLD_MAGENTA);
		return (1);
	}
	else if (ft_strequ(color, "{bold cyan}"))
	{
		pf->len += ft_putstr(ANSI_BOLD_CYAN);
		return (1);
	}
	return (0);
}

static int	bold_colors(t_pf *pf, char *color)
{
	if (ft_strequ(color, "{bold red}"))
	{
		pf->len += ft_putstr(ANSI_BOLD_RED);
		return (1);
	}
	else if (ft_strequ(color, "{bold green}"))
	{
		pf->len += ft_putstr(ANSI_BOLD_GREEN);
		return (1);
	}
	else if (ft_strequ(color, "{bold yellow}"))
	{
		pf->len += ft_putstr(ANSI_BOLD_YELLOW);
		return (1);
	}
	else if (more_bold(pf, color))
		return (1);
	return (0);
}

static int	more_colors(t_pf *pf, char *color)
{
	if (ft_strequ(color, "{blue}"))
	{
		pf->len += ft_putstr(ANSI_BLUE);
		return (1);
	}
	else if (ft_strequ(color, "{magenta}"))
	{
		pf->len += ft_putstr(ANSI_MAGENTA);
		return (1);
	}
	else if (ft_strequ(color, "{cyan}"))
	{
		pf->len += ft_putstr(ANSI_CYAN);
		return (1);
	}
	else if (ft_strequ(color, "{eoc}"))
	{
		pf->len += ft_putstr(ANSI_EOC);
		return (1);
	}
	return (0);
}

static int	check_color(t_pf *pf, char *color)
{
	if (ft_strequ(color, "{red}"))
	{
		pf->len += ft_putstr(ANSI_RED);
		return (1);
	}
	else if (ft_strequ(color, "{green}"))
	{
		pf->len += ft_putstr(ANSI_GREEN);
		return (1);
	}
	else if (ft_strequ(color, "{yellow}"))
	{
		pf->len += ft_putstr(ANSI_YELLOW);
		return (1);
	}
	else if (more_colors(pf, color))
		return (1);
	else if (bold_colors(pf, color))
		return (1);
	return (0);
}

void		print_color(t_pf *pf, char *format, int *i)
{
	int		i2;
	char	*color;

	i2 = *i;
	while (format[i2] && format[i2] != '}')
		i2++;
	if (format[i2] == '}')
	{
		color = ft_strsub(format, *i, (size_t)(i2 + 1 - *i));
		if (check_color(pf, color))
			*i = i2 + 1;
	}
}
