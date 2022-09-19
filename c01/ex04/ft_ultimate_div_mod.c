/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 23:31:50 by mnouchet          #+#    #+#             */
/*   Updated: 2022/09/17 19:55:29 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *a / *b;
	*b = temp % *b;
}
/*
int	main(void)
{
	int a;
	int b;

	a = 7;
	b = 2;
	printf("%d ; %d\n", a, b);
	ft_ultimate_div_mod(&a, &b);
	printf("%d ; %d\n", a, b);
	return (0);
}
*/
