/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:50:03 by victofer          #+#    #+#             */
/*   Updated: 2023/07/24 10:14:45 by victofer         ###   ########.fr       */
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
}

void	title(void)
{
	printf("%s\n", B);
	printf(" ███╗   ███╗██╗███╗   ██╗██╗██████╗██╗  ██╗██████╗██╗    ██╗\n");
	printf(" ████╗ ████║██║████╗  ██║██║██╔═══╝██║  ██║██╔═══╝██║    ██║\n");
	printf(" ██╔████╔██║██║██╔██╗ ██║██║██████╗███████║████╗  ██║    ██║\n");
	printf(" ██║╚██╔╝██║██║██║╚██╗██║██║╚════█║██╔══██║██╔═╝  ██║    ██║\n");
	printf(" ██║ ╚═╝ ██║██║██║ ╚████║██║██████║██║  ██║██████╗██████╗██████╗\n");
	printf(" ╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚═════╝╚═╝  ╚═╝╚═════╝╚═════╝╚═════╝\n");
	printf("                    FORTEGA-  VICTOFER        %s\n\n", W);
}

int	main(int argc, char **argv, char **env)
{
	t_cmd	*cmd;
	t_env	*envars;
	char	*tmp;

	(void)argv;
	if (argc != 1)
	{
		ft_putendl_fd("Error: execute minishell without parameters", 2);
		return (0);
	}
	cmd = NULL;
	tmp = ft_itoa(getpid());
	envars = ft_envar(env);
	if (!is_env(envars, "1PID"))
		set_env(envars, "1PID", tmp);
	free(tmp);
	atexit(leaks);
	settings();
	title();
	printf("First PID: %d\n", getfirstpid(envars));
	mini_loop(cmd, envars);
	return (0);
}
