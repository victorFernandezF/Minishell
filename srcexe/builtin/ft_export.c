/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 13:39:43 by fortega-          #+#    #+#             */
/*   Updated: 2023/07/10 10:08:24 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_env	*ft_new_envar(char *envar);
char	**envtomatexp(t_env *env);
int		strmatsize(char **mat);
int		matsize(char **mat);

char	*mattostr(char **mat)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	str = (char *)malloc((strmatsize(mat) + 1) * sizeof(char));
	i = -1;
	k = 0;
	while (mat[++i])
	{
		j = -1;
		while (mat[i][++j])
			str[k++] = mat[i][j];
		str[k++] = '\n';
	}
	str[k] = '\0';
	return (str);
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

void	insert_var(char *envar, t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = ft_new_envar(envar);
}

int	add_export(t_cmd *cmd, t_env *env)
{
	int		i;
	char	*tmp;

	i = -1;
	while (cmd->params[++i])
	{
		if (ft_isalpha(cmd->params[i][0]) == 0)
		{
			tmp = ft_strjoin(cmd->params[i], ": not a valid identifier");
			cmd_cd_error("export", tmp, env);
			set_env(env, "?", "1");
			continue ;
		}
		insert_var(cmd->params[i], env);
		set_env(env, "?", "0");
	}
	return (EXIT_SUCCESS);
}

int	ft_export(t_cmd *cmd, t_env *env)
{
	char	**mat;
	char	*str;
	int		fd;

	if (cmd->input)
		close(cmd->input);
	fd = 1;
	if (cmd->output != 0)
		fd = cmd->output;
	if (!cmd->params || !cmd->params[0]
		|| cmd->params[0][0] == '\0')
	{
		mat = envtomatexp(env);
		sort_mat(mat);
		str = mattostr(mat);
		free_mat(mat);
		ft_putstr_fd(str, fd);
		free(str);
	}
	else
		return (add_export(cmd, env));
	set_env(env, "?", "0");
	closeback(cmd);
	return (EXIT_SUCCESS);
}
