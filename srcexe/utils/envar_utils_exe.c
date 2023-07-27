/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envar_utils_exe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:36:19 by fortega-          #+#    #+#             */
/*   Updated: 2023/07/27 10:06:24 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int		fillmatenv2(t_env *var, char *str, int j);
void	shlvl_up(t_env *env, bool ud);
int		n_vars(t_env *env);
int		cntvar(t_env *var);

int	find_str(char *str, char *tofind)
{
	int	i;
	int	f;

	i = 0;
	if (tofind[i] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		f = 0;
		while (str[i + f] != '\0' && str[i + f] == tofind[f])
		{
			if (tofind[f + 1] == '\0')
				return (1);
			f++;
		}
		i++;
	}
	return (0);
}

void	mv_shlvl(t_env *env, char *cmd)
{
	static int	ud;

	if (!ud)
		ud = 1;
	if (find_str(cmd, "minishell"))
	{
		if (ud == 1)
		{
			shlvl_up(env, true);
			ud = 2;
			return ;
		}
		if (ud == 2)
		{
			shlvl_up(env, false);
			ud = 1;
			return ;
		}
	}
}

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

char	*fillmatenvexe(t_env *env)
{
	char	*str;
	int		i;
	int		j;

	str = (char *)malloc((cntvar(env) + 1) * sizeof(char));
	i = 0;
	j = 0;
	while (env->var[i])
		str[j++] = env->var[i++];
	if (env->vals[0] == NULL)
	{
		str[j] = '\0';
		return (str);
	}
	str[j++] = '=';
	j += fillmatenv2(env, str, j);
	str[j] = '\0';
	return (str);
}

char	**envtomatexecve(t_env *env, char *cmd)
{
	int		i;
	char	**mat;
	t_env	*tmp;

	mv_shlvl(env, cmd);
	i = 0;
	mat = (char **)malloc((n_vars(env) + 1) * sizeof(char *));
	tmp = env;
	while (tmp && i < n_vars(env))
	{
		if (!(ft_strncmp("?", tmp->var, ft_strlen("?"))))
		{
			tmp = tmp->next;
			continue ;
		}
		mat[i] = fillmatenvexe(tmp);
		tmp = tmp->next;
		i++;
	}
	mat[i] = NULL;
	mv_shlvl(env, cmd);
	return (mat);
}
