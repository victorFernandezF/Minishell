/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:48:58 by victofer          #+#    #+#             */
/*   Updated: 2023/03/20 11:14:38 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
 * Function: ft_substr
 * ----------------------------
 *   Allocates (with malloc(3)) and returns a substring
 *   from the string ’s’. The substring begins at index
 *   ’start’ and is of maximum size ’len’.
 *
 *   s: string.
 *   start: index where substring begins.
 *   len: the len of the substring.
 *  
 *   Returns: The substring.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub_str;
	unsigned int	i;
	size_t			size;

	if (!s)
		return (NULL);
	if ((size_t)start > ft_strlen(s))
	{
		return (ft_strdup(""));
	}
	size = ft_strlen(s + start);
	if (size < len)
		len = size;
	i = 0;
	sub_str = (char *)malloc(sizeof(char) * (len + 1));
	if (sub_str == NULL)
		return (NULL);
	while (s[i] && i < len)
	{
		sub_str[i] = s[i + start];
		i++;
	}
	sub_str[i] = 0;
	return (sub_str);
}
