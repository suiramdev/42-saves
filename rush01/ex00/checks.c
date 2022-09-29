/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 22:46:11 by mnouchet          #+#    #+#             */
/*   Updated: 2022/09/25 23:11:50 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	not_on_row(int nb, int grid_size, int **grid, int r)
{
	int	i;

	i = 0;
	while (i < grid_size)
	{
		if (grid[r][i] == nb)
			return (0);
		i++;
	}
	return (1);
}

int	not_on_column(int nb, int grid_size, int **grid, int c)
{
	int	i;

	i = 0;
	while (i < grid_size)
	{
		if (grid[i][c] == nb)
			return (0);
		i++;
	}
	return (1);
}

int	check_row_is_ok(int **grid, int c1, int c2, int r)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	j = 1;
	k = 1;
	if (r == 3)
	{
		while (i < 4)
		{
			if (grid[r][i] > grid[r][0])
				j++;
			if (grid[r][3 - i] > grid[r][3])
				k++;
			i++;
		}
		if (j == c1 && k == c2)
			return (1);
	}
	return (1);
}

int	col_check_clue(int **grid, int clue, int i, int pos)
{
	int	r;
	int	c;
	int	tallest;

	r = pos / 4;
	c = pos % 4;
	tallest = 1;
	if (r == 3)
	{
		while (i >= 0)
		{
			if (grid[i][c] > tallest)
				tallest++;
			i--;
		}
		if (tallest == clue)
			return (1);
		else
			return (0);
	}
	return (1);
}

int	row_check_clue(int **grid, int clue, int i, int pos)
{
	int	r;
	int	c;
	int	tallest;

	r = pos / 4;
	c = pos % 4;
	tallest = 1;
	if (c == 3)
	{
		while (i >= 0)
		{
			if (grid[r][i] > tallest)
				tallest++;
			i--;
		}
		if (tallest == clue)
			return (1);
		else
			return (0);
	}
	return (1);
}
