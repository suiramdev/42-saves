/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 13:01:53 by mnouchet          #+#    #+#             */
/*   Updated: 2022/09/26 13:34:32 by mnouchet         ###   ########.fr       */
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


int	ft_atoi_base(char *str, char *base)
{
	int	output;
	int	sign;
	int	i;
	int pos;

	if (!ft_is_base(base))
		return (0);
	output = 0;
	sign = 1;
	i = 0;
	while (ft_is_space(str[i]) || ft_is_sign(str[i]))
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i])
	{
		pos = ft_find_in_base(str[i], base);
		if (pos < 0)
			return (0);
		output = output * 10 + pos; 
		i++;
	}
	return (output * sign);
}
