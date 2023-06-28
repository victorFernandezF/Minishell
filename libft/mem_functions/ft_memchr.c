/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:53:10 by victofer          #+#    #+#             */
/*   Updated: 2023/06/28 12:07:45 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Locates the first occurrence of c (converted to an
 *   unsigned char) in string s.
 * 
 * @param s string.
 * @param c character to search in s.
 * @param n number of bytes in which c is gointg to
 * 	 be searched.
 * @return Returns: a pointer to the byte located, or NULL if
 *   no such byte exists within n bytes.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	charac;

	str = (unsigned char *)s;
	charac = (unsigned char)c;
	while (n--)
	{
		if (*str == charac)
			return (str);
		if (n)
			str++;
	}
	return (NULL);
}
