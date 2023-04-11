/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:38:29 by victofer          #+#    #+#             */
/*   Updated: 2023/03/17 11:14:46 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/* 
 * Function: ft_memset
 * ----------------------------
 *   Writes len bytes of value c (converted to an unsigned char)
 *   to the string b.
 *
 *   b: void * variable where the function will write 
 *   c: int
 *   len: size_t with the length bytes we want to write
 * 
 *   Returns: its first argument (b)
 */
void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
