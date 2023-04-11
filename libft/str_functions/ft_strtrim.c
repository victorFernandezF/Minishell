/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 12:15:25 by victofer          #+#    #+#             */
/*   Updated: 2023/03/20 11:17:12 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
 * Function: ft_strtrim
 * ----------------------------
 *   Allocates (with malloc(3)) and returns a copy of
 *   ’s1’ with the characters specified in ’set’ removed
 *   from the beginning and the end of the string.
 *
 *   s1: The string to be trimmed.
 * 	 set: The reference set of characters to trim.
 *  
 *   Returns: The trimmed string.
 * 	 NULL if the allocation fails.
 */
char	*ft_strtrim(char *s1, char *set)
{
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	i = ft_strlen (s1);
	while (i && ft_strchr(set, s1[i]))
		i--;
	return (ft_substr(s1, 0, i + 1));
}
