/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- < fortega-@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:07:10 by victofer          #+#    #+#             */
/*   Updated: 2023/06/16 22:11:08 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Controls the signal 'SIGINT' so when user press ctrl-c
 * 	a new line will be displayed.
 *
 * @param sig Signal id.
 */
void	signal_handler(int sig)
{
	if (sig == 2)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

/**
 * @brief checks if readline takes EOF character which means
 * 	that shell must exit. (ctrl-d: exit the program).
 *
 * @param read The read line.
 */
void	check_ctrl_d(char *read, t_env *envars)
{
	if (read == 0)
	{
		if (envars != NULL)
			freeenv(envars);
		printf("\x1B[32m[MINISHELL]$\x1B[0m exit\n");
		settings(1);
		exit(0);
	}
}

/**
 * @brief A loop that shows the prompt and wait for a command
 *  from the user.
 *
 */
void	mini_loop(char **env)
{
	t_cmd	*cmd;
	t_env	*envars;
	char	*read;

	envars = ft_envar(env);
	while (1)
	{
		signal(SIGINT, signal_handler);
		read = readline("\x1B[32m[MINISHELL]$ \x1B[0m");
		check_ctrl_d(read, envars);
		if (read[0] != '\0')
			add_history(read);
		if (check_invalid_characters(read) == 0 && read[0])
		{
			cmd = init_struct(cmd);
			cmd = start_parser(cmd, read, envars);
			if (check_empty_cmd_or_bad_input_output(cmd) == 0)
			{
				print_test(read, cmd, 0);
				//processing(cmd, envars);
			}
			free_struct(cmd);
		}
		free(read);
	}
}
