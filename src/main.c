/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:50:03 by victofer          #+#    #+#             */
/*   Updated: 2023/05/12 10:16:09 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	main(int argc, char **argv)
{
	t_cmd	*cmd;
	int		i;

	atexit(leaks);
	cmd = NULL;
	cmd = init_struct(cmd);
	i = -1;
	if (argc >= 2)
		cmd = start_parser(cmd, argv[1]);
	i = -1;
	if (cmd->input == -1)
	{
		free_struct(cmd);
		return (0);
	}
	print_test(argv[1], cmd, 0);
	if (cmd != NULL)
		//free_struct(cmd);
	return (0);
}
