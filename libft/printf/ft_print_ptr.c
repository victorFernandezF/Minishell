/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Victofer <victofer@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:36:17 by victofer          #+#    #+#             */
/*   Updated: 2023/05/30 13:39:55 by Victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_ptr_len(unsigned int ptr)
{
	int	len;

	len = 0;
	while (ptr != 0)
	{
		len++;
		ptr = ptr / 16;
	}
	return (len);
}

static void	ft_put_ptr(unsigned int ptr)
{
	if (ptr >= 16)
	{
		ft_put_ptr(ptr / 16);
		ft_put_ptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar_fd(ptr + '0', 1);
		else
			ft_putchar_fd(ptr - 10 + 'a', 1);
	}
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	ret;

	ret = 0;
	ret += write(1, "0x", 2);
	if (ptr == 0)
		ret += write(1, "0", 1);
	else
	{
		ft_put_ptr(ptr);
		ret += ft_ptr_len(ptr);
	}
	return (ret);
}
