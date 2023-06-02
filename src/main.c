/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:50:03 by victofer          #+#    #+#             */
/*   Updated: 2023/06/02 12:39:10 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	settings(int set)
{
	struct termios	old_settings;
	struct termios	settings;

	if (tcgetattr(0, &old_settings))
		perror("Error");
	if (set == 0)
	{
		settings = old_settings;
		settings.c_lflag &= ~ECHOCTL;
		if (tcsetattr(0, 0, &settings))
			perror("Error.");
	}
	if (set == 1)
	{
		settings = old_settings;
	}
}

int	main(int argc, char **argv, char **env)
{
	(void)argv;
	settings(0);
	atexit(leaks);
	printf("%i\n", (int)getpid());
	if (argc == 1)
		mini_loop(env);
	else
		printf("Error: execute minishell without parameters\n");
	return (0);
}
