/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envar_utils_exe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:36:19 by fortega-          #+#    #+#             */
/*   Updated: 2023/07/17 12:49:26 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int		fillmatenv2(t_env *var, char *str, int j);
void	shlvl_up(t_env *env);
int		n_vars(t_env *env);
int		cntvar(t_env *var);

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

char	**envtomatexecve(t_env *env)
{
	int		i;
	char	**mat;
	t_env	*tmp;

	shlvl_up(env);
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
	return (mat);
}
