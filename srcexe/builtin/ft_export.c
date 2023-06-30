/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 13:39:43 by fortega-          #+#    #+#             */
/*   Updated: 2023/06/30 17:53:20 by fortega-         ###   ########.fr       */
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



int	add_export(t_cmd *cmd, t_env *env)
{
	int		i;
	int		j;
	char	**mat;

	printf("%p\n", env);
	i = -1;
	while (cmd->params[++i])
	{
		mat = ft_split(cmd->params[i], '=');
		j = -1;
		while (mat[++j])
			printf("%s\n", mat[j]);
		printf("\n");
		free_mat(mat);
	}
	return (EXIT_SUCCESS);
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
	else
		return (add_export(cmd, env));
	set_env(env, "?", "0");
	return (EXIT_SUCCESS);
}
