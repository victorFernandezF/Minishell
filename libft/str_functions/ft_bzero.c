/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:38:52 by victofer          #+#    #+#             */
/*   Updated: 2023/03/17 11:25:08 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/* 
 * Function: ft_bzero
 * ----------------------------
 *   Writes n zeroed bytes to string s. If n is zero, does nothing.
 *
 *   s: void * variable where the function will write 
 *   n: size_t with the length bytes we want to write
 * 
 *   Returns: its first argument (s)
 */
void	*ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		((unsigned char *)s)[i] = 0;
		i++;
	}
	return (s);
}
