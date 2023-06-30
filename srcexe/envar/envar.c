/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:01:44 by fortega-          #+#    #+#             */
/*   Updated: 2023/06/30 16:07:44 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	freevals(char **vals)
{
	int	i;

	i = 0;
	while (vals[i])
		i++;
	while (i >= 0)
	{
		free (vals[i]);
		i--;
	}
}

char	**emptyvar(void)
{
	char	**mat;
//	char	*str;

	//str = (char *)malloc(1 * sizeof(char));
	//str[0] = NULL;
	mat = (char **)malloc(1 * sizeof(char *));
	//mat[0] = str;
	mat[0] = NULL;
	return (mat);
}

void	freeenv(t_env *env)
{
	t_env	*tmp;
	t_env	*clean;

	tmp = env;
	while (tmp)
	{
		clean = tmp;
		tmp = tmp->next;
		free(clean->var);
		freevals(clean->vals);
		free(clean->vals);
		free(clean);
	}
}

t_env	*ft_new_envar(char *envar)
{
	t_env	*new;
	char	**tmp;

	new = malloc (sizeof(t_env));
	tmp = ft_splitf(envar);
	if (!new | !tmp)
		return (NULL);
	new->next = NULL;
	new->var = tmp[0];
	if (!(ft_strncmp("PATH", tmp[0], ft_strlen("PATH"))))
		new->vals = ft_split(tmp[1], ':');
	else if (!(ft_strncmp("OLDPWD", tmp[0], ft_strlen("OLDPWD"))))
		new->vals = emptyvar();
		//new->vals = ft_split(" ", '\0');
	else
		if (tmp[1])
			new->vals = ft_split(tmp[1], '\0');
	free (tmp[1]);
	free (tmp);
	return (new);
}

t_env	*ft_envar(char **env)
{
	t_env	*lst;
	t_env	*tmp;
	t_env	*next;
	int		i;

	i = 0;
	while (env[i])
	{
		if (i == 0)
		{
			lst = ft_new_envar(env[i]);
			tmp = lst;
		}
		else
		{
			next = ft_new_envar(env[i]);
			tmp->next = next;
			tmp = next;
		}
		i++;
	}
	tmp->next = ft_new_envar("?=0");
	return (lst);
}
