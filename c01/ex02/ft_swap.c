/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 13:39:55 by mnouchet          #+#    #+#             */
/*   Updated: 2022/09/17 19:57:17 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	store;

	store = *a;
	*a = *b;
	*b = store;
}
/*
int	main(void)
{
	int a = 1;
	int b = 2;
	ft_swap(&a, &b);
	printf("a: %d\n", a);
	printf("b: %d", b);
	return (0);
}
*/
