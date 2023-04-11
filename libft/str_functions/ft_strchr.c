/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:38:11 by victofer          #+#    #+#             */
/*   Updated: 2023/03/17 11:40:25 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
 * Function: ft_strchr
 * ----------------------------
 *   locates the first occurrence of c (converted to a char)
 * 	 in the string pointed to by s.
 *
 * 	 s: string 
 *   c: char. 
 *  
 *   Returns: a pointer to the located character or NULL if it does
 * 	 not apear in s.
 */
char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == s[i])
		return ((char *)&s[i]);
	return (NULL);
}
