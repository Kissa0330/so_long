/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakano   <rtakano@student.42.fr    >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 00:26:13 by rtakano           #+#    #+#             */
/*   Updated: 2022/04/10 11:50:34 by rtakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	length;
	unsigned int	i;
	char			*res;

	if (s == NULL || f == NULL)
		return (NULL);
	length = ft_strlen((char *)s);
	res = malloc((length + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		*(res + i) = f(i, *((char *)s + i));
		i++;
	}
	res[length] = '\0';
	return (res);
}
