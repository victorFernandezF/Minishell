/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 18:11:40 by victofer          #+#    #+#             */
/*   Updated: 2023/05/18 10:04:17 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* 
 * fill_struct (src/parser.c)
 * ----------------------------
 *	This function sets the components of the
 *	cmd line into the struct. 
 *
 *	PARAMS:
 *	-> cmd: The structure created at main. 
 *	-> command: An string whith the given command
 *
 * 	RETURN
 *	-> cmd: the given struct struct.
 */
t_cmd	*fill_struct(t_cmd *tmp, char *command)
{
	char	*no_outputs;
	char	*no_output_input;
	char	*spanded;
	t_cmd	*new;

	new = tmp;
	spanded = spand_all_env_vasr(command);
	new->nb_outputs = get_nb_outputs(spanded);
	new->output = get_output(spanded, new);
	no_outputs = delete_outputs_from_line(spanded);
	new->cmd = get_cmd(no_outputs);
	new->flags = get_flags(no_outputs);
	new->nb_inputs = get_nb_inputs(spanded);
	new->input = get_input(spanded, new);
	no_output_input = delete_inputs_from_line(no_outputs);
	new->params = get_parameters(no_output_input);
	free(no_output_input);
	free(no_outputs);
	free(spanded);
	return (new);
}

/* 
 * start_parser (src/parser.c)
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
 *	-> cmd: the struct filled witth the different parts of
 *	the command.
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
