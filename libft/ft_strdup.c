/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakano   <rtakano@student.42.fr    >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 23:12:11 by rtakano           #+#    #+#             */
/*   Updated: 2022/04/10 11:50:34 by rtakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*copy_str;
	int		i;

	copy_str = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (copy_str == NULL)
		return (copy_str);
	i = 0;
	while (*(src + i) != '\0')
	{
		*(copy_str + i) = *(src + i);
		i++;
	}
	*(copy_str + i) = '\0';
	return (copy_str);
}
