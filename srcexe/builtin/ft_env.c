/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 09:11:39 by fortega-          #+#    #+#             */
/*   Updated: 2023/06/30 11:32:13 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_cntenv(t_env *env)
{
	int		i;
	int		j;
	int		t;
	t_env	*tmp;

	t = 0;
	tmp = env;
	while (tmp)
	{
		i = 0;
		j = -1;
		t += ft_strlen(tmp->var) + 1;
		while (tmp->vals[++j])
		{
			if (!(ft_strncmp("?", tmp->var, ft_strlen("?"))))
				continue ;
			while (tmp->vals[j][i++])
				t++;
		}
		if (tmp->next)
			t++;
		tmp = tmp->next;
	}
	return (t);
}

int	ft_etaval(char *str, int v, int i, t_env *var)
{
	int	j;

	j = 0;
	while (var->vals[v][j])
	{
		str[i++] = var->vals[v][j++];
	}
	if (!(ft_strncmp("PATH", var->var, ft_strlen("PATH"))))
	{
		if (var->vals[v + 1])
		{
			str[i++] = ':';
			j++;
		}
	}
	return (j);
}

int	ft_etavar(char *str, char *var, int i)
{
	int	j;

	j = 0;
	while (var[j])
	{
		str[i++] = var[j++];
	}
	str[i] = '=';
	j++;
	return (j);
}

char	*envtoarray(t_env *env, char *str)
{
	int		i;
	int		j;
	t_env	*tmp;

	tmp = env;
	i = 0;
	while (tmp)
	{
		if (!(ft_strncmp("?", tmp->var, ft_strlen("?"))))
		{
			tmp = tmp->next;
			continue ;
		}
		i += ft_etavar(str, tmp->var, i);
		j = -1;
		while (tmp->vals[++j])
			i += ft_etaval(str, j, i, tmp);
		if (tmp->next)
			str[i++] = '\n';
		else
			str[i] = '\0';
		tmp = tmp->next;
	}
	return (str);
}

int	ft_env(t_env *env)
{
	char	*str;

	str = (char *)malloc((ft_cntenv(env) + 1) * sizeof(char));
	str = envtoarray(env, str);
	ft_putstr_fd(str, 1);
	free(str);
	set_env(env, "?", "0");
	return (EXIT_SUCCESS);
}
