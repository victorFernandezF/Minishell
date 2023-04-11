/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:38:49 by victofer          #+#    #+#             */
/*   Updated: 2023/03/17 11:34:22 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/* 
 * Function: ft_strlcby
 * ----------------------------
 *   Copies up to dstsize - 1 characters from the string src to dst
 *
 *   dst: variable where the function will copy 
 *   src: variable that we want to copy
 * 	 dstsize: size we want to copy
 *   Returns: The total length of the string they tried to create
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	char	*pt_src;

	pt_src = (char *)src;
	i = 0;
	if (dstsize > 0)
	{
		while (pt_src[i] && i < dstsize - 1)
		{
			dst[i] = pt_src[i];
			i++;
		}
		dst[i] = 0;
	}
	while (src[i])
		i++;
	return (i);
}
