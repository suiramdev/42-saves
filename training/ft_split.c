/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:12:47 by mnouchet          #+#    #+#             */
/*   Updated: 2022/10/05 18:56:53 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strincludes(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

char	**ft_allocate_words(char *str, char *charset, char **output)
{
	int	i;
	int	wordcount;
	int	charcount;

	i = 0;
	wordcount = 0;
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
	return (output);
}

/*
 * Prepare the splitting by allocating enough memory
 * This method allocates enough elements in output, and allocate_words()
 * will allocates its lengths.
 */
char	**ft_prepare_split(char *str, char *charset)
{
	char	**output;
	int		i;
	int		wordcount;

	i = 0;
	wordcount = 0;
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
	if (!output)
		return (0);
	output[wordcount] = 0;
	if (!ft_allocate_words(str, charset, output))
		return (0);
	return (output);
}

char	**ft_split(char *str, char *charset)
{
	char	**output;
	int		i;
	int		wordcount;
	int		charcount;

	output = ft_prepare_split(str, charset);
	if (!output)
		return (0);
	i = 0;
	wordcount = 0;
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
	return (output);
}

int	main(int argc, char **argv)
{
	char	**split;
	int		i;

	if (argc >= 3)
		split = ft_split(argv[1], argv[2]);
	else
		split = ft_split(",,,,,Hello,World,,,,,,I,Dit,It,,,,,,", ",");
	if (!split)
		return (0);
	i = 0;
	while (split[i])
	{
		printf("[%d]: %s\n", i, split[i]);
		i++;
	}
	return (0);
}
