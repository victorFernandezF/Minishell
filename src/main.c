/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:50:03 by victofer          #+#    #+#             */
/*   Updated: 2023/04/14 13:07:47 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*fill_struct(t_cmd *cmd, char **command, int nb_cmd)
{
	(void)nb_cmd;
	cmd = malloc(sizeof(t_cmd));
	cmd->cmd = get_part_from_str(command[0], 1);
	if (are_there_char(command[0], '-'))
		cmd->flags = get_part_from_str(command[0], 2);
	cmd->params = get_part_from_str(command[0], 3);
	cmd->output = get_output(command[0], cmd);
	return (cmd);
}

t_cmd	*start_parser(t_cmd *cmd, char *str)
{
	int		nb_cmd;
	char	**command;

	nb_cmd = get_nb_cmd(str);
	command = ft_split(str, '|');
	cmd = fill_struct(cmd, command, nb_cmd);
	free_array(command);
	return (cmd);
}

int	main(int argc, char **argv)
{
	t_cmd	*cmd;

	//atexit(leaks);
	cmd = NULL;
	if (argc >= 2)
		cmd = start_parser(cmd, argv[1]);
	printf("test cmd -> %s\n", cmd->cmd);
	printf("test flg -> %s\n", cmd->flags);
	printf("test params -> %s\n", cmd->params);
	printf("test out -> %i\n", cmd->output[0]);
	printf("test out -> %i\n", cmd->output[1]);
	printf("test nb_out -> %i\n", cmd->nb_outputs);
	free_struct(cmd);
	return (0);
}
