/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- < fortega-@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 20:25:25 by fortega-          #+#    #+#             */
/*   Updated: 2023/06/16 20:29:27 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	free_mat(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
		i++;
	while (i >= 0)
	{
		free(mat[i]);
		i--;
	}
	free(mat);
}