/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:11:11 by victofer          #+#    #+#             */
/*   Updated: 2023/06/28 12:11:10 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*des_aux;
	char	*src_aux;
	size_t	i;

	if (!dst && !src)
		return (0);
	i = -1;
	des_aux = (char *)dst;
	src_aux = (char *)src;
	if (des_aux > src_aux)
	{
		while (len-- > 0)
			des_aux[len] = src_aux[len];
	}
	else
	{
		while (++i < len)
			des_aux[i] = src_aux[i];
	}
	return (dst);
}
