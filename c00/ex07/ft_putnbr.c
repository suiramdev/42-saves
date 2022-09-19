/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:35:42 by mnouchet          #+#    #+#             */
/*   Updated: 2022/09/15 19:06:46 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	output;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	else if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
	}
	output = '0' + nb % 10;
	nb = nb / 10;
	if (nb > 0)
	{
		ft_putnbr(nb);
	}
	write(1, &output, 1);
}
/*
int	main(void)
{
	ft_putnbr(-2147483648);
	write(1, "\n", 2);
	ft_putnbr(2147483647);
	return (0);
}
*/
