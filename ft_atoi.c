/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 16:43:40 by mnouchet          #+#    #+#             */
/*   Updated: 2022/09/18 16:44:13 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	output;
	int	i;

	output = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			output *= 10;
			output += str[i] - '0';
		}
		else if (i != 0 && (str[i] == '-' || str[i] == '+' ))
			break ;
		i++;
	}
	if (str[0] == '-')
		output = -output;
	return (output);
}
