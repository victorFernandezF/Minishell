/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:27:23 by victofer          #+#    #+#             */
/*   Updated: 2023/03/20 11:08:37 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
 * Function: ft_strnstr
 * ----------------------------
 *   Locates the first occurrence of the null-termi-nated string
 *   needle in the string haystack, where not more than len characters
 *   are searched. Characters that appear after a `\0' character are 
 * 	 not searched.
 *
 *   haystack: string.
 *   needle: string;
 *   len: length.
 *  
 *   Returns: If needle is an empty string, haystack is returned;
 *   if needle occurs nowhere in haystack, NULL is returned;
 *   otherwise a pointer to the first character of the first occurrence
 *   of needle is returned.
 */
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	nlen;
	char	*hay;
	char	*need;

	hay = (char *)haystack;
	need = (char *)needle;
	nlen = ft_strlen(needle);
	if (nlen == 0 || hay == need)
		return (hay);
	while (*hay && len-- >= nlen)
	{
		if (*hay == *need && ft_memcmp (hay, need, nlen) == 0)
			return ((char *)hay);
		hay++;
	}
	return (NULL);
}
