/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:09:26 by victofer          #+#    #+#             */
/*   Updated: 2023/07/11 14:16:53 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Get the flags of the command line.
 * 
 * @param cmd_line command_line
 * @return [Char *] A string with the flags found.
 */
char	*get_flags(char *cmd_line, t_cmd *cmd)
{
	int		end;
	int		start;
	char	*flags;
	char	*rest;

	start = 0;
	if (cmd_line[0] != '-')
		return (cmd_line);
	end = get_position_of_last_char_found(cmd_line, '-');
	end = skip_characters(cmd_line, end);
	flags = ft_substr(cmd_line, start, end);
	if (!flags)
	{
		cmd->flags = NULL;
		return (cmd_line);
	}
	cmd->flags = flags;
	rest = ft_substr(cmd_line, end, ft_strlen(cmd_line));
	free(cmd_line);
	return (rest);
}
