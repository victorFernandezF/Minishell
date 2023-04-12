/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:50:03 by victofer          #+#    #+#             */
/*   Updated: 2023/04/12 12:12:33 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_token(char c)
{
	return (c == '|');
}

t_cmd	*fill_struct(t_cmd *cmd, char **command, int nb_cmd)
{
	//int	i;
	int	output;

	(void)nb_cmd;
	(void)command;
	cmd = malloc(sizeof(t_cmd));
	cmd->cmd = get_part_from_str(command[0], 1);
	cmd->flags = get_part_from_str(command[0], 2);
	output = open(get_part_from_str(command[0], 3), O_CREAT);
	cmd->output = output;
	return (cmd);
}

void	start_parser(t_cmd *cmd, char *str)
{
	int		nb_cmd;
	char	**command;

	nb_cmd = get_nb_cmd(str, 1);
	command = ft_split(str, '|');
	cmd = fill_struct(cmd, command, nb_cmd);
	printf("test cmd 1 cmd -> %s\n", cmd->cmd);
	printf("test cmd 1 flag -> %s\n", cmd->flags);
	printf("test cmd 1 out -> %i\n", cmd->output);
}

int	main(int argc, char **argv)
{
	t_cmd	*cmd;

	cmd = NULL;
	if (argc >= 2)
		//printf("%i\n", is_token(argv[1][0]));
		start_parser(cmd, argv[1]);
	exit(-1);
	return (0);
}
