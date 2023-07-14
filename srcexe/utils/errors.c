/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:53:21 by fortega-          #+#    #+#             */
/*   Updated: 2023/07/14 13:58:53 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	cmd_error(char *cmd, char *error, t_env *env)
{
	char	*one;
	char	*two;
	char	*three;
	char	*print;

	one = ft_strdup("minishell: ");
	two = ft_strjoin(one, cmd);
	free(one);
	three = ft_strjoin(two, ": ");
	free(two);
	print = ft_strjoin(three, error);
	free(three);
	ft_putendl_fd(print, STDERR_FILENO);
	free(print);
	set_env(env, "?", "1");
	return (EXIT_FAILURE);
}

int	cmd_cd_error(char *cmd, char *error, t_env *env)
{
	char	*one;
	char	*two;
	char	*three;
	char	*print;

	one = ft_strdup("minishell: ");
	two = ft_strjoin(one, cmd);
	free(one);
	three = ft_strjoin(two, ": ");
	free(two);
	print = ft_strjoin(three, error);
	free(error);
	free(three);
	ft_putendl_fd(print, STDERR_FILENO);
	free(print);
	set_env(env, "?", "1");
	return (EXIT_FAILURE);
}

void	check_signal(t_env *env)
{
	extern int	g_sign;
	char		*nb;

	if (g_sign == 1)
	{
		nb = ft_itoa(g_sign);
		set_env(env, "?", nb);
		free(nb);
		g_sign = 0;
	}
}

void	signal_handler_child(int sig)
{
	printf("Hijo\n");
	(void)sig;
	exit(0);
}
