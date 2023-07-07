/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:01:44 by fortega-          #+#    #+#             */
/*   Updated: 2023/07/07 09:46:10 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_var(t_cmd *cmd)
{
	int	i;

	i = -1;
	if (ft_strchr(cmd->cmd, '=')
		&& ft_isalpha(cmd->cmd[0]))
	{
		printf("ASIG OK\n");
		return (EXIT_SUCCESS);
	}
	//printf("ASIG BAD\n");
	return (2);
}

int	check_bi(t_cmd *cmd, t_env *env)
{
	if (!(ft_strncmp((cmd->cmd), "cd", 3)))
		return (ft_cd(cmd, env));
	else if (!(ft_strncmp((cmd->cmd), "echo", 5)))
		return (ft_echo(cmd, env));
	else if (!(ft_strncmp((cmd->cmd), "env", 4)))
		return (ft_env(cmd, env));
	else if (!(ft_strncmp((cmd->cmd), "export", 7)))
		return (ft_export(cmd, env));
	else if (!(ft_strncmp((cmd->cmd), "pwd", 4)))
		return (ft_pwd(cmd, env));
	else if (!(ft_strncmp((cmd->cmd), "unset", 6)))
		return (ft_unset(cmd, env));
	else if (!(ft_strncmp((cmd->cmd), "exit", 5)))
		return (ft_exit(cmd, env));
	else if (check_var(cmd) == 0)
		return (EXIT_SUCCESS);
	else
	{
		//printf("por aqui no\n");
		return (2);
	}
}

void	processing(t_cmd *cmd, t_env *env)
{
	int	out;
	/*int		i;
	t_env	*vari;
	t_env	*tmp;

	(void)cmd;
	vari = env;
	while (vari)
	{
		i = 0;
		printf("Variable:\n%s\n", vari->var);
		printf("Valores: \n");
		while (vari->vals[i])
		{
			printf("%i. %s\n", i, vari->vals[i]);
			i++;
		}
		tmp = vari->next;
		vari = tmp;
	}*/


	//(void)env;
	if (cmd->nb_cmd == 1)
	{
		if (check_bi(cmd, env) == 2)
			printf("EXECV\n");
	}
	else
	{
		while (cmd)
		{
			out = check_bi(cmd, env);
			if (out)
				printf("Es builtIn\n");
			else
				printf("NO es builtIN\n");
			cmd = cmd->next;
		}
	}
}
