/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_bin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:29:01 by victofer          #+#    #+#             */
/*   Updated: 2023/05/30 10:48:30 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_put_bin(unsigned int num)
{
	if (num >= 2)
	{
		ft_put_bin(num / 2);
		ft_put_bin(num % 2);
	}
	else
	{
		ft_putchar_fd(num + 48, 1);
	}
}
