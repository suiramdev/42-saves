/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantiag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 16:17:50 by tsantiag          #+#    #+#             */
/*   Updated: 2022/09/18 16:40:33 by mnouchet         ###   ########.fr       */
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
			ft_putchar('-');
	}
	else
	{
		if (i > 1 && i < y)
			ft_putchar('|');
		else
		{
			if (j == 1)
				ft_putchar('o');
			else if (j == x)
				ft_putchar('o');
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
