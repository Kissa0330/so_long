/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakano   <rtakano@student.42.fr    >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:32:04 by rtakano           #+#    #+#             */
/*   Updated: 2022/04/10 11:50:33 by rtakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;
	size_t	count_size;

	count_size = count * size;
	if (count_size == 0)
		count_size = 1;
	if (count && size > SIZE_MAX / count)
		count_size = SIZE_MAX;
	res = malloc(count_size);
	if (res == NULL)
		return (NULL);
	ft_bzero(res, count * size);
	return (res);
}
