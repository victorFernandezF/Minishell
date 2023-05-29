/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:49:00 by victofer          #+#    #+#             */
/*   Updated: 2023/05/29 19:20:41 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_pipe_at_end_of_line(char	*str)
{
	int	i;

	i = get_position_of_last_char_found(str, '|');
	i = skip_whitespaces(str, i + 1);
	return (str[i] == '\0');
}

int	check_two_pipes_in_a_row(char *str, int i)
{
	if (str[i] == '|' && str[i + 1] == '|')
		return (1);
	return (0);
}

int	check_bad_redirection_chars(char *str, int i)
{
	if (str[i] == '>' && str[i + 1] == '<')
		return (1);
	if (str[i] == '<' && str[i + 1] == '>')
		return (1);
	return (0);
}

int	check_empty_cmd_or_bad_input_output(t_cmd *cmd)
{
	if (cmd == NULL && cmd->output == -1 && cmd->input == -1)
		return (1);
	if (cmd->nb_outputs > 0 && cmd->cmd[0] == '\0')
		return (1);
	return (0);
}

int	check_invalid_characters(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (check_two_pipes_in_a_row(str, i))
			return (printf("Syntax error.\n"));
		if (check_bad_redirection_chars(str, i))
			return (printf("Syntax error.\n"));
		if (str[0] == '|' || is_pipe_at_end_of_line(str))
			return (printf("Syntax error.\n"));
	}
	return (0);
}
