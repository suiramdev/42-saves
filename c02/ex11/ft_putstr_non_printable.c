/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:41:11 by mnouchet          #+#    #+#             */
/*   Updated: 2022/09/20 11:59:31 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_is_printable(char c)
{
	return (! (c < 32 || c == 127));
}

void	ft_puthexa(char c)
{
	char	*base;

	base = "0123456789abcdef";
	if (c < 0)
		c += 256;
	write(1, &base[c / 16], 1);
	write(1, &base[c % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_is_printable(str[i]))
		{			
			write(1, "\\", 1);
			ft_puthexa(str[i]);
		}	
		else
			write(1, &str[i], 1);
		i++;
	}
}
