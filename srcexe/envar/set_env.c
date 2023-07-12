/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 21:01:28 by fortega-          #+#    #+#             */
/*   Updated: 2023/07/12 19:31:03 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	set_env(t_env *env, char *var, char *vals)
{
	t_env	*tmp;

	tmp = env;
	while (tmp && ft_strncmp(tmp->var, var, ft_strlen(tmp->var)) != 0)
		tmp = tmp->next;
	free_mat(tmp->vals);
	if (!(ft_strncmp("PATH", var, ft_strlen("PATH"))))
		tmp->vals = ft_split(vals, ':');
	else
		tmp->vals = ft_split(vals, '\0');
}
