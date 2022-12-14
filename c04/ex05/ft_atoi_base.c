/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 13:01:53 by mnouchet          #+#    #+#             */
/*   Updated: 2022/10/01 17:46:17 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_is_skipper(char c)
{
	return (c == '+' || c == '-' || c == '\f'
		|| c == '\n' || c == '\r' || c == '\t'
		|| c == '\v' || c == ' ');
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
		if (ft_is_skipper(base[i]))
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
	int	negative;
	int	i;
	int	base_len;

	if (!ft_is_base(base))
		return (0);
	output = 0;
	negative = 1;
	i = 0;
	while (ft_is_skipper(str[i]))
	{
		if (str[i] == '-')
			negative = -negative;
		i++;
	}
	base_len = ft_strlen(base);
	while (str[i])
	{
		output *= base_len;
		output += ft_find_in_base(str[i], base);
		i++;
	}
	return (output * negative);
}
