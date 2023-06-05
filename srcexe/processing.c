/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:01:44 by fortega-          #+#    #+#             */
/*   Updated: 2023/06/05 08:23:15 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	processing(t_cmd *cmd, t_env *env)
{
	int		i;
	t_env	*vari;
	t_env	*tmp;

	(void)cmd;
	vari = env;
	while (vari)
	{
		i = 0;
		printf("Variable:\n%s\n", vari->var);
		printf("Valores: \n");
		while (vari->vals[i])
		{
			printf("%i. %s\n", i, vari->vals[i]);
			i++;
		}
		tmp = vari->next;
		vari = tmp;
	}
}
