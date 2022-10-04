/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 21:57:38 by mnouchet          #+#    #+#             */
/*   Updated: 2022/10/04 20:10:11 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char				*output;
	long int			allocsize;
	int					i;

	if (size <= 0 || !strs)
	{
		output = malloc(sizeof(char));
		output[0] = 0;
		return (output);
	}
	allocsize = ft_strlen(sep) * (size - 1);
	i = 0;
	while (i < size)
		allocsize += ft_strlen(strs[i++]);
	output = malloc((allocsize + 1) * sizeof(char));
	if (!output)
		return (0);
	i = 0;
	while (i < size)
	{
		ft_strcat(output, strs[i]);
		if (i < size - 1)
			ft_strcat(output, sep);
		i++;
	}
	output[allocsize] = '\0';
	return (output);
}
