/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 11:29:51 by mnouchet          #+#    #+#             */
/*   Updated: 2022/10/02 16:12:14 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sign(char c)
{
	return (c == '+' || c == '-');
}

int	ft_is_space(char c)
{
	return (c == '\f' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v' || c == ' ');
}

int	ft_find_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_is_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (base[i])
	{
		if (ft_is_sign(base[i]) || ft_is_space(base[i]))
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

int	ft_count_digits(int nbr, int base_len)
{
	int	i;

	i = 0;
	while (nbr > 0)
	{
		nbr = nbr / base_len;
		i++;
	}
	return (i);
}
