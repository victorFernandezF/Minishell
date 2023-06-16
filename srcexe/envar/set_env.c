/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- < fortega-@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 21:01:28 by fortega-          #+#    #+#             */
/*   Updated: 2023/06/16 22:09:04 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	set_env(t_env *env, char *var, char *vals)
{
	t_env	*tmp;

	tmp = env;
	while (tmp && ft_strncmp(tmp->var, var, ft_strlen(tmp->var)) != 0)
	{
		tmp = tmp->next;
	}
	printf("Antes: %s\n%s\n", tmp->var, tmp->vals[0]);
	free_mat(tmp->vals);
	tmp->vals = ft_split(vals, '\0');
	printf("despues: %s\n%s\n", tmp->var, tmp->vals[0]);
}
