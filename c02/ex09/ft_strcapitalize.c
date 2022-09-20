/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 23:13:59 by mnouchet          #+#    #+#             */
/*   Updated: 2022/09/19 13:18:42 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_lowercase(char c)
{
	return (c >= 'a' && c <= 'z');
}

int	ft_is_uppercase(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int	ft_should_capitalize(char previous, char current)
{
	return (! ((previous >= 'a' && previous <= 'z')
			|| (previous >= 'A' && previous <= 'Z')
			|| (previous >= '0' && previous <= '9'))
		&& ft_is_lowercase(current));
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_is_uppercase(str[i]))
			str[i] = str[i] - 'A' + 'a';
		if (i > 0)
		{
			if (ft_should_capitalize(str[i - 1], str[i]))
				str[i] = str[i] - 'a' + 'A';
		}
		else
		{
			if (ft_is_lowercase(str[i]))
				str[i] = str[i] - 'a' + 'A';
		}
		i++;
	}
	return (str);
}
