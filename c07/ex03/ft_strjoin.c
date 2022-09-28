/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:21:34 by mnouchet          #+#    #+#             */
/*   Updated: 2022/09/28 19:07:18 by mnouchet         ###   ########.fr       */
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

int	ft_strstotal(char **strs)
{
	int		total;
	int		i;

	total = 0;
	i = 0;
	while (strs[i])
	{
		total += ft_strlen(strs[i]);
		i++;
	}
	return (total);
}

// This is a custom version of strcat, based on our needs.
int	ft_strcat(char *dest, char *src)
{
	int	dest_len;
	int	i;

	dest_len = ft_strlen(dest);
	i = 0;
	while (src[i])
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	return (dest_len + i);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*output;
	int		i;

	output = malloc((ft_strlen(sep) * size + ft_strstotal(strs))
			* sizeof(char));
	if (size == 0)
		return (output);
	i = 0;
	while (strs[i])
	{
		ft_strcat(output, strs[i]);
		if (i < size - 1)
			ft_strcat(output, sep);
		i++;
	}
	return (output);
}
