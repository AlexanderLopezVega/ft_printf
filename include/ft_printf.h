/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-v <alopez-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:19:51 by alopez-v          #+#    #+#             */
/*   Updated: 2025/01/23 16:23:14 by alopez-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>

# define FORMAT_SPECIFIER_CHAR '%'

size_t	ft_exponentlen(const double num);
char	*ft_getaddr(const void *addr);
char	*ft_getchar(const int c);
char	*ft_getdec(const double dec);
char	*ft_getint(const int i);
char	*ft_getlowhex(const unsigned long long i);
char	*ft_getstr(const char *str);
char	*ft_getudec(const double dec);
char	*ft_getupphex(const unsigned long long i);
size_t	ft_mantissalen(const double num);
int		ft_printf(const char *format, ...);
char	*ft_tohexstr(const unsigned long long num, const char *hex_dic,
			const size_t digits);
char	*ft_varstr(const char *format, va_list args);

#endif