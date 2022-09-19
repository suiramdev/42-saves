/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:10:46 by mnouchet          #+#    #+#             */
/*   Updated: 2022/09/16 11:51:15 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write_comb(char hundreds, char tens, char units)
{
	write(1, &hundreds, 1);
	write(1, &tens, 1);
	write(1, &units, 1);
	if (hundreds < '7')
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	char	hundreds;
	char	tens;
	char	units;

	hundreds = '0';
	tens = '1';
	units = '2';
	while (hundreds <= '9')
	{
		while (tens <= '9')
		{
			while (units <= '9')
			{
				ft_write_comb(hundreds, tens, units);
				units++;
			}
			units = ++tens + 1;
		}
		tens = ++hundreds + 1;
		units = tens + 1;
	}
}
/*
int	main(void)
{
	ft_print_comb();
	return (0);
}
*/
