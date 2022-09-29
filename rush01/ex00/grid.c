/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 22:36:42 by mnouchet          #+#    #+#             */
/*   Updated: 2022/09/25 23:17:26 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	**init_grid(int grid_size)
{
	int	**grid;
	int	i;
	int	j;

	grid = malloc(grid_size * sizeof(int *));
	if (!grid)
		return (0);
	i = 0;
	j = 0;
	while (i < grid_size)
	{
		grid[i] = malloc(grid_size * sizeof(int));
		if (!grid[i])
			return (0);
		j = 0;
		while (j < grid_size)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
	return (grid);
}

void	complete_tallest(int **grid, int *clues, int i)
{
	if (clues[i] == 1)
	{
		if (i < 4)
			grid[0][i] = 4;
		if (i >= 4 && i < 8)
			grid[3][i - 4] = 4;
		if (i >= 8 && i < 12)
			grid[i - 8][0] = 4;
		if (i >= 12)
			grid[i - 12][3] = 4;
	}
}

void	complete_suit(int **grid, int *clues, int i)
{
	int	row;
	int	col;
	int	nb;

	row = i % 4;
	col = i % 4;
	if (clues[i] == 4)
	{
		nb = 0;
		while (nb < 4)
		{
			if (i < 4)
				grid[nb][col] = nb + 1;
			else if (i >= 4 && i < 8)
				grid[nb][col] = 4 - nb;
			else if (i >= 8 && i < 12)
				grid[row][nb] = nb + 1;
			else
				grid[row][nb] = 4 - nb;
			nb++;
		}
	}
}

void	first_grid(int **grid, int *clues)
{
	int	i;

	i = 0;
	while (clues[i])
	{
		complete_tallest(grid, clues, i);
		complete_suit(grid, clues, i);
		i++;
	}
}
