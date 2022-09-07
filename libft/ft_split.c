/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakano   <rtakano@student.42.fr    >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 17:18:26 by rtakano           #+#    #+#             */
/*   Updated: 2022/04/10 11:50:34 by rtakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	**free_strs(char **strs)
{
	unsigned int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

int	count_strs(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			if (i > 0 && str[i - 1] != c)
				count ++;
		}
		i ++;
	}
	if (i > 0 && str[i - 1] != c)
		count ++;
	return (count);
}

char	**make_split(int count, char *str, char c)
{
	char	**strs;
	int		i;
	int		j;

	i = 0;
	strs = malloc(sizeof(char *) * (count + 1));
	if (strs == NULL)
		return (strs);
	strs[count] = NULL;
	while (i < count)
	{
		while (*str == c)
			str ++;
		j = 0;
		while (str[j] != c && str[j] != '\0')
			j ++;
		strs[i] = malloc(sizeof(char) * (j + 1));
		if (strs[i] == NULL)
			return (free_strs(strs));
		ft_strlcpy(strs[i], str, j + 1);
		str = str + ft_strlen(strs[i++]);
	}
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	char	*str;
	int		count;

	if (!s)
		return (NULL);
	count = count_strs(s, c);
	str = (char *)s;
	return (make_split(count, str, c));
}
