/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:57:00 by mnouchet          #+#    #+#             */
/*   Updated: 2022/09/22 19:37:39 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_numeric(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_is_sign(char c)
{
	return (c == '+' || c == '-');
}

int	ft_is_space(char c)
{
	return (c == '\f' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v' || c == ' ');
}

int	ft_atoi(char *str)
{
	int	output;
	int	sign;
	int	i;

	output = 0;
	sign = 1;
	i = 0;
	while (ft_is_space(str[i]) || ft_is_sign(str[i]))
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (ft_is_numeric(str[i]))
	{
		output = output * 10 + str[i] - '0';
		i++;
	}
	return (output * sign);
}
