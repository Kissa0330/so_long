/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 20:10:40 by rtakano           #+#    #+#             */
/*   Updated: 2022/09/07 13:53:12 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*t;

	t = (char *)s;
	while (*t != (char)c)
	{
		if (*t == '\0')
			return (NULL);
		t++;
	}
	return (t);
}
