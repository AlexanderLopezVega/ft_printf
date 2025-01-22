/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-v <alopez-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:19:51 by alopez-v          #+#    #+#             */
/*   Updated: 2025/01/22 17:01:03 by alopez-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>

# define FORMAT_SPECIFIER_CHAR '%'

void	ft_printf(const char *format, ...);
void	ft_variadic(const unsigned int n, ...);
size_t	ft_count_format_specifiers(const char *str, const char format_specifier);

#endif