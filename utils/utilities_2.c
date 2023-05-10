/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:51:06 by victofer          #+#    #+#             */
/*   Updated: 2023/05/10 12:13:14 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* 
 * skip_whitespaces
 * ----------------------------
 *	Returns an int with the position of the string
 *	after skipping all spaces.
 */
int	skip_whitespaces(char *str, int i)
{
	while (str[i] == ' ')
		i++;
	return (i);
}

/* 
 * skip_whitespaces
 * ----------------------------
 *	Returns an int with the position of the string
 *	after skipping all characters.
 */
int	skip_characters(char *str, int i)
{
	while (str[i] != ' ' && str[i] != '\0')
		i++;
	return (i);
}

/* 
 * skip_characters_and_spaces
 * ----------------------------
 *	Returns an int with the position of the string
 *	after skipping all character and spaces.
 */
int	skip_characters_and_spaces(char *str, int i)
{
	i = skip_characters(str, i);
	i = skip_whitespaces(str, i);
	return (i);
}

int	strlen_startin_in(char *str, int i)
{
	int	len;

	len = 0;
	while (str[i])
	{
		len++;
		i++;
	}
	return (len);
}