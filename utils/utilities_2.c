/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:51:06 by victofer          #+#    #+#             */
/*   Updated: 2023/05/19 12:58:19 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Skips whitespaces at the begining of a string.
 * 
 * @param str string to be spaced-skipped.
 * @param start position where start skipping spaces. 
 * @return Integer whith the position of the string after skipping spaces. 
 */
int	skip_whitespaces(char *str, int start)
{
	while (str[start] == ' ')
		start++;
	return (start);
}

/**
 * @brief Skips characters at the begining of a string.
 * 
 * @param str string to be char-skipped.
 * @param start position where start skipping characters. 
 * @return Integer whith the position of the string after skipping chars. 
 */
int	skip_characters(char *str, int start)
{
	while (str[start] != ' ' && str[start] != '\0')
		start++;
	return (start);
}

/**
 * @brief Skips whitespaces and chars at the begining of a string.
 * 
 * @param str string to be spacechar-skipped.
 * @param start position where start skipping spaces and chars. 
 * @return Integer whith the position of the string
 * 	after skipping spaces and chars. 
 */
int	skip_characters_and_spaces(char *str, int start)
{
	start = skip_characters(str, start);
	start = skip_whitespaces(str, start);
	return (start);
}

/**
 * @brief Skips cmd name and flags from cmd line.
 * 
 * @param cmd_line command_line. 
 * @return Integer whith the position of the string 
 * 	after skipping cmd and flags.
 */
int	skip_cmd_and_flags(char	*cmd_line)
{
	int	i;

	i = 0;
	if (are_there_char(cmd_line, '-'))
	{
		i = ft_strlen(cmd_line);
		while (cmd_line[i] != '-')
			i--;
		i = skip_characters(cmd_line, i);
		return (i);
	}
	i = skip_characters(cmd_line, i);
	return (i);
}

/**
 * @brief Get the length of a string but starting in an specific
 * position instead of since the begining as ft_strlen doues.
 * 
 * @param str String.
 * @param start position since where start counting chars.
 * @return The length of the portion of string.
 */
int	strlen_starting_in(char *str, int start)
{
	int	len;

	len = 0;
	while (str[start])
	{
		len++;
		start++;
	}
	return (len);
}
