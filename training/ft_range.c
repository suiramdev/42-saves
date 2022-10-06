/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:06:45 by mnouchet          #+#    #+#             */
/*   Updated: 2022/10/06 18:16:28 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

long int	ft_abs(long int nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

int	*ft_range(int start, int end)
{
	int		*output;
	long	size;
	int		i;
	
	size = ft_abs((long)end - (long)start) + 1;
	output = malloc(size * sizeof(int));
	if (!output)
		return (0);
	i = 0;
	while (i < size)
	{
		if (start < end)
			output[i] = start + i; 
		else
			output[i] = start - i;
		i++;
	}
	return (output);
}

int	main(int argc, char **argv)
{
	int	*output;
	int	start;
	int	end;
	int	size;
	int	i;

	start = -2147483648;
	end = 2147483647;
	if (argc >= 3)
	{
		start = atoi(argv[1]);
		end = atoi(argv[2]);
	}

	output = ft_range(start, end);
	if (!output)
		return (0);
	size = ft_abs(end - start) + 1;
	i = 0;
	while (i < size)
	{
		printf("%d, ", output[i]);
		i++;
	}
}
