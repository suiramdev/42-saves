/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 19:07:34 by mnouchet          #+#    #+#             */
/*   Updated: 2022/10/04 18:16:52 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <stdlib.h>

int	ft_is_sign(char c);
int	ft_is_space(char c);
int	ft_find_in_base(char c, char *base);
int	ft_is_base(char *base);
int	ft_count_digits(int nbr, int base_len);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	long int	output;
	int			negative;
	int			i;
	int			base_len;

	output = 0;
	negative = 1;
	i = 0;
	while (ft_is_sign(str[i]) || ft_is_space(str[i]))
	{
		if (str[i] == '-')
			negative = -negative;
		i++;
	}
	base_len = ft_strlen(base);
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		output *= base_len;
		output += ft_find_in_base(str[i], base);
		i++;
	}
	return (output * negative);
}

char	*ft_itoa_base(int nbr, char *base)
{
	int		base_len;
	int		digits;
	int		negative;
	char	*output;
	int		i;

	base_len = ft_strlen(base);
	negative = nbr < 0;
	if (negative)
		nbr = -nbr;
	digits = ft_count_digits(nbr, base_len);
	output = malloc((digits + negative + 1) * sizeof(char));
	if (negative)
		output[0] = '-';
	i = digits + negative - 1;
	while (nbr > 0)
	{
		output[i] = base[(unsigned int)nbr % base_len];
		nbr = nbr / base_len;
		i--;
	}
	output[digits + negative] = '\0';
	return (output);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	if (!ft_is_base(base_from) || !ft_is_base(base_to))
		return (NULL);
	return (ft_itoa_base(ft_atoi_base(nbr, base_from), base_to));
}
