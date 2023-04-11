/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:05:23 by victofer          #+#    #+#             */
/*   Updated: 2023/03/17 11:34:46 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/* 
 * Function: ft_strlcat
 * ----------------------------
 *   Copies up to dstsize - 1 characters from the string src to dst
 *
 *   dst: variable where the function will copy 
 *   src: variable that we want to copy
 * 	 dstsize: size we want to copy
 *   Returns: The total length of the string they tried to create
 */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;	

	len = ft_strlen(dst) + ft_strlen(src);
	if (dstsize <= ft_strlen(dst))
		return (ft_strlen(src) + dstsize);
	while (*dst)
		dst++;
	i = 0;
	while ((i < dstsize -(len - ft_strlen(src)) - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}
