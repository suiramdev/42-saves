/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 10:51:13 by mnouchet          #+#    #+#             */
/*   Updated: 2022/10/02 13:35:05 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*output;
	int	i;

	if (min >= max)
		return (NULL);
	output = malloc((max - min) * sizeof(int));
	if (!output)
		return (NULL);
	i = 0;
	while (i < (max - min))
	{
		output[i] = min + i;
		i++;
	}
	return (output);
}
