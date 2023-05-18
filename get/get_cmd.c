/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:12:47 by victofer          #+#    #+#             */
/*   Updated: 2023/05/18 10:08:52 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* 
 * get_nb_cmd (get/get_cmd.c)
 * ----------------------------
 *	Counts the number of commands depending on the pipes.
 *
 *	PARAMS:
 *	-> str: string given by user.
 *
 * 	RETURN
 *	-> The number of commands found.
 */
int	get_nb_cmd(char *str)
{
	int	i;
	int	cmd;

	i = -1;
	cmd = 1;
	while (str[++i])
		if (is_pipe(str[i]))
			cmd++;
	return (cmd);
}

/* 
 * get_cmd (get/get_cmd.c)
 * ----------------------------
 *	Splits the name of the command from the given string
 *
 *	PARAMS:
 *	-> str: string given by user.
 *
 * 	RETURN
 *	-> A string with the command name.
 */
char	*get_cmd(char *str)
{
	int		i;
	int		j;
	int		len;
	char	*cmd_name;

	i = -1;
	j = 0;
	i = skip_whitespaces(str, 0);
	len = skip_characters(str, i);
	cmd_name = malloc((len + 1) * sizeof(char));
	if (!cmd_name)
		return (NULL);
	while (str[i] != ' ' && str[i] != '\0')
		cmd_name[j++] = str[i++];
	cmd_name[j] = '\0';
	return (cmd_name);
}
