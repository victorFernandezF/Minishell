/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:50:03 by victofer          #+#    #+#             */
/*   Updated: 2023/06/19 18:13:50 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Change the terminal settings to avoid printing
 * '^C' when ctrl-c is pressed. And before exit the program
 * change the settings to its orriginal values.
 * 
 * @param set If 0, does not print '^C'. If 0, prints `^C`.
 */
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
	t_cmd	*cmd;

	(void)argv;
	cmd = NULL;
	settings(0);
	atexit(leaks);
	printf("%i\n", (int)getpid());
	if (argc == 1)
		mini_loop(cmd, env);
	else
		printf("Error: execute minishell without parameters\n");
	return (0);
}
