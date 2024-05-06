/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaquer <alvaquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:46:00 by alvaquer          #+#    #+#             */
/*   Updated: 2024/02/12 11:21:02 by alvaquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	only_one_p(t_long mapa, char **mapatemp)
{
	int	i;
	int	j;
	int	c1;
	int	c2;

	c1 = 0;
	c2 = 0;
	i = 0;
	while (i < mapa.lines)
	{
		j = 0;
		while (j < mapa.columns)
		{
			if (mapatemp[i][j] == 'E')
				c1++;
			if (mapatemp[i][j] == 'P')
				c2++;
			j++;
		}
		i++;
	}
	if (c1 != 1 || c2 != 1)
		return (1);
	return (0);
}

int	count_c(t_long mapa, char **mapatemp)
{
	int	i;
	int	j;
	int	valid;

	valid = 0;
	i = 0;
	while (i < mapa.lines)
	{
		j = 0;
		while (j < mapa.columns)
		{
			if (mapatemp[i][j] == 'C')
				valid++;
			j++;
		}
		i++;
	}
	if (valid < 1)
		return (1);
	return (0);
}

void	frees(t_long *mapa)
{
	int	i;

	free(mapa->exit_pos);
	i = 0;
	while (i < mapa->lines)
	{
		free(mapa->map[i]);
		i++;
	}
	free(mapa->map);
}

void	free_map(t_long *mapa)
{
	int	i;

	i = 0;
	while (i < mapa->lines)
	{
		free(mapa->map[i]);
		i++;
	}
	free(mapa->map);
}
