/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:50:03 by victofer          #+#    #+#             */
/*   Updated: 2023/07/07 14:23:39 by victofer         ###   ########.fr       */
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
void	settings(void)
{
	struct termios	settings;

	if (tcgetattr(0, &settings))
		perror("Error");
	settings.c_lflag &= ~ECHOCTL;
	if (tcsetattr(0, 0, &settings))
		perror("Error.");
}

int	main(int argc, char **argv, char **env)
{
	t_cmd	*cmd;
	t_env	*envars;

	(void)argv;
	cmd = NULL;
	envars = ft_envar(env);
	settings();
	atexit(leaks);
	printf("%i\n", (int)getpid());
	if (argc == 1)
		mini_loop(cmd, envars);
	else
	{
		ft_putendl_fd("Error: execute minishell without parameters", 2);
		free_struct(cmd);
		freeenv(envars);
	}
	return (0);
}
