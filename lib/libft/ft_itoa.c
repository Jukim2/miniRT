/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:41:05 by jukim2            #+#    #+#             */
/*   Updated: 2022/11/12 13:55:10 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	get_len(int n)
{
	long long	num;
	int			len;

	len = 0;
	num = n;
	if (n < 0)
	{
		num *= -1;
		len++;
	}
	while (num >= 0)
	{
		num /= 10;
		len++;
		if (num == 0)
			break ;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*str;
	long long	num;

	len = get_len(n);
	str = malloc(sizeof(char) * len + 1);
	if (str == 0)
		return (0);
	num = n;
	if (num < 0)
	{
		num *= -1;
		str[0] = '-';
	}
	str[len--] = '\0';
	while (num >= 0)
	{
		str[len--] = num % 10 + '0';
		num /= 10;
		if (num == 0)
			break ;
	}
	return (str);
}
