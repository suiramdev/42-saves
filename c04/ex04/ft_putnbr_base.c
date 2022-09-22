/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 17:08:19 by mnouchet          #+#    #+#             */
/*   Updated: 2022/09/22 18:29:12 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_is_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (base[i])
	{
		write(1, &base[i], 1);
		if (base[i] == '+' || base[i] == '-')
			return (0);
		while (base[i + j])
		{
			if (base[i] == base[i + j])
				return (0);
			j++;
		}
		j = ++i + 1;
	}
	return (i <= 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				base_len;

	base_len = ft_strlen(base);
	if (!ft_is_base(base))
		return ;
	write(1, &base[(unsigned int)nbr % base_len], 1);
	if (base_len >= 10)
		write(1, &base[(unsigned int)nbr % base_len], 1);
}
