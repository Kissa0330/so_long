/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakano   <rtakano@student.42.fr    >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 22:51:42 by rtakano           #+#    #+#             */
/*   Updated: 2022/04/10 11:50:33 by rtakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	overflow(int negativeflag)
{
	if (negativeflag == -1)
		return (0);
	else
		return (-1);
}
int	ft_atoi(const char *str)
{
	int				negativeflag;
	unsigned int	num;

	num = 0;
	negativeflag = 1;
	while (*str == ' ' || *str == '\t' || *str == '\f'
		|| *str == '\r' || *str == '\n' || *str == '\v')
		str ++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			negativeflag = -1;
		str ++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if ((num * 10 + (*str - '0')) / 10 != num)
			return (overflow(negativeflag));
		num = num * 10 + (*str - '0');
		str ++;
	}
	return ((int)num * negativeflag);
}
