/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:43:40 by victofer          #+#    #+#             */
/*   Updated: 2023/03/20 12:06:38 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/* 
 * Function: ft_calloc
 * ----------------------------
 *   Allocates enough space for count objects that are
 *   size bytes of memory each and returns a pointer to the
 *   allocated memory. The allocated memory is filled with
 *   bytes of value zero.
 *
 *   count: number of objects to allocate.
 *   s2: size in bytes of each objects (sizeof()).
 * 
 *   Returns: A pointer to allocated memory
 */

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;

	res = malloc(size * count);
	if (res == NULL)
		return (res);
	ft_bzero(res, size * count);
	return (res);
}
