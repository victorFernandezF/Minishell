/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:07:10 by victofer          #+#    #+#             */
/*   Updated: 2023/05/25 19:20:56 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	signal_handler(int sig)
{
	if (sig == 2)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 3);
		rl_redisplay();
	}
}

void	mini_loop(void)
{
	t_cmd	*cmd;
	char	*read;

	while (1)
	{
		signal(SIGINT, signal_handler);
		read = readline("\x1B[32m[MINISHELL]: \x1B[0m");
		if (read == 0)
			exit(0);
		if (read[0] != '\0')
			add_history(read);
		if (read[0])
		{
			cmd = init_struct(cmd);
			cmd = start_parser(cmd, read);
			if (cmd != NULL)
				print_test(read, cmd, 0);
			free_struct(cmd);
			free(read);
		}
	}
}
