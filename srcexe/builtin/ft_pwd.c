/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:01:57 by fortega-          #+#    #+#             */
/*   Updated: 2023/06/23 15:13:14 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*get_pwd(t_env *env);

int	ft_pwd(t_cmd *cmd, t_env *env)
{
	char	*tmp;

	if (cmd->output != 0)
		return (EXIT_SUCCESS);
	tmp = ft_strjoin(get_pwd(env), "\n");
	ft_putstr_fd(tmp, 1);
	free(tmp);
	set_env(env, "?", "0");
	return (EXIT_SUCCESS);
}
