/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:50:03 by victofer          #+#    #+#             */
/*   Updated: 2023/07/13 12:50:22 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
