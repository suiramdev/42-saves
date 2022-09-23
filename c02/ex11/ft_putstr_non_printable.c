/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:41:11 by mnouchet          #+#    #+#             */
/*   Updated: 2022/09/22 16:31:33 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_non_printable(char c)
{
	return (c < 32 || c == 127);
}

void	ft_puthexa(unsigned char c)
{
	char	*base;

	base = "0123456789abcdef";
	write(1, &base[c / 16], 1);
	write(1, &base[c % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_non_printable(str[i]))
		{
			write(1, "\\", 1);
			ft_puthexa((unsigned char)str[i]);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}
