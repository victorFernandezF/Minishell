/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envar_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 13:44:00 by fortega-          #+#    #+#             */
/*   Updated: 2023/07/17 09:00:05 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	n_vars(t_env *env)
{
	int		t;
	t_env	*tmp;

	t = 0;
	tmp = env;
	while (tmp)
	{
		if (!(ft_strncmp("?", tmp->var, ft_strlen("?"))))
		{
			tmp = tmp->next;
			continue ;
		}
		tmp = tmp->next;
		t++;
	}
	return (t);
}

int	cntvar(t_env *var)
{
	int	t;
	int	i;
	int	j;

	t = 0;
	i = -1;
	j = -1;
	while (var->var[++i])
		t++;
	if (var->vals[0] == NULL)
		return (t);
	t++;
	while (var->vals && var->vals[++j])
	{
		i = -1;
		while (var->vals[j][++i])
		{
			t++;
		}
		if (!(ft_strncmp("PATH", var->var, ft_strlen("PATH")))
			&& var->vals[j + 1])
			t++;
	}
	//t += 2;
	return (t);
}

int	fillmatenv2(t_env *var, char *str, int j)
{
	int	i;
	int	k;
	int	t;

	t = 0;
	k = 0;
	while (var->vals && var->vals[k])
	{
		i = 0;
		while (var->vals[k][i])
		{
			str[j++] = var->vals[k][i++];
			t++;
		}
		if (!(ft_strncmp("PATH", var->var, ft_strlen("PATH")))
			&& var->vals[k + 1])
		{
			str[j++] = ':';
			t++;
		}
		k++;
	}
	return (t);
}

char	*fillmatenv(t_env *env)
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
	//str[j++] = '"';
	j += fillmatenv2(env, str, j);
	//str[j++] = '"';
	str[j] = '\0';
	return (str);
}

char	**envtomatexp(t_env *env)
{
	int		i;
	char	**mat;
	t_env	*tmp;

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
		mat[i] = fillmatenv(tmp);
		tmp = tmp->next;
		i++;
	}
	mat[i] = NULL;
	return (mat);
}
