/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:52:36 by fortega-          #+#    #+#             */
/*   Updated: 2023/07/17 09:41:11 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	matsize(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
		i++;
	return (i);
}

int	strmatsize(char **mat)
{
	int	i;
	int	j;
	int	l;

	i = -1;
	l = 0;
	while (mat[++i])
	{
		j = -1;
		while (mat[i][++j])
			l++;
		l++;
	}
	return (l);
}

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

int	get_shlvl(t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (!ft_strncmp(tmp->var, "SHLVL", ft_strlen("SHLVL")))
			return (ft_atoi(tmp->vals[0]));
		tmp = tmp->next;
	}
	return (0);
}

void	shlvl_up(t_env *env)
{
	int		now;
	char	*tmp;

	now = get_shlvl(env) + 1;
	tmp = ft_itoa(now);
	set_env(env, "SHLVL", tmp);
	free(tmp);
}
