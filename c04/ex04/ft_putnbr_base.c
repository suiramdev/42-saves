/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 17:08:19 by mnouchet          #+#    #+#             */
/*   Updated: 2022/09/27 11:11:47 by mnouchet         ###   ########.fr       */
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
		if (base[i] == '+' || base[i] == '-')
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		j = ++i + 1;
	}
	return (i > 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_len;

	if (!ft_is_base(base))
		return ;
	base_len = ft_strlen(base);
	write(1, &base[(unsigned int)nbr % base_len], 1);
	nbr = nbr / base_len;
	if (nbr > 0)
		ft_putnbr_base(nbr, base);
}
