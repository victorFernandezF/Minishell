/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:28:13 by fortega-          #+#    #+#             */
/*   Updated: 2023/07/28 09:16:11 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	echo_len(t_cmd *cmd, bool n)
{
	int	i;
	int	l;

	i = -1;
	l = 0;
	while (++i < n_params(cmd->params))
	{
		l += ft_strlen(cmd->params[i]);
		if (i + 1 < n_params(cmd->params))
			l++;
	}
	if (n == false)
		l++;
	return (l);
}

void	echo_str(t_cmd *cmd, t_env *env, bool n, int fd)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	i = -1;
	k = 0;
	str = (char *)malloc((echo_len(cmd, n) + 1) * sizeof(char));
	while (++i < n_params(cmd->params))
	{
		j = -1;
		while (cmd->params[i][++j])
			str[k++] = cmd->params[i][j];
		if (i + 1 < n_params(cmd->params))
			str[k++] = 32;
	}
	if (n == false)
		str[k++] = '\n';
	str[k] = '\0';
	ft_putstr_fd(str, fd);
	free(str);
	set_env(env, "?", "0");
}

void	print_echo(t_cmd *cmd, t_env *env, bool n, int fd)
{
	if ((!cmd->params || !cmd->params[0]
			|| cmd->params[0][0] == '\0') && n == true)
		set_env(env, "?", "0");
	else if ((!cmd->params || !cmd->params[0]
			|| cmd->params[0][0] == '\0') && n == false)
	{
		ft_putstr_fd("\n", fd);
		set_env(env, "?", "0");
	}
	else
	{
		echo_str(cmd, env, n, fd);
	}
}

int	ft_echo(t_cmd *cmd, t_env *env)
{
	int	fd;

	if (cmd->input && cmd->owin == 1)
		close(cmd->input);
	fd = 1;
	if (cmd->output != 0)
		fd = cmd->output;
	if (cmd->flags)
	{
		if (!(ft_strncmp("-n", cmd->flags, ft_strlen("-n"))))
		{
			print_echo(cmd, env, true, fd);
			return (EXIT_SUCCESS);
		}
		else
			return (cmd_error("echo", "Only -n option allowed", env));
	}
	else
	{
		print_echo(cmd, env, false, fd);
		closeback(cmd);
		return (EXIT_SUCCESS);
	}
}
