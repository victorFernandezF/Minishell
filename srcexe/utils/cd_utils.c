/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 21:18:19 by fortega-          #+#    #+#             */
/*   Updated: 2023/07/13 22:54:01 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	n_params(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
		i++;
	return (i);
}

int	n_flags(char *array)
{
	int		i;
	char	**tmp;

	if (!array)
		return (0);
	i = 0;
	tmp = f_split(array, ' ');
	if (!tmp)
	{
		printf("Fail allocate memory\n");
		return (-1);
	}
	while (tmp[i])
		i++;
	free_mat(tmp);
	return (i);
}

int	is_env(t_env *env, char *var)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (!(ft_strncmp(var, tmp->var, ft_strlen(var))))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
