/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhilary <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:37:24 by fhilary           #+#    #+#             */
/*   Updated: 2020/02/10 18:37:36 by fhilary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <float.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdbool.h>
# include "../libft/includes/libft.h"

typedef enum	e_typemod
{
	L_MOD = 1 << 0,
	LL_MOD = 1 << 1,
	H_MOD = 1 << 2,
	HH_MOD = 1 << 3,
	CAP_L_MOD = 1 << 4,
	J_MOD = 1 << 5,
	Z_MOD = 1 << 6,
}				t_typemod;

typedef enum	e_typefg
{
	MIN_FLAG = 1 << 0,
	PLUS_FLAG = 1 << 1,
	SPACE_FLAG = 1 << 2,
	ZERO_FLAG = 1 << 3,
	HASH_FLAG = 1 << 4,
}				t_typefg;

typedef struct	s_pf
{
	t_typefg	flag;
	int			width;
	int			precision;
	t_typemod	modifier;
	char		data_type;
	int			len;
}				t_pf;
/*
**	n$:	n is the number of the param to use in the format
**	If any placeholder specifies a parameter, all MUST too.
*/
/*
**	0:	'-'
**	1:	'+'
**	2:	' '
**	3:	'0'
**	4:	'#'
*/
/*
**	cannot have '+' and ' '
**	cannot have '-' and '0'
**	'#' flag needs to have correct data type
**	'-':	Left-align the output of this placeholder.
**	'+':	Sets a '+' before positive numbers.
**	' ':	Sets a ' ' before positive numbers.
**	'0':	Sets zeros before number as long as the width type.
**	'#':	Alternate form:
**			For g and G, trailing zeros are not removed.
**			For f, F, e, E, g, G, output always contains a decimal point.
**			For o, x, X, text 0, 0x, 0X, is prepended to non-zero numbers.
*/
/*
**	The argument will be in a field at least this wide and wider if necessary.
**	If the converted argument has fewer characters than the field width,
**	it will be padded on the left, or right with '-' flag
**	The padding character is ' ' (space), but '0' if zero flag is present.
**	If the field width is *, the value is from the next argument,
**	which must be an int.
*/
/*
**	A dot '.' separates the field width from the precision.
**	If the precision is *, the value is from the next argument,
**	which must be an int.
**	Conversion	Meaning
**	s:					The max number of characters to be printed from string.
**	e, E, f:			The number of digits to print after the decimal point.
**	g, G:				The number of significant digits.
**	d, i, o, u, x, X:	The minimum number of digits to be printed.
**						Leading zeros will be added to make up the field width.
*/
/*
**	modifier:	holds all different length modifiers
**	data_type:	holds the to-convert datatype
**	va_list:	holds all variable arguments
**	format:		hold the complete format of the string
*/

# define ANSI_RED "\e[0;31m"
# define ANSI_BOLD_RED "\e[1;31m"
# define ANSI_GREEN "\e[0;32m"
# define ANSI_BOLD_GREEN "\e[1;32m"
# define ANSI_YELLOW "\e[0;33m"
# define ANSI_BOLD_YELLOW "\e[1;33m"
# define ANSI_BLUE "\e[0;34m"
# define ANSI_BOLD_BLUE "\e[1;34m"
# define ANSI_MAGENTA "\e[0;35m"
# define ANSI_BOLD_MAGENTA "\e[1;35m"
# define ANSI_CYAN "\e[0;36m"
# define ANSI_BOLD_CYAN "\e[1;36m"
# define ANSI_EOC "\e[0m"

/*
**		>>>>>>>>	MAIN_FUNCTION		<<<<<<<<
*/
int				ft_printf(const char *format, ...);

/*
**		>>>>>>>>	PARSING_FUNCTIONS	<<<<<<<<
*/
void			set_flag(t_pf *pf, char c, int *i);
void			set_modifier(t_pf *pf, const char *fmt, int *i);
void			set_width(t_pf *pf, const char *fmt, va_list va, int *i);
void			set_precision(t_pf *pf, const char *fmt, int *i, va_list valist);
void			parse_placeholder(t_pf *pf, const char *fmt, int *i, va_list valist);

/*
**		>>>>>>>>	PARSE_UTIL_FUNCTIONS<<<<<<<<
*/
int				is_flag(char c);
int				is_modifier(char c);
int				is_data_type(char c);
void			validate_flags(t_pf *pf);
void			if_nothing(t_pf *pf, const char *fmt, int *i);

/*
**		>>>>>>>>	UTIL_FUNCTIONS		<<<<<<<<
*/
t_pf			*create_pf_struct(void);
void			print_padding_add_len(char c, int *diff, t_pf *pf);

/*
**		>>>>>>>>	PRINTING_FUNCTIONS	<<<<<<<<
*/
void			print_zero_flag_num(t_pf *pf, int *diff, char *tmp);
void			print_no_zero_flag_num(t_pf *pf, int *diff, char *tmp);
void			print_precision(t_pf *pf, char *num);
void			print_padding(t_pf *pf, int *diff);

void			print_placeholder(t_pf *pf, va_list va);
void			print_num(t_pf *pf, va_list va);
int				print_num_d(t_pf *pf, long long num);
int				print_num_f(t_pf *pf, long double num);
void			print_txt(t_pf *pf, va_list va);
void			print_base(t_pf *pf, va_list va);

void			print_txt_c(t_pf *pf, char c);
void			print_txt_s(t_pf *pf, char *str);
void			print_padding(t_pf *pf, int *diff);

int				print_b(t_pf *pf, unsigned long long num, int base);
void			print_0x(t_pf *pf, char *tmp);
void			print_ull(t_pf *pf, int *diff, char *tmp);
void			print_zero_flag_ull(t_pf *pf, int *diff, char *tmp);

/*
**		>>>>>>>>	PRINT_UTIL_FUNCTIONS	<<<<<<<<
*/
int				calc_diff(t_pf *pf, char *num);
int				set_init_diff(t_pf *pf, char *num);
void			print_plus_space_flag(t_pf *pf, char *num);
void			print_zero_flag_num(t_pf *pf, int *diff, char *tmp);
void			print_zero_flag_space_plus_flag(t_pf *pf, char **tmp);
/*
**		>>>>>>>>	CASTING_FUNCTIONS		<<<<<<<<
*/
void			cast_num(t_pf *pf, va_list valist);
void			cast_txt(t_pf *pf, va_list valist);
void			cast_base(t_pf *pf, va_list valist);
void			cast_decimal(t_pf *pf, va_list valist);
void			cast_placeholder(t_pf *pf, va_list valist);

/*
**		>>>>>>>>	COLOR_FUNCTIONS			<<<<<<<<
*/
void			print_color(t_pf *pf, const char *fmt, int *i);

#endif
