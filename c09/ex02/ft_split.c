/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:45:56 by mnouchet          #+#    #+#             */
/*   Updated: 2022/10/04 17:27:51 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strincludes(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_allocate_words(char *str, char *charset, char **output)
{
	int	wordcount;
	int	charcount;
	int	i;

	wordcount = 0;
	i = 0;
	while (str[i])
	{
		while (ft_strincludes(str[i], charset) && str[i])
			i++;
		if (str[i])
		{
			charcount = 0;
			while (!ft_strincludes(str[i], charset) && str[i])
			{
				charcount++;
				i++;
			}
			output[wordcount] = malloc((charcount + 1) * sizeof(char));
			if (!output[wordcount])
				return (0);
			wordcount++;
		}
	}
	return (1);
}

// It allocated enough memory to the split's output
char	**ft_prepare_split(char *str, char *charset)
{
	char	**output;
	int		wordcount;
	int		i;

	wordcount = 0;
	i = 0;
	while (str[i])
	{
		while (ft_strincludes(str[i], charset) && str[i])
			i++;
		if (str[i])
		{
			while (!ft_strincludes(str[i], charset) && str[i])
				i++;
			wordcount++;
		}
	}
	output = malloc((wordcount + 1) * sizeof(char *));
	output[wordcount] = 0;
	if (!ft_allocate_words(str, charset, output))
		return (0);
	return (output);
}

void	ft_fill_words(char *str, char *charset, char **output)
{
	int		wordcount;
	int		charcount;
	int		i;

	wordcount = 0;
	i = 0;
	while (str[i])
	{
		while (ft_strincludes(str[i], charset) && str[i])
			i++;
		if (str[i])
		{
			charcount = 0;
			while (!ft_strincludes(str[i], charset) && str[i])
			{
				output[wordcount][charcount] = str[i];
				charcount++;
				i++;
			}
			output[wordcount][charcount] = '\0';
			wordcount++;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**output;

	output = ft_prepare_split(str, charset);
	if (!output)
		return (0);
	ft_fill_words(str, charset, output);
	return (output);
}
