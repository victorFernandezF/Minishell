/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 13:26:47 by victofer          #+#    #+#             */
/*   Updated: 2023/06/28 12:05:42 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_spaces(char c)
{
	if (c == ' ' || c == '\n')
		return (1);
	return (0);
}

static int	ft_base(char c, int base)
{
	char	*pos;
	char	*pos2;
	int		i;

	pos = "0123456789abcdef";
	pos2 = "0123456789ABCDEF";
	i = 0;
	while (i < base)
	{
		if (c == pos[i] || c == pos2[i])
			return (i);
		i++;
	}
	return (-1);
}

/**
 * @brief Convert to base x the given number in base 10
 * 
 * @param str number to convert.
 * @param base base to convert.
 * @return An integer with the converted number;
 */
int	ft_atoi_base(char *str, int base)
{
	int	i;
	int	neg;
	int	res;

	i = 0;
	res = 0;
	neg = 0;
	while (ft_spaces(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = 1;
		i++;
	}
	while (ft_base(str[i], base) != -1)
	{
		res = res * base;
		res = res + ft_base(str[i], base);
		i++;
	}
	if (neg)
		return (-res);
	return (res);
}
