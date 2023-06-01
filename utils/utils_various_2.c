/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_various_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 19:07:02 by victofer          #+#    #+#             */
/*   Updated: 2023/06/01 12:45:42 by victofer         ###   ########.fr       */
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

int	is_between_quotes(char *str, int end)
{
	int	nb_quotes;
	int	i;

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
int	skip_chars_between_quotes(char *str, int start)
{
	if (str[start] != 34)
		return (start);
	start++;
	while (str[start] && str[start] != 34)
		start++;
	start++;
	start = skip_whitespaces(str, start);
	return (start);
}
