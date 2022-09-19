/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 10:08:19 by mnouchet          #+#    #+#             */
/*   Updated: 2022/09/18 15:30:34 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	backup;
	int	i;

	i = 0;
	while (i < size / 2)
	{
		backup = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = backup;
		i++;
	}
}
