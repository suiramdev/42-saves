/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:12:55 by mnouchet          #+#    #+#             */
/*   Updated: 2022/09/29 17:26:32 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] && s2[i]))
		i++;
	return (s1[i] - s2[i]);
}

void	ft_sort_params(char **params, int size)
{
	char	*backup;
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = ++i + 1;
		while (j < size)
		{
			if (ft_strcmp(params[i], params[j]) > 0)
			{
				backup = params[i];
				params[i] = params[j];
				params[j] = backup;
			}
			j++;
		}
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	ft_sort_params(argv, argc);
	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			write(1, &argv[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
