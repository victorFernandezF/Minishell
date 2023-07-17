/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:50:03 by victofer          #+#    #+#             */
/*   Updated: 2023/07/17 12:52:04 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		getfirstpid(t_env *env);
void	signal_handler_child(int sig);

void	s_handler(t_env *env)
{
	if (getfirstpid(env) == getpid())
	{
		signal(SIGINT, signal_handler);
		signal(SIGQUIT, signal_handler);
	}
	/*else
	{
		freeenv(env);
		signal(SIGINT, signal_handler_child);
		signal(SIGQUIT, signal_handler_child);
	}*/
}

int	main(int argc, char **argv, char **env)
{
	t_cmd	*cmd;
	t_env	*envars;
	char	*tmp;

	(void)argv;
	tmp = ft_itoa(getpid());
	cmd = NULL;
	envars = ft_envar(env);
	if (!is_env(envars, "1PID"))
		set_env(envars, "1PID", tmp);
	free(tmp);
	printf("First PID: %d\n", getfirstpid(envars));
	settings();
	//atexit(leaks);
	printf("%i\n", (int)getpid());
	//s_handler(envars);
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
