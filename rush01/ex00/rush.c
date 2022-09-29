/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toteixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:45:16 by toteixei          #+#    #+#             */
/*   Updated: 2022/09/25 23:22:45 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_math.h"
#include "ft_std.h"
#include "grid.h"
#include "clues.h"
#include "validate.h"

void	ft_display(int **grid, int grid_size)
{
	int	x;
	int	y;

	y = 0;
	while (y < grid_size)
	{
		x = 0;
		while (x < grid_size)
		{
			ft_putchar(grid[y][x] + '0');
			if (++x < grid_size)
				ft_putchar(' ');
		}
		ft_putchar('\n');
		free(grid[y]);
		y++;
	}
	free(grid);
}

int	main(int argc, char **argv)
{
	int	grid_size;
	int	*clues;
	int	**grid;

	(void)argc;
	grid_size = 4;
	clues = get_clues(argv[1], grid_size);
	if (!clues)
	{
		write(1, "Error", 5);
		return (0);
	}
	grid = init_grid(grid_size);
	first_grid(grid_size, grid, clues);
	if (is_grid_ok(grid, 0, clues) == 1)
		ft_display(grid, grid_size);
	else
		write(1, "Error", 5);
	free(clues);
	return (0);
}
