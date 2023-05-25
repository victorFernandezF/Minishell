/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:50:03 by victofer          #+#    #+#             */
/*   Updated: 2023/05/25 13:44:19 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	sighandler(int sig)
{
	if (sig == 2)
		exit(0);
}

int	main(void)
{
	t_cmd	*cmd;
	char	*read;

	atexit(leaks);
	cmd = NULL;
	cmd = init_struct(cmd);
	signal(SIGINT, sighandler);
	while (1)
	{
		read = readline("\x1B[32m[MINISHELL]: \x1B[0m");
		if (read[0] != '\0')
			add_history(read);
		if (read[0])
		{
			free_struct(cmd);
			cmd = init_struct(cmd);
			cmd = start_parser(cmd, read);
			if (cmd != NULL)
				print_test(read, cmd, 0);
		}
	}
	if (cmd != NULL)
		free_struct(cmd);
	return (0);
}
