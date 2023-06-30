/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 13:39:43 by fortega-          #+#    #+#             */
/*   Updated: 2023/06/30 17:19:32 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**envtomatexp(t_env *env);

int	matsize(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
		i++;
	return (i);
}

void	sort_mat(char **mat)
{
	int		s;
	int		i;
	int		j;
	int		m;
	char	*tmp;

	s = matsize(mat);
	i = -1;
	while (++i < s)
	{
		j = -1;
		while (++j < s && mat[j + 1])
		{
			if (ft_strlen(mat[j]) < ft_strlen(mat[j + 1]))
				m = ft_strlen(mat[j]);
			else
				m = ft_strlen(mat[j + 1]);
			if (ft_strncmp(mat[j], mat[j + 1], m) > 0)
			{
				tmp = mat[j];
				mat[j] = mat[j + 1];
				mat[j + 1] = tmp;
			}
		}
	}
}

int	ft_export(t_cmd *cmd, t_env *env)
{
	char	**mat;
	int		i;

	if (!cmd->params || !cmd->params[0]
		|| cmd->params[0][0] == '\0')
	{
		mat = envtomatexp(env);
		sort_mat(mat);
		i = -1;
		while (mat[++i])
		{
			printf("%s\n", mat[i]);
		}
		free_mat(mat);
	}
	set_env(env, "?", "0");
	return (EXIT_SUCCESS);
}
