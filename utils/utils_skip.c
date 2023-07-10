/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_skip.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:08:29 by victofer          #+#    #+#             */
/*   Updated: 2023/07/10 12:09:39 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Skips whitespaces at the begining of a string.
 * 
 * @param str string to be spaced-skipped.
 * @param start position where start skipping spaces. 
 * @return [Int] The position of the string after skipping spaces. 
 */
int	skip_whitespaces(char *str, int start)
{
	while (is_space_minishel(str[start]))
		start++;
	return (start);
}

/**
 * @brief Skips characters at the begining of a string.
 * 
 * @param str string to be char-skipped.
 * @param start position where start skipping characters. 
 * @return [Int] The position of the string after skipping chars. 
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
 * @return [Int] The position of the string
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
 * @return [Int] The position of the string 
 * 	after skipping cmd and flags.
 */
int	skip_cmd_and_flags(char	*cmd_line)
{
	int	i;

	i = 0;
	i = skip_cmd_name(cmd_line, 0);
	while (cmd_line[i] == '-')
		i = skip_characters_and_spaces(cmd_line, i);
	return (i);
}

/**
 * @brief Returns the position in the string after skipping
 * 	everithing that is not the quotes.
 * 
 * @param str String.
 * @param starting Starting position.
 * @return [Int] The position after skipping some characters. 
 */
int	skip_everything_til_quotes(char	*str, int starting)
{
	while (str[starting] && str[starting] != 34)
		starting++;
	starting++;
	return (starting);
}
