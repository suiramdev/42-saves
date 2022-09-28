/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 19:09:10 by mnouchet          #+#    #+#             */
/*   Updated: 2022/09/28 20:41:30 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	**ft_split(char *str, char *charset)
{
	char	**output;
	int		elements;
	int		chars;
	int		i;
	int		j;
	
	i = 0;
	while (str[i])
	{
		j = 0;
		while (charset[j])
		{
			if (charset[j] == str[i])
				elements++;
			j++;
		}
		i++;
	}
	output = malloc(sizeof(char *));
}
