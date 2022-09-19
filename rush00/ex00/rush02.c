/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 11:27:03 by mnouchet          #+#    #+#             */
/*   Updated: 2022/09/18 14:51:13 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

// i is the rows
// j are the columns

int	ft_simple_atoi(char *str)
{
	int	output;
	int	i;

	output = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			output *= 10;
			output += str[i] - '0';
		}
		else if (i != 0 && (str[i] == '-' || str[i] == '+' ))
			break ;
		i++;
	}
	if (str[0] == '-')
		output = -output;
	return (output);
}

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
		else
		{
			if (i == 1)
				ft_putchar('A');
			else if (i == y)
				ft_putchar('C');
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
