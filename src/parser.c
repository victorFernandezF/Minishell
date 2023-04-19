/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 18:11:40 by victofer          #+#    #+#             */
/*   Updated: 2023/04/19 12:19:25 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* 
 * fill_struct
 * ----------------------------
 *	This function is supose to set the components of the
 *	cmd line. 
 *
 *	PARAMS:
 *	-> cmd: The structure created at main. 
 *	-> command: An array of strings whith the given command
 *		if there are pipes in the line, there will be variosus
 *		elements in the array
 *
 * 	RETURN
 *	-> cmd: the given struct struct.
 */
t_cmd	*fill_struct(t_cmd *cmd, char **command, int nb_cmd)
{
	char	**params;
	char	*param;

	(void)nb_cmd;
	cmd = malloc(sizeof(t_cmd));
	cmd->cmd = get_part_from_str(command[0], 1);
	if (are_there_char(command[0], '-'))
		cmd->flags = get_part_from_str(command[0], 2);
	param = get_part_from_str(command[0], 3);
	params = ft_split_2(param);
	free(param);
	cmd->params = params;
	cmd->output = get_output(command[0], cmd);
	return (cmd);
}

/* 
 * start_parser
 * ----------------------------
 *	This is the main parser function.
 *	It separate the different parts of the cmd line. 
 *
 *	PARAMS:
 *	-> cmd: The structure created at main. 
 *		At this point it has nothing.
 *	-> str: A string whith the whole commad (ex: echo -n "hello" > out)
 *
 * 	RETURN
 *	-> cmd: the given struct struct.
 */
t_cmd	*start_parser(t_cmd *cmd, char *str)
{
	int		nb_cmd;
	char	**command;
	int		i;

	i = -1;
	nb_cmd = get_nb_cmd(str);
	command = ft_split(str, '|');
	if (are_there_char(str, '#'))
		while (++i < nb_cmd)
			command[i] = transform_env_var(command[i]);
	cmd = fill_struct(cmd, command, nb_cmd);
	free_array(command);
	return (cmd);
}
