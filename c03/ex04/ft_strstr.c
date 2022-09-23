/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:37:31 by mnouchet          #+#    #+#             */
/*   Updated: 2022/09/22 21:08:11 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	str_len;
	int	find_len;
	int	matching;
	int	i;

	str_len = ft_strlen(str);
	find_len = ft_strlen(to_find);
	matching = 0;
	i = 0;
	while (str[i])
	{
		while (str[i + matching] == to_find[matching]
			&& (i + matching) < str_len)
			matching++;
		if (matching == find_len)
			return (&str[i]);
		matching = 0;
		i++;
	}
	return (0);
}
