/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/06 13:00:57 by jvisser        #+#    #+#                */
/*   Updated: 2019/03/06 16:06:23 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	more_bold(t_pf *pf, char *color)
{
	if (ft_strequ(color, "{bold blue}"))
	{
		ft_putstr_add_len(ANSI_BOLD_BLUE, pf);
		return (1);
	}
	else if (ft_strequ(color, "{bold magenta}"))
	{
		ft_putstr_add_len(ANSI_BOLD_MAGENTA, pf);
		return (1);
	}
	else if (ft_strequ(color, "{bold cyan}"))
	{
		ft_putstr_add_len(ANSI_BOLD_CYAN, pf);
		return (1);
	}
	return (0);
}

static int	bold_colors(t_pf *pf, char *color)
{
	if (ft_strequ(color, "{bold red}"))
	{
		ft_putstr_add_len(ANSI_BOLD_RED, pf);
		return (1);
	}
	else if (ft_strequ(color, "{bold green}"))
	{
		ft_putstr_add_len(ANSI_BOLD_GREEN, pf);
		return (1);
	}
	else if (ft_strequ(color, "{bold yellow}"))
	{
		ft_putstr_add_len(ANSI_BOLD_YELLOW, pf);
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
		ft_putstr_add_len(ANSI_BLUE, pf);
		return (1);
	}
	else if (ft_strequ(color, "{magenta}"))
	{
		ft_putstr_add_len(ANSI_MAGENTA, pf);
		return (1);
	}
	else if (ft_strequ(color, "{cyan}"))
	{
		ft_putstr_add_len(ANSI_CYAN, pf);
		return (1);
	}
	else if (ft_strequ(color, "{eoc}"))
	{
		ft_putstr_add_len(ANSI_EOC, pf);
		return (1);
	}
	return (0);
}

static int	check_color(t_pf *pf, char *color)
{
	if (ft_strequ(color, "{red}"))
	{
		ft_putstr_add_len(ANSI_RED, pf);
		return (1);
	}
	else if (ft_strequ(color, "{green}"))
	{
		ft_putstr_add_len(ANSI_GREEN, pf);
		return (1);
	}
	else if (ft_strequ(color, "{yellow}"))
	{
		ft_putstr_add_len(ANSI_YELLOW, pf);
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
