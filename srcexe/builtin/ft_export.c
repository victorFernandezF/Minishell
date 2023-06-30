/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 13:39:43 by fortega-          #+#    #+#             */
/*   Updated: 2023/06/30 16:17:12 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**envtomatexp(t_env *env);

int	ft_export(t_cmd *cmd, t_env *env)
{
	char	**mat;
	int		i;

	printf("%p\n", cmd);
	i = -1;
	mat = envtomatexp(env);
	while (mat[++i])
	{
		printf("%s\n", mat[i]);
	}
	free_mat(mat);
	set_env(env, "?", "0");
	return (EXIT_SUCCESS);
}
