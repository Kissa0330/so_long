/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakano   <rtakano@student.42.fr    >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 12:21:49 by rtakano           #+#    #+#             */
/*   Updated: 2022/04/10 11:50:34 by rtakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	count1;
	size_t	count2;

	if (size == 0)
		return (ft_strlen((char *)src));
	count1 = ft_strlen(dest);
	count2 = 0;
	if (count1 >= size)
		return (size + ft_strlen(src));
	while (src[count2] != '\0' && count1 + count2 < size - 1)
	{
		dest[count1 + count2] = src[count2];
		count2++;
	}
	dest[count1 + count2] = '\0';
	return (count1 + ft_strlen(src));
}
