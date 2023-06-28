/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:30:00 by victofer          #+#    #+#             */
/*   Updated: 2023/06/28 12:08:46 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Compares byte string s1 against byte string s2.
 *   Both strings are assumed to be n bytes long.
 *   function copies n bytes from memory area src
 *   to memory area dst.
 * 
 * @param s1 destination memory area.
 * @param s2 source memory area.
 * @param n bytes that are goint to be copied
 * @return 0 if the two strings are identical.
 *   if not, the difference between the first two 
 * 	 differing bytes returns the original value of dst.
 */
int	ft_memcmp(void *s1, void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	if (s1 == s2 || n == 0)
		return (0);
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (n--)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		if (n)
		{
			str1++;
			str2++;
		}
	}
	return (0);
}
