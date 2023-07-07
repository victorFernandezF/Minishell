/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:52:36 by fortega-          #+#    #+#             */
/*   Updated: 2023/07/07 09:55:40 by fortega-         ###   ########.fr       */
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
