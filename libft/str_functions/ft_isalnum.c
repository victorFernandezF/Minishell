/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:35:15 by victofer          #+#    #+#             */
/*   Updated: 2023/03/17 10:58:59 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
 * Function: ft_isalnum
 * ----------------------------
 *   Checks if a given char is alphanumeric (letters or numbers)
 *
 *   c: char to be check. 
 *  
 *   Returns: 1 if is alphanumeric and 0 if not.
 */
int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}
