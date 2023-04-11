/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:50:03 by victofer          #+#    #+#             */
/*   Updated: 2023/04/11 19:13:29 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_token(char c)
{
	return (c == '|');
}

void	start_parser(t_cmd *cmd, char *str)
{
	int		nb_cmd;
	int		i;
	char	**command;
	t_cmd	**cmd_list;

	(void)cmd;
	nb_cmd = 1;
	i = 0;
	while (str[i])
	{
		if (is_token(str[i]))
			nb_cmd++;
		i++;
	}
	i = 0;
	//printf("%i\n", nb_cmd);
	command = ft_split_2(str);
	cmd_list = malloc(sizeof(t_cmd) * nb_cmd);
	while (command[i])
	{
		if (is_token(command[i][0]))
			i++;
		printf("%s\n", command[i]);
		i++;
	}
	//printf("%s\n", cmd_list[0]->cmd);
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
