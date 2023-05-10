/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 18:11:40 by victofer          #+#    #+#             */
/*   Updated: 2023/05/10 13:00:18 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
t_cmd	*fill_struct(t_cmd *tmp, char *command)
{
	char	**parameters;
	char	*param;
	t_cmd	*new;

	new = tmp;
	new->cmd = get_cmd(command);
	if (are_there_char(command, '-'))
		new->flags = get_flags(command);
	new->nb_outputs = get_nb_outputs(command);
	new->output = get_output(command, new);
	new->nb_inputs = get_nb_inputs(command);
	new->input = get_input(command, new);
	if (new->nb_outputs > 0)
		param = del_outputs(command);
	else
		param = get_params(command);
	parameters = ft_split_2(param);
	free(param);
	new->params = parameters;
	new = check_env_param(new);
	return (new);
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
	t_cmd	*og_cmd;

	og_cmd = cmd;
	i = -1;
	nb_cmd = get_nb_cmd(str);
	command = ft_split(str, '|');
	cmd = fill_struct(cmd, command[0]);
	i = 0;
	if (nb_cmd > 1)
		while (command[++i] != NULL)
			cmd = fill_more_than_one(cmd, command[i], i + 1);
	free_array(command);
	return (cmd);
}
