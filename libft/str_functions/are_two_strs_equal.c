/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   are_two_strs_equal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 11:00:15 by victofer          #+#    #+#             */
/*   Updated: 2023/06/28 11:05:40 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Compares if two strings are the same.
 * Same length and same content.
 * 
 * @param str1 String 1
 * @param str2 String 2
 * @return 1 if they are equal. 0 if they are different.
 */
int	are_two_strs_equal(char *str1, char *str2)
{
	int	i;
	int	len_s1;
	int	len_s2;

	i = -1;
	len_s1 = ft_strlen(str1);
	len_s2 = ft_strlen(str2);
	if (len_s1 != len_s2)
		return (0);
	while (++i < len_s1)
		if (str1[i] != str2[i])
			return (0);
	return (1);
}
