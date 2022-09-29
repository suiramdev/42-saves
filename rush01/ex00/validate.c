/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 22:46:11 by mnouchet          #+#    #+#             */
/*   Updated: 2022/09/25 23:14:19 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checks.h"

int	validate_clues(int **grid, int *clues, int pos)
{
	int	r;
	int	c;

	r = pos / 4;
	c = pos % 4;
	return (row_check_clue(grid, clues[r + 8], 0, pos)
		&& row_check_clue(grid, clues[r + 12], 3, pos)
		&& col_check_clue(grid, clues[c], 0, pos)
		&& col_check_clue(grid, clues[c + 4], 3, pos));
}

int	is_grid_ok(int **grid, int pos, int *clues)
{
	int	c;
	int	r;
	int	k;

	if (pos == 4 * 4)
		return (1);
	r = pos / 4;
	c = pos % 4;
	if (grid[r][c] != 0)
		return (is_grid_ok(grid, pos + 1, clues));
	k = 1;
	while (k <= 4)
	{
		if (not_on_column(k, 4, grid, c) && not_on_row(k, 4, grid, r)
			&& validate_clues(grid, clues, pos))
		{
			grid[r][c] = k;
			if (is_grid_ok(grid, pos + 1, clues))
				return (1);
		}
		k++;
	}
	grid[r][c] = 0;
	return (0);
}
