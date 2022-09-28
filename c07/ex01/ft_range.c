/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 10:51:13 by mnouchet          #+#    #+#             */
/*   Updated: 2022/09/28 17:21:23 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*output;

	if (min >= max)
		return (0);
	output = malloc((max - min) * sizeof(int));
	while (min <= max)
	{
		output[max - min] = min;
		min++;
	}
	return (output);
}
