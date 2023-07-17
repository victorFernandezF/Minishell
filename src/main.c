/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:50:03 by victofer          #+#    #+#             */
/*   Updated: 2023/07/17 10:28:25 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	getfirstpid(t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (!(ft_strncmp("1PID", tmp->var, ft_strlen("1PID"))))
			return (ft_atoi(tmp->vals[0]));
		tmp = tmp->next;
	}
	return (0);
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
