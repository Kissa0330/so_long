/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:46:11 by takanoraika       #+#    #+#             */
/*   Updated: 2022/09/19 20:22:16 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	path_check(char *path)
{
	int	i;

	i = 0;
	if (path == NULL)
		return (-1);
	if (path[0] == '.')
		return (-1);
	while (path[i] != '\0')
	{
		if (i == INT_MAX)
			return (-1);
		if (path[i] == '.')
		{
			if (ft_strncmp(&path[i], ".bar", 5) != 0)
				return (-1);
		}
		i ++;
	}
	return (0);
}
