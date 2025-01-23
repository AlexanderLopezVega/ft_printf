/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-v <alopez-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:42:36 by alopez-v          #+#    #+#             */
/*   Updated: 2025/01/20 16:06:41 by alopez-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_fd_rec(int n, int fd)
{
	if (n > -10 && n < 10)
	{
		if (n < 0)
			ft_putchar_fd(-n + '0', fd);
		else
			ft_putchar_fd(n + '0', fd);
	}
	else
	{
		ft_putnbr_fd_rec(n / 10, fd);
		ft_putnbr_fd_rec(n % 10, fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	ft_putnbr_fd_rec(n, fd);
}
