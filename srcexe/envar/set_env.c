/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 21:01:28 by fortega-          #+#    #+#             */
/*   Updated: 2023/07/17 10:21:51 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_env	*new_set(char *var, char *vals)
{
	t_env	*new;
	char	*var2;

	new = malloc (sizeof(t_env));
	new->next = NULL;
	var2 = ft_strdup(var);
	new->var = var2;
	if (!(ft_strncmp("PATH", var2, ft_strlen("PATH"))))
		new->vals = ft_split(vals, ':');
	else
		if (vals)
			new->vals = ft_split(vals, '\0');
	return (new);
}

void	set_env(t_env *env, char *var, char *vals)
{
	t_env	*tmp;

	tmp = env;
	while (tmp && ft_strncmp(tmp->var, var, ft_strlen(tmp->var)) != 0)
		tmp = tmp->next;
	if (!tmp)
	{
		tmp = env;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_set(var, vals);
		return ;
	}
	free_mat(tmp->vals);
	if (!(ft_strncmp("PATH", var, ft_strlen("PATH"))))
		tmp->vals = ft_split(vals, ':');
	else
		tmp->vals = ft_split(vals, '\0');
}
