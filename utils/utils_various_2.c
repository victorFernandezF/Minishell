/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_various_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 19:07:02 by victofer          #+#    #+#             */
/*   Updated: 2023/06/28 10:59:40 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Counts thenumber of words that are in the string.
 * 	Things inside double quotes count as one.
 * 
 * @param str String to be splitted.
 * @return thhe nomber of elements that the final array will have.
 */
int	count_words_minishell(char *str)
{
	int	cont;

	cont = 0;
	while (*str)
	{
		while (*str && is_space_minishel(*str))
			str++;
		if (*str == 34)
		{
			cont++;
			str++;
			while (*str && *str != 34)
				str++;
			str++;
		}
		else if (*str && !is_space_minishel(*str))
		{
			cont++;
			while (*str && !is_space_minishel(*str))
				str++;
		}
	}
	return (cont);
}

/**
 * @brief Checks if the given string is inside quotes.
 * 
 * @param str string
 * @param end  position where word starts
 * @return 1 if the word is inside quotes. 0 if not.
 */
int	is_between_double_quotes(char *str, int end)
{
	int	i;
	int	nb_quotes;

	i = -1;
	nb_quotes = 0;
	while (++i < end)
		if (str[i] == 34)
			nb_quotes++;
	if (nb_quotes == 0)
		return (0);
	if (nb_quotes % 2 == 0)
		return (0);
	return (1);
}

/**
 * @brief Skips whitespaces and chars at the begining of a string.
 * 
 * @param str string to be spacechar-skipped.
 * @param start position where start skipping spaces and chars. 
 * @return Integer whith the position of the string
 * 	after skipping spaces and chars. 
 */
int	skip_cmd_name(char *str, int start)
{
	if (str[start] != 34)
	{
		start = skip_characters_and_spaces(str, start);
		return (start);
	}
	start++;
	while (str[start] != '\0' && str[start] != 34)
		start++;
	start++;
	start = skip_whitespaces(str, start);
	return (start);
}

/**
 * @brief Creates a new string with everithing except cmd name and flags.
 *	The redirection characters are followed by '_'
 *	(ex: line 'echo -n hello > out world' will become 'hello >_out world')
 * 
 * @param cmd_line Line with the command line. 
 * @return String that contains everithing except cmd name and flags
 *	and the redirection characters are followed by '_'.
 */
char	*replace_spaces_after_redirect(char *cmd_line)
{
	int		i;
	int		j;
	int		len;
	char	*res;

	i = 0;
	len = strlen_starting_in(cmd_line, i);
	res = malloc((len + 1) * sizeof(char));
	j = 0;
	i = -1;
	while (cmd_line[++i])
	{
		if ((!is_between_double_quotes(cmd_line, i))
			&& ((cmd_line[i] == '>' && cmd_line[i + 1] == ' ')
				|| (cmd_line[i] == '<' && cmd_line[i + 1] == ' ')))
		{
			res[j] = cmd_line[i];
			res[j + 1] = '_';
			j += 2;
			i += 2;
		}
		res[j++] = cmd_line[i];
	}
	res[j] = '\0';
	return (res);
}
