/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 11:15:45 by apecci            #+#    #+#             */
/*   Updated: 2021/02/17 11:15:46 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef	struct	s_printableobject
{
	char	tipo;
	int		precision;
	int		width;
	int		minus;
	int		zero;
	int		zompa;
	int		j;
	int		contatore;
	int		i;
}				t_printabile;

t_printabile	ft_initialize(t_printabile p);
size_t			hexlenght_long(size_t n);
char			*hexadecimalconvert_long(size_t n);
int				num_of_digits(long long n);
void			ft_putchar_fd(int c, int fd);
int				ft_strlen_const(const char *s);
int				ft_strlen(char *s);
int				ft_ndigit(int n);
char			*ft_itoa(int nb);
void			ft_putnbr_fd(unsigned int n, int fd);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				is_number(char c);
t_printabile	putstr_contatore(t_printabile p, char *support);
int				is_checkable(char c);
char			ft_find_tipo(const char *s, int i);
int				ft_find_precision(const char *s, int k, va_list lista);
t_printabile	ft_find_precision_string(t_printabile p, const char *s,
				int i, int j);
t_printabile	ft_set_minus(t_printabile p, const char *s,
				int i, int j);
t_printabile	ft_find_width_string(t_printabile p, const char *s,
				int i, va_list list);
t_printabile	ft_find_width_param(t_printabile p, const char *s,
				int i, va_list list);
t_printabile	ft_set_zero(t_printabile p);
t_printabile	ft_find_precision_support(t_printabile p, const char *s,
				int i, va_list list);
t_printabile	ft_find_flags_support(t_printabile p, const char *s,
				int i, va_list list);
t_printabile	ft_find_flags(t_printabile p, const char *s,
				int i, va_list list);
t_printabile	ft_percent(t_printabile p);
t_printabile	ft_putchar_simple(t_printabile p, const char *s);
t_printabile	ft_char(t_printabile p, va_list list);
t_printabile	ft_print_support_until_prec(t_printabile p, char *support);
t_printabile	ft_print_width_till_num_of_spaces(t_printabile p,
				int num_of_spaces);
t_printabile	ft_string_handle_null(t_printabile p, int num_of_spaces);
t_printabile	ft_print_until_diff(t_printabile p, int diff, char *to_print);
t_printabile	ft_string_support_1(t_printabile p, char *support);
t_printabile	ft_string_support_2(t_printabile p, char *support);
t_printabile	ft_string(t_printabile p, va_list list);
char			*ft_str_to_lower(char *support);
t_printabile	ft_int_helper_1 (t_printabile p, int num, char *support);
t_printabile	ft_int_helper_2 (t_printabile p, int num, char *support);
t_printabile	ft_int_helper_3(t_printabile p, int num, char *support);
t_printabile	ft_int_helper_4(t_printabile p);
t_printabile	ft_int_handler(t_printabile p, va_list list);
t_printabile	ft_hex_handle_zero_support_3(t_printabile p);
t_printabile	ft_hex_helper_3(t_printabile p, char *support);
t_printabile	ft_hex_handle_zero_support(t_printabile p);
t_printabile	ft_hex_handle_zero_support1(t_printabile p);
t_printabile	ft_hex_handle_zero(t_printabile p);
char			*ft_str_to_lower(char *support);
t_printabile	ft_hex_helper_1(t_printabile p, char *support);
t_printabile	ft_hex_support1(t_printabile p, char *support);
t_printabile	ft_hex_handler(t_printabile p, va_list list);
t_printabile	ft_unsigned_helper_4(t_printabile p, unsigned int num2);
t_printabile	ft_unsigned_helper_1(t_printabile p, unsigned int support);
t_printabile	ft_precision_zero_handler(t_printabile p, unsigned int num2);
t_printabile	ft_unsigned_helper_2(t_printabile p,
				long support_unsigned_num);
t_printabile	ft_unsigned(t_printabile p, va_list list);
t_printabile	ft_pointer_handler_null_argument(t_printabile p);
t_printabile	ft_pointer_handle_multiple_flags(t_printabile p, char *support);
t_printabile	ft_pointer(t_printabile p, va_list list);
t_printabile	ft_grande_while_2(t_printabile p, va_list list);
t_printabile	ft_grande_while(t_printabile p, const char *s, va_list list);
int				ft_parser(const char *s, va_list list);
int				ft_printf(char const *str, ...);

#endif
