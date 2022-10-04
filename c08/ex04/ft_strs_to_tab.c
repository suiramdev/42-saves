/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 00:17:11 by mnouchet          #+#    #+#             */
/*   Updated: 2022/10/04 04:27:28 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*copy;
	int		i;

	i = 0;
	while (src[i])
		i++;
	copy = malloc((i + 1) * sizeof(char));
	i = 0;
	while (src[i])
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*output;
	int					i;

	output = malloc((ac + 1) * sizeof(struct s_stock_str));
	if (!output)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		output[i].size = ft_strlen(av[i]);
		output[i].str = av[i];
		output[i].copy = ft_strdup(av[i]);
		i++;
	}
	output[i].size = 1;
	output[i].str = 0;
	output[i].copy = 0;
	return (output);
}
