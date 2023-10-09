/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:45:11 by jukim2            #+#    #+#             */
/*   Updated: 2022/11/12 11:32:54 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long	num;
	char		ch;

	num = n;
	if (fd < 0)
	{
		return ;
	}
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_fd(num * (-1), fd);
		return ;
	}
	ch = n % 10 + '0';
	if (n / 10 != 0)
		ft_putnbr_fd(n / 10, fd);
	write (fd, &ch, 1);
}
