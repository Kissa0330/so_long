/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakano   <rtakano@student.42.fr    >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 22:32:26 by rtakano           #+#    #+#             */
/*   Updated: 2022/04/10 11:50:34 by rtakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*tostr(unsigned int n, int len)
{
	char	*res;

	res = malloc((len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	res[len] = '\0';
	while (len--)
	{
		res[len] = n % 10 + '0';
		n /= 10;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	size_t	len;
	long	i;

	len = 1;
	i = n;
	while (n / 10)
	{
		len++;
		n /= 10;
	}
	if (n < 0)
	{
		i *= -1;
		len ++;
	}
	res = tostr(i, len);
	if (res == NULL)
		return (NULL);
	if (n < 0)
		res[0] = '-';
	return (res);
}
