/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:51:06 by victofer          #+#    #+#             */
/*   Updated: 2023/05/25 12:18:29 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Checks if there are som quotes in the string
 * before the given position.
 * 
 * @param str String.
 * @param end Position. Function will check quotes in the string
 * 	before this point.
 * @return 1 if quotes found and 0 if not. 
 */
int	is_there_open_quotes(char *str, int end)
{
	end--;
	while (str[end] && str[end] != ' ')
		if (str[end--] == 34)
			return (1);
	return (0);
}

/**
 * @brief Returns 1 if char c is found in string str.
 *	If not, returns 0.
 * 
 * @param str line.
 * @param c character to search.
 * @return int 0 or 1.
 */
int	are_there_char(char *str, char c)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (1);
	return (0);
}
