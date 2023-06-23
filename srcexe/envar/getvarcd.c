/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getvarcd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:14:53 by fortega-          #+#    #+#             */
/*   Updated: 2023/06/23 10:32:08 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*get_home(t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (!(ft_strncmp("HOME", tmp->var, ft_strlen("HOME")))
			&& ft_strlen(tmp->var) == 4)
		{
			if (!tmp->vals)
				return ("$HOME");
			return (tmp->vals[0]);
		}
		tmp = tmp->next;
	}
	return ("$HOME");
}

char	*get_oldpwd(t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (!(ft_strncmp("OLDPWD", tmp->var, ft_strlen("OLDPWD"))))
		{
			if (!tmp->vals[0])
				return ("$OLDPWD");
			return (tmp->vals[0]);
		}
		tmp = tmp->next;
	}
	return ("$OLDPWD");
}

char	*get_pwd(t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (!(ft_strncmp("PWD", tmp->var, ft_strlen("PWD"))))
		{
			if (!tmp->vals)
				return (NULL);
			return (tmp->vals[0]);
		}
		tmp = tmp->next;
	}
	return (NULL);
}
