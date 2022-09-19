/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 11:27:03 by mnouchet          #+#    #+#             */
/*   Updated: 2022/09/18 16:44:26 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

// i is the rows
// j are the columns

void	rush_display(int x, int y, int i, int j)
{
	if (j > 1 && j < x)
	{
		if (i > 1 && i < y)
			ft_putchar(' ');
		else
			ft_putchar('B');
	}
	else
	{
		if (i > 1 && i < y)
			ft_putchar('B');
		else if (i == 1)
		{
			if (j == 1)
				ft_putchar('A');
			else if (j == x)
				ft_putchar('C');
		}
		else
		{
			if (j == 1)
				ft_putchar('C');
			else if (j == x)
				ft_putchar('A');
		}
	}
}

void	rush(int x, int y)
{
	int	i;
	int	j;

	if (x <= 0 || y <= 0)
		return ;
	i = 1;
	j = 1;
	while (i <= y)
	{
		while (j <= x)
		{
			rush_display(x, y, i, j);
			j++;
		}
		ft_putchar('\n');
		i++;
		j = 1;
	}	
}
