/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 19:09:39 by mnouchet          #+#    #+#             */
/*   Updated: 2022/09/16 14:55:37 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_com1(void)
{
	int	a;
	int	b;

	a = 0;
	b = 1;
	while (a < 99)
	{
		while (b <= 99)
		{
			ft_putchar('0' + a / 10);
			ft_putchar('0' + a % 10);
			write(1, " ", 1);
			ft_putchar('0' + b / 10);
			ft_putchar('0' + b % 10);
			if (a != 98)
			{
				write(1, ", ", 2);
			}
			b++;
		}
		b = ++a + 1;
	}
}
/*
int	main(void)
{
	ft_print_comb2();
	return (0);
}
*/
