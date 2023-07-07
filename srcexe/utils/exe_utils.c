/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:05:11 by fortega-          #+#    #+#             */
/*   Updated: 2023/07/07 18:31:08 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	argsize(t_cmd *cmd)
{
	int	s;

	s = 0;
	if (cmd->flags)
		s++;
	if (cmd->params)
		s += n_params(cmd->params) + 1;
	else
		s++;
	return (s);
}

char	*fillargmat(char *str)
{
	char	*arg;
	int		i;

	arg = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	i = -1;
	while (str[++i])
		arg[i] = str[i];
	arg[i] = '\0';
	return (arg);
}

char	*pathbar(char *path, char *cmd)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strjoin(path, "/");
	tmp2 = ft_strjoin(tmp, cmd);
	free (tmp);
	return (tmp2);
}

char	**get_binpath(t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (!(ft_strncmp("PATH", tmp->var, ft_strlen("PATH"))))
			return (tmp->vals);
		tmp = tmp->next;
	}
	return (NULL);
}
