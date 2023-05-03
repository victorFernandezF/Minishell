/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:02:52 by victofer          #+#    #+#             */
/*   Updated: 2023/05/03 10:24:15 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* 
 * print_test
 * ----------------------------
 *	Prints all elements of the struct cms
 *	JUST FOR TESTING.
 */

void	print_test(t_cmd *cmd, int repeat)
{
	int		i;

	i = -1;
	if (repeat == 0)
		printf("%s -- TESTING -- %s\n\n", BG, W);
	printf("%s  -- [ NODE %i ] -- %s\n", B, cmd->index, W);
	printf("%s cmd name    ➤%s %s\n", Y, W, cmd->cmd);
	printf("%s flags       ➤%s %s\n", Y, W, cmd->flags);
	printf("%s id          ➤%s %d\n", Y, W, cmd->index);
	while (cmd->params[++i] != NULL)
		printf("%s param[%i]    ➤%s %s\n", Y, i, W, cmd->params[i]);
	printf("%s nb_output   ➤%s %i\n", Y, W, cmd->nb_outputs);
	i = -1;
	while (++i < cmd->nb_outputs)
		printf("%s output[%i]   ➤%s %i\n", Y, i, W, cmd->output[i]);
	printf("%s nb_input    ➤%s %i\n", Y, W, cmd->nb_inputs);
	printf("%s input       ➤%s %i\n", Y, W, cmd->input);
	printf("\n");
	if (cmd->next != NULL)
		print_test(cmd->next, 1);
}

void	leaks(void)
{
	printf(" \n%s-- LEAKS -- %s\n\n", B, W);
	system("leaks -q minishell");
}
