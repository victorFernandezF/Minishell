/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:50:03 by victofer          #+#    #+#             */
/*   Updated: 2023/04/18 12:20:56 by victofer         ###   ########.fr       */
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
	int		i;

	i = -1;
	nb_cmd = get_nb_cmd(str);
	command = ft_split(str, '|');
	if (are_there_char(str, '#'))
		while (++i < nb_cmd)
			command[i] = transform_env_var(command[i]);
	cmd = fill_struct(cmd, command, nb_cmd);
	printf("%s\n", command[0]);
	free_array(command);
	return (cmd);
}

int	main(int argc, char **argv)
{
	t_cmd	*cmd;
	int		i;

	cmd = NULL;
	i = -1;
	if (argc >= 2)
		cmd = start_parser(cmd, argv[1]);
	printf("test cmd -> %s\n", cmd->cmd);
	printf("test flg -> %s\n", cmd->flags);
	printf("test params -> %s\n", cmd->params);
	printf("test nb_out -> %i\n", cmd->nb_outputs);
	while (++i < cmd->nb_outputs)
		printf("test out %i -> %i\n", i, cmd->output[i]);
	free_struct(cmd);
	return (0);
}
