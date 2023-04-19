/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:02:52 by victofer          #+#    #+#             */
/*   Updated: 2023/04/19 09:40:17 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* 
 * print_test
 * ----------------------------
 *	Prints all elements of the struct cms
 *	JUST FOR TESTING.
 */
void	print_test(t_cmd *cmd)
{
	int	i;

	i = -1;
	printf("test cmd -> %s\n", cmd->cmd);
	printf("test flg -> %s\n", cmd->flags);
	printf("test params -> %s\n", cmd->params);
	printf("test nb_out -> %i\n", cmd->nb_outputs);
	while (++i < cmd->nb_outputs)
		printf("test out %i -> %i\n", i, cmd->output[i]);
}

void	leaks(void)
{
	system("leaks -q minishell");
}
