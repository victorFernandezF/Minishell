/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_quotation_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 11:56:49 by victofer          #+#    #+#             */
/*   Updated: 2023/06/28 11:26:07 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Checks if a specific word inside an array is between
 *  simple quotes.
 * 
 * @param array Array
 * @param pos Postition of the word in the array
 * @return 1 if it is inside simple quotes. 0 if not.
 */
int	is_inside_simple_quotes(char **array, int pos)
{
	int	i;
	int	j;
	int	nb_q;

	i = -1;
	nb_q = 0;
	while (array[++i])
	{
		if (i == pos)
			break ;
		j = -1;
		while (array[i][++j])
			if (array[i][j] == 39)
				nb_q++;
		j = -1;
		if (array[pos][++j])
			if (array[pos][j] == 39)
				nb_q++;
	}
	return (!(nb_q % 2 == 0));
}

/**
 * @brief Checks if a simple word is inside simple quotes.
 * 
 * @param str Word to be checked
 * @return 1 if it is between quotes. 0 if not.
 */
int	check_simple_quotes(char *str)
{
	int	len;
	int	res;
	int	end;
	int	begin;

	len = ft_strlen(str) -1;
	begin = 0;
	end = 0;
	res = 0;
	if (str[0] == 39)
		begin = 1;
	if (str[len] == 39)
		end = 1;
	if (begin == 1 && end == 1)
		res = 1;
	return (res);
}

/**
 * @brief Checks if the given string is inside quotes.
 * 
 * @param str string
 * @param end  position where word starts
 * @return 1 if the word is inside quotes. 0 if not.
 */
int	is_between_simple_quotes(char *str, int end)
{
	int	i;
	int	nb_quotes;

	i = -1;
	nb_quotes = 0;
	while (++i < end)
		if (str[i] == 39)
			nb_quotes++;
	if (nb_quotes == 0)
		return (0);
	if (nb_quotes % 2 == 0)
		return (0);
	return (1);
}

/**
 * @brief Checks if there are unclosed quotation marks 
 * 
 * @param str string
 * @return 0 If every quotation mark opened is closed.
 * 	 1 if any opened quotation mark is not closed.
 */
int	check_unclosed_quotes(char *str)
{
	int		i;
	int		nb_quot;

	i = -1;
	nb_quot = 0;
	while (str[++i])
		if (str[i] == 39 || str[i] == 34)
			nb_quot++;
	if (nb_quot % 2 == 0)
		return (0);
	return (1);
}