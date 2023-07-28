/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:09:26 by victofer          #+#    #+#             */
/*   Updated: 2023/07/28 12:30:02 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	get_len_of_flags(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == '-')
	{
		i = skip_characters(str, i);
		i = skip_whitespaces(str, i);
	}
	return (i);
}

/**
 * @brief Splits the flags from the command_line
 * and store it in the struct.
 * 
 * @param cmd_line Command lime.
 * @return [Char *] The given line, after deleting the flags. 
 */
char	*get_flags(char *exp, char *cmd_line, t_cmd *cmd)
{
	int		start;
	char	*flags;
	char	*rest;
	char	*no_cmd;
	char	*copy;

	copy = ft_strdup(cmd_line);
	start = skip_characters_and_spaces(copy, 0);
	no_cmd = ft_substr(copy, start, strlen_starting_in(cmd_line, start));
	if (no_cmd[0] != '-')
	{
		free(copy);
		copy = ft_strdup(exp);
		cmd->flags = NULL;
		free_maximun_of_four_str(no_cmd, exp, NULL, NULL);
		return (copy);
	}
	start = get_len_of_flags(no_cmd);
	if (no_cmd[start] && no_cmd[start] != ' ')
		start--;
	flags = ft_substr(no_cmd, 0, start);
	cmd->flags = flags;
	start++;
	rest = ft_substr(exp, start, strlen_starting_in(exp, start));
	return (free_maximun_of_four_str(no_cmd, copy, exp, NULL), rest);
}
