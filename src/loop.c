/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:07:10 by victofer          #+#    #+#             */
/*   Updated: 2023/07/28 09:52:00 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	sigdad(void);
void	sigchild(void);

/**
 * @brief Controls the signal 'SIGINT' so when user press ctrl-c
 * 	a new line will be displayed.
 *
 * @param sig Signal id.
 */
void	signal_handler(int sig)
{
	extern int	g_sign;

	if (sig == 2)
	{
		g_sign = 1;
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	if (sig == 3)
	{
		rl_on_new_line();
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
		exit(1);
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
	if (!pwd)
		pwd = "[Minishell]";
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
		sigdad();
		read = readline(prompt);
		sigchild();
		check_ctrl_d(read, env, prompt);
		if (read[0] != '\0')
			add_history(read);
		if (check_invalid_characters(read, env) == 0
			&& !not_empty(read, env) && read[0])
		{
			cmd = init_struct(cmd);
			start_parser(cmd, read, env);
			if (check_errors_in_cmd(cmd) == 0)
			{
				print_test(read, cmd, 0);
				processing(cmd, env);
			}
		}
		free_maximun_of_four_str(read, prompt, NULL, NULL);
	}
	free_struct(cmd);
}
