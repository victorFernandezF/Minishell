/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:49:00 by victofer          #+#    #+#             */
/*   Updated: 2023/05/29 18:23:43 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_two_pipes_in_a_row(char *str, int i)
{
	return (str[i] == '|' && str[i + 1] == '|');
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
	return (cmd != NULL && cmd->output != -1 && cmd->input != -1);
}

int	check_invalid_characters(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (check_two_pipes_in_a_row(str, i))
			return (printf("Error.\n"));
		if (check_bad_redirection_chars(str, i))
			return (printf("Error.\n"));

	}
	return (0);
}
