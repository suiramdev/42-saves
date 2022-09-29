/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:00:46 by mnouchet          #+#    #+#             */
/*   Updated: 2022/09/29 12:07:08 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size - 1 && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	if (size - i > 0)
		dest[i] = '\0';
}

int	ft_oneof(char c, char *charset)
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

void	ft_prepare_split(char *str, char *charset, char **output, char *entry)
{
	int		wordcount;
	int		charcount;
	int		i;

	wordcount = 0;
	charcount = 0;
	i = 0;
	while (str[i])
	{
		if (ft_oneof(str[i], charset))
		{
			if (charcount > 0)
				wordcount++;
		}
		else
			charcount++;
		i++;
	}
	output = malloc(wordcount * sizeof(char *));
	entry = malloc(i * sizeof(char));
}

char	**ft_split(char *str, char *charset)
{
	char	**output;
	char	*entry;
	int		wordcount;
	int		charcount;
	int		i;

	ft_prepare_split(str, charset, output, entry);
	if (!output || !entry)
		return (0);
	wordcount = 0;
	charcount = 0;
	i = 0;
	while (str[i])
	{
		if (ft_oneof(str[i], charset))
		{
			output[wordcount] = malloc(charcount * sizeof(char));
			ft_strlcpy(output[wordcount], entry, wordcount + 1);
			wordcount++;
			charcount = 0;
		}
		else
			entry[charcount] = str[i];
		charcount++;
		i++;
	}
	return (output);
}
