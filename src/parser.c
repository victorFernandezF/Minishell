/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 18:11:40 by victofer          #+#    #+#             */
/*   Updated: 2023/04/26 11:30:21 by victofer         ###   ########.fr       */
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
t_cmd	*fill_struct(t_cmd *tmp, char *command, int nb_cmd)
{
	char	**params;
	char	*param;
	t_cmd	*new;
	int		len;

	(void)nb_cmd;
	new = tmp;
	new->cmd = get_cmd(command);
	if (are_there_char(command, '-'))
		new->flags = get_flags(command);
	new->output = get_output(command, new);
	param = get_params(command);
	if (new->nb_outputs > 0)
	{
		len = ft_strlen(command);
		param = get_params_after_out(param, command, len);
	}
	params = ft_split_2(param);
	free(param);
	new->params = params;
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
	if (are_there_char(str, '#'))
		while (++i < nb_cmd)
			command[i] = transform_env_var(command[i]);
	cmd = fill_struct(cmd, command[0], nb_cmd);
	i = 0;
	if (nb_cmd > 1)
		while (command[++i] != NULL)
			cmd = fill_more_than_one(cmd, command[i], i + 1);
	free_array(command);
	return (cmd);
}
