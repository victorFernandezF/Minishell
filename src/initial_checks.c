/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:49:00 by victofer          #+#    #+#             */
/*   Updated: 2023/06/29 18:07:41 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Checks if there are no more characters after a pipe
 * 	(skipping spaces).
 * 
 * @param str 
 * @return 1 is there are no more chars. 0 if there are more chars. 
 */
int	is_pipe_at_end_of_line(char	*str)
{
	int	i;

	i = get_position_of_last_char_found(str, '|');
	if (get_nb_cmd(str) == 1)
		return (0);
	i = skip_whitespaces(str, i + 1);
	return (str[i] == '\0');
}

/**
 * @brief Checks if there are two or more pipes in a row
 * 	skipping spaces between them.
 * 
 * @param str 
 * @param i 
 * @return 1 if there are more than one pipe in a row. 0 if not.
 */
int	check_two_pipes_in_a_row(char *str, int i)
{
	while (str[i])
	{
		if (str[i] == '|')
		{
			i++;
			i = skip_whitespaces(str, i);
			if (str[i] == '|')
				return (1);
		}
		i++;
	}
	return (0);
}

/**
 * @brief Checks if there are any redirection sign following by
 * an invalid character.
 * 
 * @param str 
 * @param i 
 * @return 1 if something is wrong. 0 if not.
 */
int	check_bad_redirection_chars(char *str, int i)
{
	if (str[i] == '>' && str[i + 1] == '<')
		return (1);
	if (str[i] == '<' && str[i + 1] == '>')
		return (1);
	if (str[i] == '>' && str[i + 1] != '>')
	{
		i++;
		i = skip_whitespaces(str, i);
		if (!ft_isalnum(str[i]) && !is_space_minishel(str[i]) && str[i] != '$')
			return (1);
	}
	if (str[i] == '<' && str[i + 1] != '<')
	{
		i++;
		i = skip_whitespaces(str, i);
		if (!ft_isalnum(str[i]) && !is_space_minishel(str[i]) && str[i] != '$')
			return (1);
	}
	return (0);
}

/**
 * @brief Checks if cmd line only contents a redirection without
 * 	the rest of the command (ex: [minishell]$ > output).
 * 
 * @param cmd 
 * @return 1 if somethin goes wrong. 0 if not. 
 */
int	check_empty_cmd_or_bad_input_output(t_cmd *cmd)
{
	if (cmd == NULL || cmd->output == -1 || cmd->input == -1)
		return (1);
	if (cmd->nb_inputs > 0 && cmd->input < 2)
		return (1);
	if (cmd->nb_outputs > 0 && cmd->output < 2)
		return (1);
	if (cmd->nb_outputs > 0 && cmd->cmd == NULL)
		return (1);
	if (cmd->nb_inputs > 0 && cmd->cmd == NULL)
		return (1);
	return (0);
}

/**
 * @brief Checks if there are any errors or invalid
 * 	chars combination before do anything.
 * 
 * @param str 
 * @return 0 if everything is ok. Something different than 0 if something
 * 	is worng and the execution must stop.
 */
int	check_invalid_characters(char *str, t_env *env)
{
	int	i;
	int	res;

	i = -1;
	res = 0;
	while (str[++i])
	{
		if (check_two_pipes_in_a_row(str, i))
			return (print_errors_by_code(1, env));
		if (check_unclosed_quotes(str))
			return (print_errors_by_code(1, env));
		if (check_bad_redirection_chars(str, i))
			return (print_errors_by_code(2, env));
		if (str[0] == '|' || is_pipe_at_end_of_line(str))
			return (print_errors_by_code(3, env));
	}
	return (res);
}
