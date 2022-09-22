/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:46:11 by takanoraika       #+#    #+#             */
/*   Updated: 2022/09/22 19:56:48 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	path_check(char *path)
{
	size_t	i;

	i = ft_strlen(path);
	if (path[0] == '.')
		return (-1);
	while (i > 0)
	{
		if (i > INT_MAX)
			return (-1);
		if (path[i] == '.')
		{
			if (ft_strncmp(&path[i], ".ber", 5) != 0)
				return (-1);
			else
				return (0);
		}
		i --;
	}
	return (0);
}
