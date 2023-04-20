/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:02:52 by victofer          #+#    #+#             */
/*   Updated: 2023/04/20 13:01:26 by victofer         ###   ########.fr       */
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
	printf("%s -- TESTING -- %s\n\n", BG, W);
	printf("%s cmd       ➤%s %s\n", Y, W, cmd->cmd);
	printf("%s flg       ➤%s %s\n", Y, W, cmd->flags);
	while (cmd->params[++i] != NULL)
		printf("%s param[%i]  ➤%s %s\n", Y, i, W, cmd->params[i]);
	printf("%s nb_out    ➤%s %i\n", Y, W, cmd->nb_outputs);
	i = -1;
	while (++i < cmd->nb_outputs)
		printf("%s out[%i]    ➤%s %i\n", Y, i, W, cmd->output[i]);
	printf("\n");
}

void	leaks(void)
{
	printf(" \n%s-- LEAKS --%s\n\n", B, W);
	system("leaks -q minishell");
}
