/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:17:42 by victofer          #+#    #+#             */
/*   Updated: 2023/06/16 12:03:53 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Copy a string but doing the malloc stuff first.
 * 
 * @param str_to_copy The string to be copied.
 * @return A mallocked string with the value of str_to_copy
 */
char	*ft_copy_str(char *str_to_copy)
{
	int		len;
	char	*copy;

	len = ft_strlen(str_to_copy);
	copy = malloc(len * sizeof(char));
	if (!copy)
		return (NULL);
	copy = ft_strcpy(copy, str_to_copy);
	return (copy);
}
