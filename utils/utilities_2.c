/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:51:06 by victofer          #+#    #+#             */
/*   Updated: 2023/05/12 10:21:19 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* 
 * skip_whitespaces (utils/utilities_2.c)
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
 * skip_whitespaces (utils/utilities_2.c)
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
 * skip_characters_and_spaces (utils/utilities_2.c)
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

/* 
 * strlen_starting_in (utils/utilities_2.c)
 * ----------------------------
 *	Returns the length of an string but
 *	starting in the position i.
 */
int	strlen_starting_in(char *str, int i)
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

/* 
 * skip_cmd_and_flags (utils/utilities_2.c)
 * ----------------------------
 *	Returns the position of a string skipping the
 *	cmd name and flags.
 */
int	skip_cmd_and_flags(char	*str)
{
	int	i;

	i = 0;
	if (are_there_char(str, '-'))
	{
		i = ft_strlen(str);
		while (str[i] != '-')
			i--;
		i = skip_characters(str, i);
		return (i);
	}
	i = skip_characters(str, i);
	return (i);
}
