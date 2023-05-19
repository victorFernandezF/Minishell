/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:09:26 by victofer          #+#    #+#             */
/*   Updated: 2023/05/19 13:17:31 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Get the flags of the command line.
 * 
 * @param cmd_line command_line
 * @return A string with the flags found.
 */
char	*get_flags(char *cmd_line)
{
	int		i;
	int		start;
	int		end;
	char	*flags;

	if (!are_there_char(cmd_line, '-'))
		return (NULL);
	start = skip_characters_and_spaces(cmd_line, 0);
	end = get_position_of_last_char_found(cmd_line, '-');
	end = skip_characters(cmd_line, end);
	flags = malloc ((end - start +1) * sizeof(char));
	if (!flags)
		return (NULL);
	i = 0;
	while (start < end)
		flags[i++] = cmd_line[start++];
	flags[i] = '\0';
	return (flags);
}
