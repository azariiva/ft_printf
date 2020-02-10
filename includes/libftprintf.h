/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/05 15:36:27 by jvisser        #+#    #+#                */
/*   Updated: 2019/03/07 19:58:45 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <float.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdbool.h>
# include "../libft/includes/libft.h"

typedef struct	s_pf
{
	short		options;
	int			paramater;
	int			if_param;
	char		flag[5];
	short		flags;
	int			width;
	int			precision;
	char		modifier[7];
	char		data_type;
	int			len;
	va_list		*valist;
	char		*format;
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

# define MIN_FLAG (pf->flag)[0]
# define PLUS_FLAG (pf->flag)[1]
# define SPACE_FLAG (pf->flag)[2]
# define ZERO_FLAG (pf->flag)[3]
# define HASH_FLAG (pf->flag)[4]

# define L_MOD (pf->modifier)[0]
# define LL_MOD (pf->modifier)[1]
# define H_MOD (pf->modifier)[2]
# define HH_MOD (pf->modifier)[3]
# define CAP_L_MOD (pf->modifier)[4]
# define J_MOD (pf->modifier)[5]
# define Z_MOD (pf->modifier)[6]

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
**		>>>>>>>>	MAIN_FUNCTIONS		<<<<<<<<
*/
void			reset_pf(t_pf *pf);
void			if_conversion(t_pf *pf, int *i);
int				ft_printf(const char *format, ...);
int				loop_format(t_pf *pf, va_list va_2);

/*
**		>>>>>>>>	PARSING_FUNCTIONS	<<<<<<<<
*/
void			set_flag(t_pf *pf, char c, int *i);
void			set_modifier(t_pf *pf, char *str, int *i);
void			set_width(t_pf *pf, char *str, int *i, va_list valist);
void			set_precision(t_pf *pf, char *str, int *i, va_list valist);
void			parse_placeholder(t_pf *pf, char *str, int *i, va_list valist);

/*
**		>>>>>>>>	PARSE_UTIL_FUNCTIONS<<<<<<<<
*/
int				is_flag(char c);
int				is_modifier(char c);
int				is_data_type(char c);
void			validate_flags(t_pf *pf);
void			if_nothing(t_pf *pf, char *str, int *i);

/*
**		>>>>>>>>	UTIL_FUNCTIONS		<<<<<<<<
*/
void			display_error(char *str);
t_pf			*create_pf_struct(void);
void			change_to_upper(char *tmp);
void			print_padding_add_len(char c, int *diff, t_pf *pf);

/*
**		>>>>>>>>	PRINTING_FUNCTIONS	<<<<<<<<
*/
void			print_zero_flag_num(t_pf *pf, int *diff, char *tmp);
void			print_no_zero_flag_num(t_pf *pf, int *diff, char *tmp);
void			print_precision(t_pf *pf, char *num);
void			print_padding(t_pf *pf, int *diff);

void			print_placeholder(t_pf *pf);
void			print_num(t_pf *pf);
void			print_num_d(t_pf *pf, long long num);
void			print_num_f(t_pf *pf, long double num);
void			print_txt(t_pf *pf);
void			print_txt_ws(t_pf *pf, wchar_t *str);
void			print_txt_wc(t_pf *pf, wchar_t c);
void			print_base(t_pf *pf);

void			print_txt_c(t_pf *pf, char c);
void			print_txt_s(t_pf *pf, char *str);
void			print_padding(t_pf *pf, int *diff);

void			print_b(t_pf *pf, unsigned long long num, int base);
void			print_0x(t_pf *pf, char *tmp);
void			print_ull(t_pf *pf, int *diff, char *tmp);
void			print_zero_flag_ull(t_pf *pf, int *diff, char *tmp);

/*
**		>>>>>>>>	PRINT_UTIL_FUNCTIONS	<<<<<<<<
*/
int				calc_diff(t_pf *pf, char *num);
int				set_init_diff(t_pf *pf, char *num);
void			ft_putchar_add_len(char c, t_pf *pf);
void			ft_putstr_add_len(char *str, t_pf *pf);
void			print_plus_space_flag(t_pf *pf, char *num);
void			print_padding_add_len(char c, int *diff, t_pf *pf);
void			print_zero_flag_num(t_pf *pf, int *diff, char *tmp);
void			print_zero_flag_space_plus_flag(t_pf *pf, char **tmp);
void			ft_putstrn_add_len(char const *s, size_t n, t_pf *pf);

/*
**		>>>>>>>>	VALIDATE_FUNCTIONS		<<<<<<<<
*/
size_t			is_utf8(unsigned char *str, size_t len);
size_t			check_2byte_utf8(unsigned char *str, size_t len, size_t *i,
																bool *checked);
size_t			check_3byte_utf8(unsigned char *str, size_t len, size_t *i,
																bool *checked);
size_t			check_4byte_utf8(unsigned char *str, size_t len, size_t *i,
																bool *checked);
int				validate_next(t_pf *pf, char *format, va_list valist_cpy);

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
void			print_color(t_pf *pf, char *format, int *i);

#endif
