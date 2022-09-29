/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 10:37:59 by mnouchet          #+#    #+#             */
/*   Updated: 2022/09/23 11:13:38 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_rot_13(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'm')
				|| (str[i] >= 'A' && str[i] <= 'M'))
			ft_putchar(str[i] + 13);
		else if ((str[i] > 'm' && str[i] <= 'z')
				|| (str[i] > 'M' && str[i] <= 'Z'))
			ft_putchar(str[i] - 13);
		else
			ft_putchar(str[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		write(1, "\n", 1);
		return (0);
	}

	ft_rot_13(argv[1]);
}
