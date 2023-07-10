/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:07:10 by victofer          #+#    #+#             */
/*   Updated: 2023/07/10 12:22:23 by victofer         ###   ########.fr       */
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
void	check_ctrl_d(char *read, t_env *env, char *prompt)
{
	if (read == 0)
	{
		if (env != NULL)
			freeenv(env);
		printf("%s exit\n", prompt);
		exit(0);
	}
}

/**
 * @brief Gets the PWD from the struct env and combines it
 * whith fancy colors.
 *
 * @param env
 * @return [Char *] The actual directory finished in $ sign.
 */
static char	*get_prompt(t_env *env)
{
	char	*tmp;
	char	*res;
	char	*pwd;

	pwd = find_env_from_srruct(env, "PWD");
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
void	mini_loop(t_cmd *cmd, t_env *env)
{
	char	*read;
	char	*prompt;

	while (1)
	{
		prompt = get_prompt(env);
		signal(SIGINT, signal_handler);
		read = readline(prompt);
		check_ctrl_d(read, env, prompt);
		if (read[0] != '\0')
			add_history(read);
		if (check_invalid_characters(read, env) == 0
			&& !not_empty(read, env) && read[0])
		{
			cmd = init_struct(cmd);
			cmd = start_parser(cmd, read, env);
			if (check_errors_in_cmd(cmd) == 0)
			{
				print_test(read, cmd, 0);
				processing(cmd, env);
			}
			free_struct(cmd);
		}
		free_maximun_of_four_str(read, prompt, NULL, NULL);
	}
	free_struct(cmd);
}
