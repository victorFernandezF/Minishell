/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_checks_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:51:06 by victofer          #+#    #+#             */
/*   Updated: 2023/07/10 12:12:22 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Checks if in any node of the struct the error is set to 1
 * 
 * @param cmd 
 * @return [Int] 1 if finds error in any node of the struct. 0 If not.
 */
int	check_errors_in_cmd(t_cmd *cmd)
{
	t_cmd	*tmp;
	int		error;

	tmp = cmd;
	error = 0;
	if (tmp->error == 1)
		error++;
	while (tmp->next != NULL)
	{
		if (tmp->error == 1)
			error++;
		tmp = tmp->next;
	}
	return (error);
}

/**
 * @brief Checks if there are som quotes in the string
 * before the given position.
 * 
 * @param str String.
 * @param end Position. Function will check quotes in the string
 * 	before this point.
 * @return [Int] 1 if quotes found and 0 if not. 
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
 * @return [Int] 1 if char c is found in string. 0 if not.
 */
int	search_char_in_str(char *str, char c)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (1);
	return (0);
}

int	not_empty(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	i = skip_whitespaces(str, i);
	if ((int)ft_strlen(str) == i)
		res = 1;
	return (res);
}
