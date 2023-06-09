/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_oct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:27:58 by victofer          #+#    #+#             */
/*   Updated: 2023/05/30 10:49:06 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_put_oct(unsigned int num)
{
	if (num >= 8)
	{
		ft_put_oct(num / 8);
		ft_put_oct(num % 8);
	}
	else
	{
		ft_putchar_fd(num + 48, 1);
	}
}
