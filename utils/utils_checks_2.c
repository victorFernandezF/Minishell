/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_checks_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:51:06 by victofer          #+#    #+#             */
/*   Updated: 2023/07/12 13:25:44 by victofer         ###   ########.fr       */
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
	t_cmd	*cmd_2;
	t_cmd	*tmp;
	int		error;

	error = 0;
	cmd_2 = cmd;
	while (cmd_2)
	{
		if (cmd_2->error == 1)
			error++;
		tmp = tmp->next;
		tmp = cmd_2->next;
		cmd_2 = tmp;
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

int	not_empty(char *str, t_env *env)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	i = skip_whitespaces(str, i);
	if ((int)ft_strlen(str) == i)
		res = 1;
	if ((str[0] == 39 || str[0] == 34))
	{
		i = skip_whitespaces(str, i);
		if ((str[i] == 39 || str[i] == 34))
		{
			res = 1;
			print_errors_by_code(4, env);
		}	
	}
	return (res);
}
