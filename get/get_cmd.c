/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:12:47 by victofer          #+#    #+#             */
/*   Updated: 2023/04/21 12:12:49 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/minishell.h"

/* 
 * get_nb_cmd
 * ----------------------------
 *	Counts the number of commands depending on the pipes.
 *
 *	PARAMS:
 *	-> str: string given by user.
 *
 * 	RETURN
 *	-> An integer with the number of commands found.
 */
int	get_nb_cmd(char *str)
{
	int	i;
	int	cmd;

	i = -1;
	cmd = 1;
	while (str[++i])
		if (str[i] == '|')
			cmd++;
	return (cmd);
}

/* 
 * get_cmd
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
	int		end;
	char	*res;

	i = 0;
	i = skip_characters(str, i);
	end = i;
	res = malloc(i * sizeof(char));
	if (!res)
		return (NULL);
	i = -1;
	while (++i < end)
		res[i] = str[i];
	res[i] = '\0';
	return (res);
}