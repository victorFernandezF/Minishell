/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:01:57 by fortega-          #+#    #+#             */
/*   Updated: 2023/07/10 10:08:29 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*get_pwd(t_env *env);

int	ft_pwd(t_cmd *cmd, t_env *env)
{
	char	*tmp;
	int		fd;

	if (cmd->input)
		close(cmd->input);
	fd = 1;
	if (cmd->output != 0)
		fd = cmd->output;
	tmp = ft_strjoin(get_pwd(env), "\n");
	ft_putstr_fd(tmp, fd);
	free(tmp);
	set_env(env, "?", "0");
	closeback(cmd);
	return (EXIT_SUCCESS);
}
