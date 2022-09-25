/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 13:51:18 by mnouchet          #+#    #+#             */
/*   Updated: 2022/09/25 20:35:30 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "ft_maths.h"
#include "ft_std.h"

int	GRID_SIZE = 4;

// Verify that the clues were placed right 
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

// This function returns the clues in a one dimensional array.
// It returns null in case it is not matching with the right format.
//
// TODO: Check that there is the needed amount of clues, not less, not much
// i != ft_sqrt(grid_size, 2) - 1 
// on line 72 before the verify_clues calls, with a || operator
int	*get_clues(char *arg)
{
	int	*clues;
	int	i;
	int	j;

	clues = malloc(ft_sqrt(GRID_SIZE, 2) * sizeof(int));
	i = 0;
	j = 0;
	while (arg[i])
	{
		if (i % 2 == 0)
		{
			if (arg[i] < '1' || arg[i] > '0' + GRID_SIZE)
				return (0);
			clues[j++] = arg[i] - '0';
		}
		else if (arg[i] != ' ')
			return (0);
		i++;
	}
	if (!verify_clues(clues, GRID_SIZE))
		return (0);
	return (clues);
}

void	first_grid(int **grid, int *clues)
{
	int	i;

	i = 0;
	while (clues[i])
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
		if (clues[i] == 4)
		{
			if (i < 4)
			{
				grid[0][i] = 1;
				grid[1][i] = 2;
				grid[2][i] = 3;
				grid[3][i] = 4;
			}
			if (i >= 4 && i < 8)
			{
				grid[0][i - 4] = 4;
				grid[1][i - 4] = 3;
				grid[2][i - 4] = 2;
				grid[3][i - 4] = 1;
			}
			if (i >= 8 && i < 12)
			{
				grid[i - 8][0] = 1;
				grid[i - 8][1] = 2;
				grid[i - 8][2] = 3;
				grid[i - 8][3] = 4;
			}
			if (i >= 12)
			{
				grid[i - 12][0] = 4;
				grid[i - 12][1] = 3;
				grid[i - 12][2] = 2;
				grid[i - 12][3] = 1;
			}
		}
		i++;
	}
}

// Create the game's grid_size
// It also fills it with the already known numbers
int	**init_grid(int *clues)
{
	int	**grid;
	int	row;
	int	col;

	grid = malloc(GRID_SIZE * sizeof(int *));
	row = 0;
	while (row < GRID_SIZE)
	{
		col = 0;
		grid[row] = malloc(GRID_SIZE * sizeof(int));
		while (col < GRID_SIZE)
		{
			grid[row][col] = 0;
			col++;
		}
		row++;
	}
	first_grid(grid, clues);
	//prefill_grid(grid, clues, grid_size);
	return (grid);
}

int	is_number_available(int nb, int **grid, int pos)
{
	int	row;
	int	col;
	int	i;

	row = pos / GRID_SIZE;
	col = pos % GRID_SIZE;
	i = 0;
	while (i < GRID_SIZE)
	{
		if (grid[row][i] == nb || grid[i][col] == nb)
			return (0);
		i++;
	}
	return (1);
}

int	is_row_filled(int **grid, int pos)
{
	int	row;
	int	i;

	row = pos / GRID_SIZE;
	i = 0;
	while (i < GRID_SIZE)
	{
		if (!grid[row][i])
			return (0);
		i++;
	}
	return (1);
}

int	is_col_filled(int **grid, int pos)
{
	int	col;
	int	i;

	col = pos % GRID_SIZE;
	i = 0;
	while (i < GRID_SIZE)
	{
		if (!grid[i][col])
			return (0);
		i++;
	}
	return (1);
}

int	can_place(int nb, int **grid, int pos, int *clues)
{
	return (is_number_available(nb, grid, pos));
}

int	solve_grid(int **grid, int pos, int *clues)
{
	int	row;
	int	col;
	int	nb;

	if (pos > ft_sqrt(GRID_SIZE, 2))
		return (1);
	row = pos / GRID_SIZE;
	col = pos % GRID_SIZE;
	nb = 1;
	while (nb <= GRID_SIZE)
	{
		if (can_place(nb, grid, pos, clues)) {
			grid[row][pos] = nb;

			if (solve_grid(grid, pos + 1, clues))
				return (1);
		}
		grid[row][col] = 0;
		nb++;
	}
	return (0);
}

// Display the grid
void	display_grid(int **grid)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (row < GRID_SIZE)
	{
		while (col < GRID_SIZE)
		{
			ft_putchar('0' + grid[row][col]);
			if (col < GRID_SIZE - 1)
				ft_putchar(' ');
			col++;
		}
		write(1, "\n", 1);
		row++;
		col = 0;
	}
}

int	main(int argc, char **argv)
{
	int	**grid;
	int	*clues;

	if (argc < 2)
	{
		write(1, "Error", 5);
		return (0);
	}
	clues = get_clues(argv[1]);
	if (!clues)
	{
		write(1, "Error", 5);
		return (0);
	}
	grid = init_grid(clues);
	solve_grid(grid, clues, 0);
	display_grid(grid);
	free(clues);
	return (0);
}
