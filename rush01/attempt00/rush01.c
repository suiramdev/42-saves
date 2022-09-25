/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 13:51:18 by mnouchet          #+#    #+#             */
/*   Updated: 2022/09/25 17:39:01 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "ft_maths.h"
#include "ft_std.h"

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
int	*get_clues(char *arg, int grid_size)
{
	int	*clues;
	int	i;
	int	j;

	clues = malloc(ft_sqrt(grid_size, 2) * sizeof(int));
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

// Prefill the grid with obvious values
void	prefill_grid(int **grid, int *clues, int grid_size)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (row < grid_size)
	{
		while (col < grid_size)
		{
			if (row == 0 && clues[col] == 1)
				grid[row][col] = 4;
			else if (row == grid_size - 1 && clues[grid_size + col] == 1)
				grid[row][col] = 4;
			else if (col == 0 && clues[2 * grid_size + col] == 1)
				grid[row][col] = 4;
			else if (col == grid_size - 1 && clues[3 * grid_size + col] == 1)
				grid[row][col] = 4;
			col++;
		}
		row++;
		col = 0;
	}
}

// Create the game's grid_size
// It also fills it with the already known numbers
int	**init_grid(int grid_size, int *clues)
{
	int	**grid;
	int	row;
	int	col;

	grid = malloc(grid_size * sizeof(int *));
	row = 0;
	col = 0;
	while (row < grid_size)
	{
		grid[row] = malloc(grid_size * sizeof(int));
		while (col < grid_size)
		{
			grid[row][col] = 0;
			col++;
		}
		row++;
		col = 0;
	}
	first_grid(grid, clues);
	//prefill_grid(grid, clues, grid_size);
	return (grid);
}

int	is_number_available(int nb, int **grid, int grid_size, int pos)
{
	int	row;
	int	col;
	int	i;

	row = pos / grid_size;
	col = pos % grid_size;
	i = 0;
	while (i < grid_size)
	{
		if (grid[row][i] == nb || grid[i][col] == nb)
			return (0);
		i++;
	}
	return (1);
}

// Weird way to check visibility of skycrapers
int	validate_row(int **grid, int *clues, int grid_size, int pos)
{
	int	row;
	int	col;
	int	i;
	int	visible[4];

	row = pos / grid_size;
	col = pos % grid_size;
	i = 0;
	while (i < 4)
		visible[i++] = 0;
	i = 0;
	while (i < grid_size)
	{
		visible[0] += grid[i][col] > grid[0][col];
		visible[1] += grid[i][col] > grid[grid_size - 1][col];
		visible[2] += grid[row][i] > grid[row][0];
		visible[3] += grid[row][i] > grid[row][grid_size - 1];
		i++;
	}
	return (visible[0] == clues[col]
		&& visible[1] == clues[grid_size + col]
		&& visible[2] == clues[2 * grid_size + row]
		&& visible[3] == clues[3 * grid_size + row]);
}

// Fill the grid full of numbers.
// TODO. Backtracking in it, when the rows aren't valid
// (see validate_row)
int	complete_grid(int **grid, int *clues, int grid_size, int pos)
{
	int	row;
	int	col;
	int	i;

	if (pos >= ft_sqrt(grid_size, 2))
		return (0);
	row = pos / grid_size;
	col = pos % grid_size;
	if (grid[row][col] > 0)
		return (complete_grid(grid, clues, grid_size, pos + 1));
	i = 1;
	while (i <= grid_size)
	{
		if (is_number_available(i, grid, grid_size, pos))
		{
			grid[row][col] = i;
			//printf("%d\n", validate_row(grid, clues, grid_size, pos));
			complete_grid(grid, clues, grid_size, pos + 1);
		}
		i++;
	}
	return (0);
}

// Display the grid
void	display_grid(int **grid, int grid_size)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (row < grid_size)
	{
		while (col < grid_size)
		{
			ft_putchar('0' + grid[row][col]);
			if (col < grid_size - 1)
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
	int	grid_size;
	int	**grid;
	int	*clues;

	(void)argc;
	grid_size = 4;
	clues = get_clues(argv[1], grid_size);
	if (!clues)
	{
		write(1, "Error", 5);
		return (0);
	}
	grid = init_grid(grid_size, clues);
	complete_grid(grid, clues, grid_size, 0);
	display_grid(grid, grid_size);
	free(clues);
	return (0);
}
