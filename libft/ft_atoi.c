/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:18:05 by jukim2            #+#    #+#             */
/*   Updated: 2022/11/12 18:53:51 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	long long	num;
	long long	is_minus;

	num = 0;
	is_minus = 0;
	while ((9 <= *str && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
		is_minus = *(str++) - '+';
	while ('0' <= *str && *str <= '9')
	{
		num *= 10;
		num += *(str++) - '0';
	}
	if (is_minus)
		num *= -1;
	return (num);
}
