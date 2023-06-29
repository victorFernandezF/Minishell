/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:07:10 by victofer          #+#    #+#             */
/*   Updated: 2023/06/29 18:11:08 by victofer         ###   ########.fr       */
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
void	check_ctrl_d(char *read, t_env *envars, char *prompt)
{
	if (read == 0)
	{
		if (envars != NULL)
			freeenv(envars);
		printf("%s exit\n", prompt);
		settings(1);
		exit(0);
	}
}

/**
 * @brief Gets the PWD from the struct envars and combines it
 * whith fancy colors.
 * 
 * @param envars 
 * @return The actual directory finished in $ sign. 
 */
static char	*get_prompt(t_env *envars)
{
	char	*tmp;
	char	*res;
	char	*pwd;

	pwd = find_env_from_srruct(envars, "PWD");
	tmp = ft_strjoin("\x1B[32m", pwd);
	res = ft_strjoin(tmp, "$\x1B[0m ");
	free(tmp);
	return (res);
}

/**
 * @brief A loop that shows the prompt and wait for a command
 *  from the user.
 *
 */
void	mini_loop(t_cmd *cmd, t_env *envars)
{
	char	*read;
	char	*prompt;

	while (1)
	{
		prompt = get_prompt(envars);
		signal(SIGINT, signal_handler);
		read = readline(prompt);
		check_ctrl_d(read, envars, prompt);
		if (read[0] != '\0')
			add_history(read);
		if (check_invalid_characters(read, envars) == 0 && read[0])
		{
			cmd = init_struct(cmd);
			cmd = start_parser(cmd, read, envars);
			if (cmd->error == 0)
			{
				//print_test(read, cmd, 0);
				processing(cmd, envars);
			}
			free_struct(cmd);
		}
		free_maximun_of_four_str(read, prompt, NULL, NULL);
	}
	free_struct(cmd);
}
