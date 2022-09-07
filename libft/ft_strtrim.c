/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakano   <rtakano@student.42.fr    >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 21:03:05 by rtakano           #+#    #+#             */
/*   Updated: 2022/04/10 11:50:34 by rtakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	trim_start(const char *str, const char *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (str[i] == set[j])
			{
				i++ ;
				break ;
			}
			j ++;
		}
		if (set[j] == '\0')
			break ;
	}
	return (i);
}

size_t	trim_end(const char *str, const char *set)
{
	size_t	len;
	size_t	i;
	int		j;

	len = ft_strlen((char *)str);
	i = 0;
	while (str[len - i - 1] != '\0')
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (str[len - i - 1] == set[j])
			{
				i ++;
				break ;
			}
			j ++;
		}
		if (set[j] == '\0')
			break ;
	}
	return (len - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	start;
	size_t	len;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup((char *)s1));
	start = trim_start(s1, set);
	len = ft_strlen(s1 + start);
	while (len > 0 && ft_strchr(set, *(s1 + start + len - 1)))
		len--;
	if (len <= 0)
		return (ft_strdup(""));
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, s1 + start, len + 1);
	return (res);
}
