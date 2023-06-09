/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:29:14 by victofer          #+#    #+#             */
/*   Updated: 2023/05/30 10:53:20 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], 1);
		i++;
	}
}

int	ft_print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_string(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], 1);
		i++;
	}
	return (i);
}
