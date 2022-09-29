/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clues.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 22:42:12 by mnouchet          #+#    #+#             */
/*   Updated: 2022/09/25 22:43:44 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_math.h"

int	verify_clues(int *clues, int grid_size)
{
	int	i;

	i = 0;
	while (i < grid_size / 2)
	{
		if (clues[i * grid_size] == 1 && clues[(i + 2) * grid_size] == 1)
			return (0);
		i++;
	}
	return (1);
}

int	*get_clues(char *arg, int grid_size)
{
	int	*clues;
	int	i;
	int	j;

	clues = malloc(ft_sqrt(grid_size, 2) * sizeof(int));
	if (!clues)
		return (0);
	i = 0;
	j = 0;
	while (arg[i])
	{
		if (i % 2 == 0)
		{
			if (arg[i] < '1' || arg[i] > '0' + grid_size)
				return (0);
			clues[j++] = arg[i] - '0';
		}
		else if (arg[i] != ' ')
			return (0);
		i++;
	}
	if (!verify_clues(clues, grid_size))
		return (0);
	return (clues);
}
