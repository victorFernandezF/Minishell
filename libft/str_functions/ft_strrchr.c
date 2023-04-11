/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:34:15 by victofer          #+#    #+#             */
/*   Updated: 2023/03/17 11:40:56 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
 * Function: ft_strrchr
 * ----------------------------
 *   locates the last occurrence of c (converted to a char)
 * 	 in the string pointed to by s.
 *
 * 	 s: string 
 *   c: char. 
 *  
 *   Returns: a pointer to the located character or NULL if it does
 * 	 not apear in s.
 */
char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*last;

	i = 0;
	last = NULL;
	while (s[i])
	{
		if (s[i] == (char)c)
			last = (char *)&s[i];
		i++;
	}
	if ((char)c == s[i])
		return ((char *)&s[i]);
	return (last);
}
