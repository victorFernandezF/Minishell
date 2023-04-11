/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 10:23:58 by victofer          #+#    #+#             */
/*   Updated: 2023/03/17 11:06:23 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../libft.h"

/*
 * Function: ft_strcpy
 * ----------------------------
 *   copy the string src into the string dst
 *
 *   src: string with the content we want to copy in dst.
 *   dst: destination string where we want to copy src.
 *  
 *   Returns: the char *dst given but with the copy done.
 */
char	*ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
